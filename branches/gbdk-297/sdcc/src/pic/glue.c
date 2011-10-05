/*-------------------------------------------------------------------------

  SDCCglue.c - glues everything we have done together into one file.
                Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1998)

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!
-------------------------------------------------------------------------*/

#include "../common.h"
#include <time.h>
#include "ralloc.h"
#include "pcode.h"
#include "newalloc.h"


#ifdef _BIG_ENDIAN
  #define _ENDIAN(x)  (3-x)
#else
  #define _ENDIAN(x)  (x)
#endif

#define BYTE_IN_LONG(x,b) ((x>>(8*_ENDIAN(b)))&0xff)

extern symbol *interrupts[256];
static void printIval (symbol * sym, sym_link * type, initList * ilist, pBlock *pb);
extern int noAlloc;
extern set *publics;
extern unsigned maxInterrupts;
extern int maxRegBank;
extern symbol *mainf;
extern char *VersionString;
extern FILE *codeOutFile;
extern set *tmpfileSet;
extern set *tmpfileNameSet;
extern char *iComments1;
extern char *iComments2;
//extern void emitStaticSeg (memmap * map);

extern DEFSETFUNC (closeTmpFiles);
extern DEFSETFUNC (rmTmpFiles);

extern void AnalyzeBanking (void);
extern void copyFile (FILE * dest, FILE * src);

extern void writeUsedRegs(FILE *);

extern void initialComments (FILE * afile);
extern void printPublics (FILE * afile);

extern void printChar (FILE * ofile, char *s, int plen);


/*-----------------------------------------------------------------*/
/* aopLiteral - byte from a literal value                          */
/*-----------------------------------------------------------------*/
static int
_aopLiteral (value * val, int offset)
{
  unsigned long ul = (unsigned long) floatFromVal (val);

  return  (ul >> (8*_ENDIAN(offset)) &0xff);
}

/*-----------------------------------------------------------------*/
/* aopLiteral - string from a literal value                        */
/*-----------------------------------------------------------------*/
int pic14aopLiteral (value *val, int offset)
{
  union {
    float f;
    unsigned char c[4];
  } fl;

  /* if it is a float then it gets tricky */
  /* otherwise it is fairly simple */
  if (!IS_FLOAT(val->type)) {
    unsigned long v = (unsigned long) floatFromVal(val);

    return ( (v >> (offset * 8)) & 0xff);
  }

  /* it is type float */
  fl.f = (float) floatFromVal(val);
#ifdef _BIG_ENDIAN    
  return fl.c[3-offset];
#else
  return fl.c[offset];
#endif

}


