
# line 2 "constraint.y"
  // $Id$
// ========================================================================
//
// = LIBRARY
//    Trading
// 
// = FILENAME
//    constraint.y
//
// = AUTHOR
//    Seth Widoff <sbw1@cs.wustl.edu>
//
// ========================================================================

#include "Constraint.h"
#include "Constraint_Nodes.h"

//#define YYDEBUG 1
# define GT 257
# define GE 258
# define LT 259
# define LE 260
# define EQ 261
# define NE 262
# define EXIST 263
# define AND 264
# define OR 265
# define NOT 266
# define IN 267
# define TWIDDLE 268
# define BOOLEAN 269
# define PLUS 270
# define MINUS 271
# define MULT 272
# define DIV 273
# define UMINUS 274
# define NUMBER 275
# define RPAREN 276
# define LPAREN 277
# define IDENT 278
# define STRING 279
# define UNSIGNED_INTEGER 280
# define SIGNED_INTEGER 281
# define DOUBLE 282
# define CONSTRAINT 283
# define SEQUENCE 284
# define UNKNOWN 285
# define WITH 286
# define MAX 287
# define MIN 288
# define FIRST 289
# define RANDOM 290

#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#else
#include <malloc.h>
#include <memory.h>
#endif

#include <values.h>

#ifdef __cplusplus

#ifndef yyerror
	void yyerror(const char *);
#endif

#ifndef yylex
#ifdef __EXTERN_C__
	extern "C" { int yylex(void); }
#else
	int yylex(void);
#endif
#endif
	int yyparse(void);

#endif
#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256

# line 133 "constraint.y"


//extern int yydebug = 1;
yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
	};
# define YYNPROD 38
# define YYLAST 93
yytabelem yyact[]={

    19,    54,    44,    16,    45,    19,    24,    37,    22,    38,
    39,    24,    21,    22,    18,    20,    23,    21,    25,    18,
    20,    23,    36,     7,     6,     5,     8,     9,    19,    60,
    26,    16,    40,    41,    24,    25,    22,    38,    39,    15,
    21,    11,    18,    20,    23,    32,    33,    34,    35,    30,
    31,    14,    10,    17,    13,    12,     4,     3,     1,     2,
     0,     0,     0,     0,     0,    27,    28,    29,     0,     0,
    42,     0,    48,    49,    50,    51,    52,    53,    43,    47,
    58,    59,    46,     0,     0,     0,     0,     0,     0,     0,
    56,    57,    55 };
yytabelem yypact[]={

  -263,-10000000,  -230,-10000000,  -234,  -235,  -235,  -235,-10000000,-10000000,
-10000000,  -212,  -245,  -261,  -240,-10000000,  -258,-10000000,  -235,  -276,
-10000000,-10000000,  -271,-10000000,-10000000,  -235,  -235,  -230,  -230,  -230,
  -235,  -235,  -235,  -235,  -235,  -235,  -277,  -235,  -235,  -235,
  -235,  -235,-10000000,  -247,-10000000,-10000000,  -234,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,  -233,  -240,  -240,-10000000,-10000000,
-10000000 };
yytabelem yypgo[]={

     0,    58,    57,    59,    56,    52,    41,    55,    54,    51,
    39,    53 };
yytabelem yyr1[]={

     0,     1,     1,     2,     2,     2,     2,     2,     3,     3,
     4,     4,     5,     5,     5,     5,     5,     5,     5,     6,
     6,     7,     7,     8,     8,     8,     9,     9,     9,    10,
    10,    11,    11,    11,    11,    11,    11,    11 };
yytabelem yyr2[]={

     0,     3,     3,     5,     5,     5,     3,     3,     7,     3,
     7,     3,     7,     7,     7,     7,     7,     7,     3,     7,
     3,     7,     3,     7,     7,     3,     7,     7,     3,     5,
     3,     7,     5,     3,     3,     5,     3,     3 };
yytabelem yychk[]={

-10000000,    -1,    -3,    -2,    -4,   288,   287,   286,   289,   290,
    -5,    -6,    -7,    -8,    -9,   -10,   266,   -11,   277,   263,
   278,   275,   271,   279,   269,   265,   264,    -3,    -3,    -3,
   261,   262,   257,   258,   259,   260,   267,   268,   270,   271,
   272,   273,   -11,    -3,   278,   275,    -4,    -5,    -6,    -6,
    -6,    -6,    -6,    -6,   278,    -8,    -9,    -9,   -10,   -10,
   276 };