/*-----------------------------------------------------------------*/
/* emitRegularMap - emit code for maps with no special cases       */
/*-----------------------------------------------------------------*/
static void
pic14emitRegularMap (memmap * map, bool addPublics, bool arFlag)
{
  symbol *sym;
  int i, size, bitvars = 0;;

  if (addPublics)
    fprintf (map->oFile, ";\t.area\t%s\n", map->sname);

  /* print the area name */
  for (sym = setFirstItem (map->syms); sym;
       sym = setNextItem (map->syms))
    {

      /* if extern then do nothing */
      if (IS_EXTERN (sym->etype))
	continue;

      /* if allocation required check is needed
         then check if the symbol really requires
         allocation only for local variables */
      if (arFlag && !IS_AGGREGATE (sym->type) &&
	  !(sym->_isparm && !IS_REGPARM (sym->etype)) &&
	  !sym->allocreq && sym->level)
	continue;

      /* if global variable & not static or extern
         and addPublics allowed then add it to the public set */
      if ((sym->level == 0 ||
	   (sym->_isparm && !IS_REGPARM (sym->etype))) &&
	  addPublics &&
	  !IS_STATIC (sym->etype))
	addSetHead (&publics, sym);

      /* if extern then do nothing or is a function
         then do nothing */
      if (IS_FUNC (sym->type))
	continue;
#if 0
      /* print extra debug info if required */
      if (options.debug || sym->level == 0)
	{

	  cdbSymbol (sym, cdbFile, FALSE, FALSE);

	  if (!sym->level)	/* global */
	    if (IS_STATIC (sym->etype))
	      fprintf (map->oFile, "F%s_", moduleName);		/* scope is file */
	    else
	      fprintf (map->oFile, "G_");	/* scope is global */
	  else
	    /* symbol is local */
	    fprintf (map->oFile, "L%s_", (sym->localof ? sym->localof->name : "-null-"));
	  fprintf (map->oFile, "%s_%d_%d", sym->name, sym->level, sym->block);
	}
#endif

      /* if is has an absolute address then generate
         an equate for this no need to allocate space */
      if (SPEC_ABSA (sym->etype))
	{
	  //if (options.debug || sym->level == 0)
	  //fprintf (map->oFile,"; == 0x%04x\n",SPEC_ADDR (sym->etype));

	  fprintf (map->oFile, "%s\tEQU\t0x%04x\n",
		   sym->rname,
		   SPEC_ADDR (sym->etype));
	}
      else
	{
	  /* allocate space */

	  /* If this is a bit variable, then allocate storage after 8 bits have been declared */
	  /* unlike the 8051, the pic does not have a separate bit area. So we emulate bit ram */
	  /* by grouping the bits together into groups of 8 and storing them in the normal ram. */
	  if (IS_BITVAR (sym->etype))
	    {
	      bitvars++;
	    }
	  else
	    {
	      fprintf (map->oFile, "\t%s\n", sym->rname);
	      if ((size = (unsigned int) getSize (sym->type) & 0xffff) > 1)
		{
		  for (i = 1; i < size; i++)
		    fprintf (map->oFile, "\t%s_%d\n", sym->rname, i);
		}
	    }
	  //fprintf (map->oFile, "\t.ds\t0x%04x\n", (unsigned int)getSize (sym->type) & 0xffff);
	}
	
	/* if it has a initial value then do it only if
	   it is a global variable */
	if (sym->ival && sym->level == 0) {
	    ast *ival = NULL;
	    
	    if (IS_AGGREGATE (sym->type))
		ival = initAggregates (sym, sym->ival, NULL);
	    else
		ival = newNode ('=', newAst_VALUE(symbolVal (sym)),
				decorateType (resolveSymbols (list2expr (sym->ival))));
	    codeOutFile = statsg->oFile;
	    GcurMemmap = statsg;
	    eBBlockFromiCode (iCodeFromAst (ival));
	    sym->ival = NULL;
	}
    }
}


/*-----------------------------------------------------------------*/
/* printIvalType - generates ival for int/char                     */
/*-----------------------------------------------------------------*/
static void 
printIvalType (symbol *sym, sym_link * type, initList * ilist, pBlock *pb)
{
  value *val;
  unsigned long ulval;

  //fprintf(stderr, "%s\n",__FUNCTION__);

  /* if initList is deep */
  if (ilist->type == INIT_DEEP)
    ilist = ilist->init.deep;

  if (!IS_AGGREGATE(sym->type) && getNelements(type, ilist)>1) {
    werror (W_EXCESS_INITIALIZERS, "scalar", sym->name, sym->lineDef);
  }

  if (!(val = list2val (ilist))) {
    // assuming a warning has been thrown
    val=constVal("0");
  }

  if (val->type != type) {
    val = valCastLiteral(type, floatFromVal(val));
  }

  if(val) 
    ulval = (unsigned long) floatFromVal (val);
  else
    ulval =0;

  switch (getSize (type)) {
  case 1:
    //tfprintf (oFile, "\t!dbs\n",aopLiteral (val, 0));
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,0))));
    //fprintf(stderr,"0x%02x\n",_aopLiteral(val,0));

    break;

  case 2:
    // if (port->use_dw_for_init) {
    //tfprintf (oFile, "\t!dws\n", aopLiteralLong (val, 0, 2));
    //  fprintf(stderr,"%s:%d  aopLiteralLong\n",__FILE__,__LINE__);
    //}else
    //fprintf (oFile, "\t.byte %s,%s\n", aopLiteral (val, 0), aopLiteral (val, 1));
    //fprintf(stderr,"0x%02x  0x%02x\n",_aopLiteral(val,0),_aopLiteral(val,1));
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,0))));
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,1))));
    break;
  case 4:
    /*
    if (!val) {
      tfprintf (oFile, "\t!dw !constword\n", 0);
      tfprintf (oFile, "\t!dw !constword\n", 0);
    }
    else {
      fprintf (oFile, "\t.byte %s,%s,%s,%s\n",
	       aopLiteral (val, 0), aopLiteral (val, 1),
	       aopLiteral (val, 2), aopLiteral (val, 3));
      fprintf(stderr,"0x%02x  0x%02x 0x%02x  0x%02x\n",
	      _aopLiteral(val,0),_aopLiteral(val,1),
	      _aopLiteral(val,2),_aopLiteral(val,3));
    }
    */
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,0))));
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,1))));
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,2))));
    addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(BYTE_IN_LONG(ulval,3))));
    break;
  }
#if 0
  {
    int size = getSize(type);

    fprintf(stderr," size=%d, val =",size);
    if(val)
      fprintf(stderr,"0x%02x\n",_aopLiteral(val,0));
    else
      fprintf(stderr,"none\n");
  }
#endif
}

/*-----------------------------------------------------------------*/
/* printIvalChar - generates initital value for character array    */
/*-----------------------------------------------------------------*/
static int 
printIvalChar (sym_link * type, initList * ilist, pBlock *pb, char *s)
{
  value *val;
  int remain;

  if(!pb)
    return 0;

  //fprintf(stderr, "%s\n",__FUNCTION__);
  if (!s)
    {

      val = list2val (ilist);
      /* if the value is a character string  */
      if (IS_ARRAY (val->type) && IS_CHAR (val->etype))
	{
	  if (!DCL_ELEM (type))
	    DCL_ELEM (type) = strlen (SPEC_CVAL (val->etype).v_char) + 1;

	  //printChar (oFile, SPEC_CVAL (val->etype).v_char, DCL_ELEM (type));
	  //fprintf(stderr, "%s omitting call to printChar\n",__FUNCTION__);
	  addpCode2pBlock(pb,newpCodeCharP(";omitting call to printChar"));

	  if ((remain = (DCL_ELEM (type) - strlen (SPEC_CVAL (val->etype).v_char) - 1)) > 0)
	    while (remain--)
	      //tfprintf (oFile, "\t!db !constbyte\n", 0);
	      addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(0)));
	  return 1;
	}
      else
	return 0;
    }
  else {
    //printChar (oFile, s, strlen (s) + 1);

    for(remain=0; remain<strlen(s); remain++) {
      addpCode2pBlock(pb,newpCode(POC_RETLW,newpCodeOpLit(s[remain])));
      //fprintf(stderr,"0x%02x ",s[remain]);
    }
    //fprintf(stderr,"\n");
  }
  return 1;
}

/*-----------------------------------------------------------------*/
/* printIvalArray - generates code for array initialization        */
/*-----------------------------------------------------------------*/
static void 
printIvalArray (symbol * sym, sym_link * type, initList * ilist,
		pBlock *pb)
{
  initList *iloop;
  int lcnt = 0, size = 0;

  if(!pb)
    return;

  /* take care of the special   case  */
  /* array of characters can be init  */
  /* by a string                      */
  if (IS_CHAR (type->next)) {
    //fprintf(stderr,"%s:%d - is_char\n",__FUNCTION__,__LINE__);
    if (!IS_LITERAL(list2val(ilist)->etype)) {
      werror (W_INIT_WRONG);
      return;
    }
    if (printIvalChar (type,
		       (ilist->type == INIT_DEEP ? ilist->init.deep : ilist),
		       pb, SPEC_CVAL (sym->etype).v_char))
      return;
  }
  /* not the special case             */
  if (ilist->type != INIT_DEEP)
    {
      werror (E_INIT_STRUCT, sym->name);
      return;
    }

  iloop = ilist->init.deep;
  lcnt = DCL_ELEM (type);

  for (;;)
    {
      //fprintf(stderr,"%s:%d - is_char\n",__FUNCTION__,__LINE__);
      size++;
      printIval (sym, type->next, iloop, pb);
      iloop = (iloop ? iloop->next : NULL);


      /* if not array limits given & we */
      /* are out of initialisers then   */
      if (!DCL_ELEM (type) && !iloop)
	break;

      /* no of elements given and we    */
      /* have generated for all of them */
      if (!--lcnt) {
	/* if initializers left */
	if (iloop) {
	  werror (W_EXCESS_INITIALIZERS, "array", sym->name, sym->lineDef);
	}
	break;
      }
    }

  /* if we have not been given a size  */
  if (!DCL_ELEM (type))
    DCL_ELEM (type) = size;

  return;
}