yytabelem yydef[]={

     0,    -2,     1,     2,     9,     0,     0,     0,     6,     7,
    11,    18,    20,    22,    25,    28,     0,    30,     0,     0,
    33,    34,     0,    36,    37,     0,     0,     3,     4,     5,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    29,     0,    32,    35,     8,    10,    12,    13,
    14,    15,    16,    17,    19,    21,    23,    24,    26,    27,
    31 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{ char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"GT",	257,
	"GE",	258,
	"LT",	259,
	"LE",	260,
	"EQ",	261,
	"NE",	262,
	"EXIST",	263,
	"AND",	264,
	"OR",	265,
	"NOT",	266,
	"IN",	267,
	"TWIDDLE",	268,
	"BOOLEAN",	269,
	"PLUS",	270,
	"MINUS",	271,
	"MULT",	272,
	"DIV",	273,
	"UMINUS",	274,
	"NUMBER",	275,
	"RPAREN",	276,
	"LPAREN",	277,
	"IDENT",	278,
	"STRING",	279,
	"UNSIGNED_INTEGER",	280,
	"SIGNED_INTEGER",	281,
	"DOUBLE",	282,
	"CONSTRAINT",	283,
	"SEQUENCE",	284,
	"UNKNOWN",	285,
	"WITH",	286,
	"MAX",	287,
	"MIN",	288,
	"FIRST",	289,
	"RANDOM",	290,
	"-unknown-",	-1	/* ends search */
};

char * yyreds[] =
{
	"-no such reduction-",
	"constraint : bool_or",
	"constraint : preference",
	"preference : MIN bool_or",
	"preference : MAX bool_or",
	"preference : WITH bool_or",
	"preference : FIRST",
	"preference : RANDOM",
	"bool_or : bool_or OR bool_and",
	"bool_or : bool_and",
	"bool_and : bool_and AND bool_compare",
	"bool_and : bool_compare",
	"bool_compare : expr_in EQ expr_in",
	"bool_compare : expr_in NE expr_in",
	"bool_compare : expr_in GT expr_in",
	"bool_compare : expr_in GE expr_in",
	"bool_compare : expr_in LT expr_in",
	"bool_compare : expr_in LE expr_in",
	"bool_compare : expr_in",
	"expr_in : expr_twiddle IN IDENT",
	"expr_in : expr_twiddle",
	"expr_twiddle : expr TWIDDLE expr",
	"expr_twiddle : expr",
	"expr : expr PLUS term",
	"expr : expr MINUS term",
	"expr : term",
	"term : term MULT factor_not",
	"term : term DIV factor_not",
	"term : factor_not",
	"factor_not : NOT factor",
	"factor_not : factor",
	"factor : LPAREN bool_or RPAREN",
	"factor : EXIST IDENT",
	"factor : IDENT",
	"factor : NUMBER",
	"factor : MINUS NUMBER",
	"factor : STRING",
	"factor : BOOLEAN",
};
#endif /* YYDEBUG */
# line	1 "/usr/ccs/bin/yaccpar"
/*
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

#pragma ident	"@(#)yaccpar	6.12	93/06/07 SMI"

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yynewmax * sizeof(type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither 
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/ 
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint)
/*
	hacks to please C++ and lint - goto's inside switch should never be
	executed; yypvt is set to 0 to avoid "used before set" warning.
*/
	static int __yaccpar_lint_hack__ = 0;
	switch (__yaccpar_lint_hack__)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
	yypvt = 0;
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			int yyps_index = (yy_ps - yys);
			int yypv_index = (yy_pv - yyv);
			int yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 1:
# line 38 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(CONSTRAINT, yypvt[-0].constraint_); } break;
case 2:
# line 40 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 3:
# line 44 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(MIN, yypvt[-0].constraint_); } break;
case 4:
# line 46 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(MAX, yypvt[-0].constraint_); } break;
case 5:
# line 48 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(WITH, yypvt[-0].constraint_); } break;
case 6:
# line 50 "constraint.y"
{ yyval.constraint_ = new ACE_Noop_Constraint(FIRST); } break;
case 7:
# line 52 "constraint.y"
{ yyval.constraint_ = new ACE_Noop_Constraint(RANDOM); } break;
case 8:
# line 56 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(OR, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 9:
# line 58 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 10:
# line 62 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(AND, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 11:
# line 64 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 12:
# line 68 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(EQ, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 13:
# line 70 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(NE, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 14:
# line 72 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(GT, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 15:
# line 74 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(GE, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 16:
# line 76 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(LT, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 17:
# line 78 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(LE, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 18:
# line 80 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 19:
# line 84 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(IN, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 20:
# line 86 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 21:
# line 90 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(TWIDDLE, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 22:
# line 92 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 23:
# line 96 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(PLUS, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 24:
# line 98 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(MINUS, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 25:
# line 100 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 26:
# line 104 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(MULT, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 27:
# line 106 "constraint.y"
{ yyval.constraint_ = new ACE_Binary_Constraint(DIV, yypvt[-2].constraint_, yypvt[-0].constraint_); } break;
case 28:
# line 108 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 29:
# line 112 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(NOT, yypvt[-0].constraint_); } break;
case 30:
# line 114 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 31:
# line 118 "constraint.y"
{ yyval.constraint_ = yypvt[-1].constraint_; } break;
case 32:
# line 120 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(EXIST, yypvt[-0].constraint_); } break;
case 33:
# line 122 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 34:
# line 124 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 35:
# line 126 "constraint.y"
{ yyval.constraint_ = new ACE_Unary_Constraint(UMINUS, yypvt[-0].constraint_); } break;
case 36:
# line 128 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
case 37:
# line 130 "constraint.y"
{ yyval.constraint_ = yypvt[-0].constraint_; } break;
# line	532 "/usr/ccs/bin/yaccpar"
	}
	goto yystack;		/* reset registers in driver code */
}