/*-----------------------------------------------------------------*/
/* printIval - generates code for initial value                    */
/*-----------------------------------------------------------------*/
static void 
printIval (symbol * sym, sym_link * type, initList * ilist, pBlock *pb)
{
  if (!ilist || !pb)
    return;

  /* if structure then    */
  if (IS_STRUCT (type))
    {
      //fprintf(stderr,"%s struct\n",__FUNCTION__);
      //printIvalStruct (sym, type, ilist, oFile);
      return;
    }

  /* if this is a pointer */
  if (IS_PTR (type))
    {
      //fprintf(stderr,"%s pointer\n",__FUNCTION__);
      //printIvalPtr (sym, type, ilist, oFile);
      return;
    }

  /* if this is an array   */
  if (IS_ARRAY (type))
    {
      //fprintf(stderr,"%s array\n",__FUNCTION__);
      printIvalArray (sym, type, ilist, pb);
      return;
    }

  /* if type is SPECIFIER */
  if (IS_SPEC (type))
    {
      //fprintf(stderr,"%s spec\n",__FUNCTION__);
      printIvalType (sym, type, ilist, pb);
      return;
    }
}

extern void pCodeConstString(char *name, char *value);
/*-----------------------------------------------------------------*/
/* emitStaticSeg - emitcode for the static segment                 */
/*-----------------------------------------------------------------*/
static void
pic14emitStaticSeg (memmap * map)
{
  symbol *sym;

  fprintf (map->oFile, ";\t.area\t%s\n", map->sname);

  //fprintf(stderr, "%s\n",__FUNCTION__);

  /* for all variables in this segment do */
  for (sym = setFirstItem (map->syms); sym;
       sym = setNextItem (map->syms))
    {
      /* if it is "extern" then do nothing */
      if (IS_EXTERN (sym->etype))
	continue;

      /* if it is not static add it to the public
         table */
      if (!IS_STATIC (sym->etype))
	addSetHead (&publics, sym);

      /* print extra debug info if required */
      if (options.debug || sym->level == 0)
	{
	  /* NOTE to me - cdbFile may be null in which case,
	   * the sym name will be printed to stdout. oh well */
	  if(cdbFile)
	    cdbSymbol (sym, cdbFile, FALSE, FALSE);

	  if (!sym->level)
	    {			/* global */
	      if (IS_STATIC (sym->etype))
		fprintf (code->oFile, "F%s_", moduleName);	/* scope is file */
	      else
		fprintf (code->oFile, "G_");	/* scope is global */
	    }
	  else
	    /* symbol is local */
	    fprintf (code->oFile, "L%s_",
		     (sym->localof ? sym->localof->name : "-null-"));
	  fprintf (code->oFile, "%s_%d_%d", sym->name, sym->level, sym->block);

	}

      /* if it has an absolute address */
      if (SPEC_ABSA (sym->etype))
	{
	  if (options.debug || sym->level == 0)
	    fprintf (code->oFile, " == 0x%04x\n", SPEC_ADDR (sym->etype));

	  fprintf (code->oFile, "%s\t=\t0x%04x\n",
		   sym->rname,
		   SPEC_ADDR (sym->etype));
	}
      else
	{
	  if (options.debug || sym->level == 0)
	    fprintf (code->oFile, " == .\n");

	  /* if it has an initial value */
	  if (sym->ival)
	    {
	      pBlock *pb;

	      fprintf (code->oFile, "%s:\n", sym->rname);
	      noAlloc++;
	      resolveIvalSym (sym->ival);
	      //printIval (sym, sym->type, sym->ival, code->oFile);
	      pb = newpCodeChain(NULL, 'P',newpCodeCharP("; Starting pCode block for Ival"));
	      addpBlock(pb);
	      addpCode2pBlock(pb,newpCodeLabel(sym->rname,-1));

	      printIval (sym, sym->type, sym->ival, pb);
	      noAlloc--;
	    }
	  else
	    {

	      /* allocate space */
	      fprintf (code->oFile, "%s:\n", sym->rname);
	      /* special case for character strings */
	      if (IS_ARRAY (sym->type) && IS_CHAR (sym->type->next) &&
		  SPEC_CVAL (sym->etype).v_char)
		pCodeConstString(sym->rname , SPEC_CVAL (sym->etype).v_char);
		/*printChar (code->oFile,
			   SPEC_CVAL (sym->etype).v_char,
			   strlen (SPEC_CVAL (sym->etype).v_char) + 1);*/
	      else
		fprintf (code->oFile, "\t.ds\t0x%04x\n", (unsigned int) getSize (sym->type) & 0xffff);
	    }
	}
    }

}


/*-----------------------------------------------------------------*/
/* emitMaps - emits the code for the data portion the code         */
/*-----------------------------------------------------------------*/
static void
pic14emitMaps ()
{
  /* no special considerations for the following
     data, idata & bit & xdata */
  pic14emitRegularMap (data, TRUE, TRUE);
  pic14emitRegularMap (idata, TRUE, TRUE);
  pic14emitRegularMap (bit, TRUE, FALSE);
  pic14emitRegularMap (xdata, TRUE, TRUE);
  pic14emitRegularMap (sfr, FALSE, FALSE);
  pic14emitRegularMap (sfrbit, FALSE, FALSE);
  pic14emitRegularMap (code, TRUE, FALSE);
  pic14emitStaticSeg (statsg);
}

/*-----------------------------------------------------------------*/
/* createInterruptVect - creates the interrupt vector              */
/*-----------------------------------------------------------------*/
static void
pic14createInterruptVect (FILE * vFile)
{
  unsigned i = 0;
  mainf = newSymbol ("main", 0);
  mainf->block = 0;

  /* only if the main function exists */
  if (!(mainf = findSymWithLevel (SymbolTab, mainf)))
    {
      if (!options.cc_only)
	werror (E_NO_MAIN);
      return;
    }

  /* if the main is only a prototype ie. no body then do nothing */
  if (!IFFUNC_HASBODY(mainf->type))
    {
      /* if ! compile only then main function should be present */
      if (!options.cc_only)
	werror (E_NO_MAIN);
      return;
    }

  fprintf (vFile, ";\t.area\t%s\n", CODE_NAME);
  fprintf (vFile, ";__interrupt_vect:\n");


  if (!port->genIVT || !(port->genIVT (vFile, interrupts, maxInterrupts)))
    {
      /* "generic" interrupt table header (if port doesn't specify one).

       * Look suspiciously like 8051 code to me...
       */

      fprintf (vFile, ";\tljmp\t__sdcc_gsinit_startup\n");


      /* now for the other interrupts */
      for (; i < maxInterrupts; i++)
	{
	  if (interrupts[i])
	    fprintf (vFile, ";\tljmp\t%s\n;\t.ds\t5\n", interrupts[i]->rname);
	  else
	    fprintf (vFile, ";\treti\n;\t.ds\t7\n");
	}
    }
}


/*-----------------------------------------------------------------*/
/* initialComments - puts in some initial comments                 */
/*-----------------------------------------------------------------*/
static void
pic14initialComments (FILE * afile)
{
  initialComments (afile);
  fprintf (afile, "; PIC port for the 14-bit core\n");
  fprintf (afile, iComments2);

}

/*-----------------------------------------------------------------*/
/* printPublics - generates .global for publics                    */
/*-----------------------------------------------------------------*/
static void
pic14printPublics (FILE * afile)
{
  symbol *sym;

  fprintf (afile, "%s", iComments2);
  fprintf (afile, "; publics variables in this module\n");
  fprintf (afile, "%s", iComments2);

  for (sym = setFirstItem (publics); sym;
       sym = setNextItem (publics))
    fprintf (afile, ";\t.globl %s\n", sym->rname);
}



/*-----------------------------------------------------------------*/
/* emitOverlay - will emit code for the overlay stuff              */
/*-----------------------------------------------------------------*/
static void
pic14emitOverlay (FILE * afile)
{
  set *ovrset;

  if (!elementsInSet (ovrSetSets))
    fprintf (afile, ";\t.area\t%s\n", port->mem.overlay_name);

  /* for each of the sets in the overlay segment do */
  for (ovrset = setFirstItem (ovrSetSets); ovrset;
       ovrset = setNextItem (ovrSetSets))
    {

      symbol *sym;

      if (elementsInSet (ovrset))
	{
	  /* this dummy area is used to fool the assembler
	     otherwise the assembler will append each of these
	     declarations into one chunk and will not overlay
	     sad but true */
	  fprintf (afile, ";\t.area _DUMMY\n");
	  /* output the area informtion */
	  fprintf (afile, ";\t.area\t%s\n", port->mem.overlay_name);	/* MOF */
	}

      for (sym = setFirstItem (ovrset); sym;
	   sym = setNextItem (ovrset))
	{

	  /* if extern then do nothing */
	  if (IS_EXTERN (sym->etype))
	    continue;

	  /* if allocation required check is needed
	     then check if the symbol really requires
	     allocation only for local variables */
	  if (!IS_AGGREGATE (sym->type) &&
	      !(sym->_isparm && !IS_REGPARM (sym->etype))
	      && !sym->allocreq && sym->level)
	    continue;

	  /* if global variable & not static or extern
	     and addPublics allowed then add it to the public set */
	  if ((sym->_isparm && !IS_REGPARM (sym->etype))
	      && !IS_STATIC (sym->etype))
	    addSetHead (&publics, sym);

	  /* if extern then do nothing or is a function
	     then do nothing */
	  if (IS_FUNC (sym->type))
	    continue;

	  /* print extra debug info if required */
	  if (options.debug || sym->level == 0)
	    {

	      cdbSymbol (sym, cdbFile, FALSE, FALSE);

	      if (!sym->level)
		{		/* global */
		  if (IS_STATIC (sym->etype))
		    fprintf (afile, "F%s_", moduleName);	/* scope is file */
		  else
		    fprintf (afile, "G_");	/* scope is global */
		}
	      else
		/* symbol is local */
		fprintf (afile, "L%s_",
			 (sym->localof ? sym->localof->name : "-null-"));
	      fprintf (afile, "%s_%d_%d", sym->name, sym->level, sym->block);
	    }

	  /* if is has an absolute address then generate
	     an equate for this no need to allocate space */
	  if (SPEC_ABSA (sym->etype))
	    {

	      if (options.debug || sym->level == 0)
		fprintf (afile, " == 0x%04x\n", SPEC_ADDR (sym->etype));

	      fprintf (afile, "%s\t=\t0x%04x\n",
		       sym->rname,
		       SPEC_ADDR (sym->etype));
	    }
	  else
	    {
	      if (options.debug || sym->level == 0)
		fprintf (afile, "==.\n");

	      /* allocate space */
	      fprintf (afile, "%s:\n", sym->rname);
	      fprintf (afile, "\t.ds\t0x%04x\n", (unsigned int) getSize (sym->type) & 0xffff);
	    }

	}
    }
}


/*-----------------------------------------------------------------*/
/* glue - the final glue that hold the whole thing together        */
/*-----------------------------------------------------------------*/
void
picglue ()
{

  FILE *vFile;
  FILE *asmFile;
  FILE *ovrFile = tempfile();
  //  int i;
#if 0
  set *s=NULL,*t=NULL;
  char a=1,b=2,c=3;


  addSet(&s,&a);
  addSet(&s,&b);
  addSet(&s,&c);

  DFPRINTF((stderr,"\n\n\n******************\n\n\n"));
  for(t=s; t; t=t->next) {
    if(t->item) 
      DFPRINTF((stderr,"Set item %d\n",*(char *)t->item));
  }

  s =reverseSet(s);
  for(t=s; t; t=t->next) {
    if(t->item) 
      DFPRINTF((stderr,"Set item %d\n",*(char *)t->item));
  }
#endif

  addSetHead(&tmpfileSet,ovrFile);


  if (mainf && IFFUNC_HASBODY(mainf->type)) {

    pBlock *pb = newpCodeChain(NULL,'X',newpCodeCharP("; Starting pCode block"));
    addpBlock(pb);

    /* entry point @ start of CSEG */
    addpCode2pBlock(pb,newpCodeLabel("__sdcc_program_startup",-1));
    /* put in the call to main */
    addpCode2pBlock(pb,newpCode(POC_CALL,newpCodeOp("_main",PO_STR)));

    if (options.mainreturn) {

      addpCode2pBlock(pb,newpCodeCharP(";\treturn from main will return to caller\n"));
      addpCode2pBlock(pb,newpCode(POC_RETURN,NULL));

    } else {

      addpCode2pBlock(pb,newpCodeCharP(";\treturn from main will lock up\n"));
      addpCode2pBlock(pb,newpCode(POC_GOTO,newpCodeOp("$",PO_STR)));

    }
  }


  /* At this point we've got all the code in the form of pCode structures */
  /* Now it needs to be rearranged into the order it should be placed in the */
  /* code space */

  movepBlock2Head('P');              // Last
  movepBlock2Head(code->dbName);
  movepBlock2Head('X');
  movepBlock2Head(statsg->dbName);   // First


  /* print the global struct definitions */
  if (options.debug)
    cdbStructBlock (0,cdbFile);

  vFile = tempfile();
  /* PENDING: this isnt the best place but it will do */
  if (port->general.glue_up_main) {
    /* create the interrupt vector table */
    pic14createInterruptVect (vFile);
  }

  addSetHead(&tmpfileSet,vFile);
    
  /* emit code for the all the variables declared */
  pic14emitMaps ();
  /* do the overlay segments */
  pic14emitOverlay(ovrFile);


  AnalyzepCode('*'); //code->dbName);

  //#ifdef PCODE_DEBUG
  //  printCallTree(stderr);
  //#endif

  pcode_test();


  /* now put it all together into the assembler file */
  /* create the assembler file name */
    
  if (!options.c1mode) {
    sprintf (buffer, srcFileName);
    strcat (buffer, ".asm");
  }
  else {
    strcpy(buffer, options.out_name);
  }

  if (!(asmFile = fopen (buffer, "w"))) {
    werror (E_FILE_OPEN_ERR, buffer);
    exit (1);
  }
    
  /* initial comments */
  pic14initialComments (asmFile);
    
  /* print module name */
  fprintf (asmFile, ";\t.module %s\n", moduleName);
    
  /* Let the port generate any global directives, etc. */
  if (port->genAssemblerPreamble)
    {
      port->genAssemblerPreamble(asmFile);
    }
    
  /* print the global variables in this module */
  pic14printPublics (asmFile);
    

  /* copy the sfr segment */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; special function registers\n");
  fprintf (asmFile, "%s", iComments2);
  copyFile (asmFile, sfr->oFile);
    

  /* Put all variables into a cblock */
  writeUsedRegs(asmFile);
  AnalyzeBanking();

  /* create the overlay segments */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; overlayable items in internal ram \n");
  fprintf (asmFile, "%s", iComments2);    
  copyFile (asmFile, ovrFile);

  /* create the stack segment MOF */
  if (mainf && IFFUNC_HASBODY(mainf->type)) {
    fprintf (asmFile, "%s", iComments2);
    fprintf (asmFile, "; Stack segment in internal ram \n");
    fprintf (asmFile, "%s", iComments2);    
    fprintf (asmFile, ";\t.area\tSSEG\t(DATA)\n"
	     ";__start__stack:\n;\t.ds\t1\n\n");
  }

  /* create the idata segment */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; indirectly addressable internal ram data\n");
  fprintf (asmFile, "%s", iComments2);
  copyFile (asmFile, idata->oFile);
    
  /* if external stack then reserve space of it */
  if (mainf && IFFUNC_HASBODY(mainf->type) && options.useXstack ) {
    fprintf (asmFile, "%s", iComments2);
    fprintf (asmFile, "; external stack \n");
    fprintf (asmFile, "%s", iComments2);
    fprintf (asmFile,";\t.area XSEG (XDATA)\n"); /* MOF */
    fprintf (asmFile,";\t.ds 256\n");
  }
	
	
  /* copy xtern ram data */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; external ram data\n");
  fprintf (asmFile, "%s", iComments2);
  copyFile (asmFile, xdata->oFile);
    

  /* copy the bit segment */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; bit data\n");
  fprintf (asmFile, "%s", iComments2);
  copyFile (asmFile, bit->oFile);


  fprintf (asmFile, "\tORG 0\n");

  /* copy the interrupt vector table */
  if (mainf && IFFUNC_HASBODY(mainf->type)) {
    fprintf (asmFile, "%s", iComments2);
    fprintf (asmFile, "; interrupt vector \n");
    fprintf (asmFile, "%s", iComments2);
    copyFile (asmFile, vFile);
  }
    
  /* copy global & static initialisations */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; global & static initialisations\n");
  fprintf (asmFile, "%s", iComments2);
    
  /* Everywhere we generate a reference to the static_name area, 
   * (which is currently only here), we immediately follow it with a 
   * definition of the post_static_name area. This guarantees that
   * the post_static_name area will immediately follow the static_name
   * area.
   */
  fprintf (asmFile, ";\t.area %s\n", port->mem.static_name); /* MOF */
  fprintf (asmFile, ";\t.area %s\n", port->mem.post_static_name);
  fprintf (asmFile, ";\t.area %s\n", port->mem.static_name);
    
  if (mainf && IFFUNC_HASBODY(mainf->type)) {
    fprintf (asmFile,"__sdcc_gsinit_startup:\n");
    /* if external stack is specified then the
       higher order byte of the xdatalocation is
       going into P2 and the lower order going into
       spx */
    if (options.useXstack) {
      fprintf(asmFile,";\tmov\tP2,#0x%02x\n",
	      (((unsigned int)options.xdata_loc) >> 8) & 0xff);
      fprintf(asmFile,";\tmov\t_spx,#0x%02x\n",
	      (unsigned int)options.xdata_loc & 0xff);
    }

  }

  if (port->general.glue_up_main && mainf && IFFUNC_HASBODY(mainf->type))
    {
      /* This code is generated in the post-static area.
       * This area is guaranteed to follow the static area
       * by the ugly shucking and jiving about 20 lines ago.
       */
      fprintf(asmFile, ";\t.area %s\n", port->mem.post_static_name);
      fprintf (asmFile,";\tljmp\t__sdcc_program_startup\n");
    }
	
  /* copy over code */
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, "; code\n");
  fprintf (asmFile, "%s", iComments2);
  fprintf (asmFile, ";\t.area %s\n", port->mem.code_name);

  //copyFile (stderr, code->oFile);

  copypCode(asmFile, 'I');
  copypCode(asmFile, statsg->dbName);
  copypCode(asmFile, 'X');
  copypCode(asmFile, 'M');
  copypCode(asmFile, code->dbName);
  copypCode(asmFile, 'P');


  fprintf (asmFile,"\tend\n");

  fclose (asmFile);
  applyToSet(tmpfileSet,closeTmpFiles);
  applyToSet(tmpfileNameSet, rmTmpFiles);
}