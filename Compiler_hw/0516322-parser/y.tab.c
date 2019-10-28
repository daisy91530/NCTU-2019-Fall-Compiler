#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include<stdio.h>
#include<stdlib.h>

extern FILE *yyin; 
int error=0;

void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
	fprintf(stderr, "Line %d: error token ident\n", line_no);
	error=1;
  	exit(-1);
 }

#line 34 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define PROGRAM 257
#define IDENTIFIER 258
#define LPAREN 259
#define RPAREN 260
#define SEMICOLON 261
#define DOT 262
#define COMMA 263
#define VAR 264
#define COLON 265
#define ARRAY 266
#define RBRAC 267
#define LBRAC 268
#define NUM 269
#define STRINGCONSTANT 270
#define OF 271
#define INTEGER 272
#define REAL 273
#define FUNCTION 274
#define PROCEDURE 275
#define PBEGIN 276
#define END 277
#define ASSIGNMENT 278
#define IF 279
#define THEN 280
#define ELSE 281
#define WHILE 282
#define DO 283
#define GE 284
#define GT 285
#define LE 286
#define LT 287
#define EQUAL 288
#define MINUS 289
#define notEQUAL 290
#define PLUS 291
#define SLASH 292
#define STAR 293
#define NOT 294
#define DOTDOT 295
#define AND 296
#define OR 297
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    5,    5,    6,    6,    6,
    3,    3,    8,    9,    9,   10,   10,   11,   11,   12,
   12,    4,   13,   14,   14,   15,   15,   15,   15,   15,
   15,   16,   19,   19,   18,   18,   20,   20,   17,   17,
   17,   21,   21,   22,   22,   24,   24,   26,   26,   26,
   26,   26,   26,   25,   25,   27,   27,   23,   23,   23,
   23,   23,   23,    7,    7,
};
static const short yylen[] = {                            2,
   10,    1,    3,    6,    0,    1,    8,    1,    1,    1,
    3,    0,    4,    6,    4,    3,    0,    4,    6,    1,
    0,    3,    1,    1,    3,    3,    1,    1,    6,    4,
    0,    2,    4,    0,    1,    4,    1,    3,    1,    3,
    3,    1,    3,    1,    3,    1,    3,    2,    4,    1,
    1,    3,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    2,    0,    0,    0,    5,    3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    0,    0,    0,    0,    0,    0,   28,    0,    0,   24,
    0,   27,    1,   11,    0,    0,   10,    8,    9,    0,
    6,    0,    0,    0,    0,    0,   32,    0,    0,   64,
   51,   55,   54,    0,   50,    0,    0,    0,    0,    0,
   46,    0,   22,    0,    0,    0,    0,    4,   20,    0,
    0,    0,   15,   37,    0,    0,    0,   48,    0,   53,
    0,    0,    0,   62,   59,   61,   58,   60,   63,    0,
    0,   57,   56,    0,   65,    0,   25,   26,   13,    0,
   16,    0,    0,   36,    0,    0,    0,   52,    0,   40,
   41,    0,    0,   47,   30,    0,    0,   14,   38,   33,
   49,    0,    0,    0,   29,    0,    0,    0,   19,    7,
};
static const short yydgoto[] = {                          2,
    6,   11,   13,   27,   40,   41,   55,   19,   20,   43,
   70,   71,   28,   29,   30,   31,   74,   32,   47,   75,
   57,   58,   90,   59,   60,   61,   94,
};
static const short yysindex[] = {                      -244,
 -235,    0, -228, -215,    0, -225, -141, -192,    0,    0,
 -165, -215, -257, -195, -137, -134, -243, -126, -124,    0,
 -162, -114, -114, -248, -217, -217,    0, -131, -102,    0,
 -116,    0,    0,    0, -165,  -94,    0,    0,    0,  -83,
    0,  -84,  -82,  -80, -217, -217,    0, -199, -217,    0,
    0,    0,    0, -217,    0,  -98, -218, -136, -186,  -85,
    0,  -97,    0, -243, -217, -257, -242,    0,    0,  -75,
 -215, -197,    0,    0, -205,  -79, -217,    0,  -73,    0,
 -243, -217, -217,    0,    0,    0,    0,    0,    0, -217,
 -217,    0,    0, -217,    0, -243,    0,    0,    0, -105,
    0, -121,  -70,    0, -217,  -74, -177,    0,  -71,    0,
    0, -133, -186,    0,    0, -242, -162,    0,    0,    0,
    0, -243,  -61,  -47,    0,  -54,  -84, -162,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -159,    0,    0,    0,    0,    0, -233,    0,    0,    0,
    0,  -49,  -43, -227,    0,    0,    0,    0,  -57,    0,
    0,    0,    0,    0, -159,    0,    0,    0,    0,    0,
    0,  -36,    0,    0,    0,    0,    0, -158,    0,    0,
    0,    0,    0,    0,    0,    0,  -48, -251, -120,    0,
    0,    0,    0, -233,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -163,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -196,    0,    0,    0,    0,
    0,  -56,  -88,    0,    0,    0,    0,    0,    0,    0,
    0, -163,    0,  -34,    0,    0,  -36,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  -10,  208,  195,   -7, -103,  159,  -60,    0,    0,  211,
  109,    0,    0,    0,  -59,    0,  -25,    0,  -44,  160,
   30,  148,    0,  151,  -55,  -46,    0,
};
#define YYTABLESIZE 242
static const short yytable[] = {                         56,
   62,   14,   91,   78,   97,   18,  100,   80,   42,   42,
   45,   42,    1,  124,   24,   42,   15,   16,   17,   46,
   76,  109,    3,   79,  130,   42,   50,   31,   42,   42,
    4,   42,   17,   35,    7,   25,  115,    8,   26,   98,
   48,   49,    5,   31,   42,   42,   52,  114,   53,   35,
   34,   50,   51,   35,  104,  123,   91,  105,   99,   77,
  102,  120,  125,   34,   34,   10,   34,    8,   46,   21,
   34,   52,   37,   53,   38,   39,   54,   82,   83,  119,
   34,   34,  121,   34,   34,  105,   34,   34,   34,   34,
   34,   34,   34,   34,   34,   34,   34,   31,   12,   34,
   34,   34,   34,   36,   34,   92,   93,   37,   34,   38,
   39,  110,  111,   31,   12,   12,   12,   31,   34,    9,
   22,   34,   34,   23,   34,   34,   34,   34,   34,   34,
   34,   34,   34,   34,   34,   33,   34,   34,   34,   44,
   44,    8,   44,  117,   42,   63,   44,   84,   85,   86,
   87,   88,   52,   89,   53,   52,   44,   53,   64,   44,
   44,   65,   44,   44,   44,   44,   44,   44,   44,   44,
   44,   45,   45,   67,   45,   44,   44,   68,   45,   69,
   73,   81,   72,   95,  101,   96,  108,  106,   45,  116,
  118,   45,   45,   46,   45,   45,   45,   45,   45,   45,
   45,   45,   45,   43,   43,  126,   43,   45,   45,  122,
   43,   39,   39,  127,   39,   17,  128,   17,   39,   23,
   43,   21,   31,   43,   43,   18,   43,   35,   39,   66,
  103,   39,   39,   44,   39,  129,  107,  112,    0,   43,
   43,  113,
};
static const short yycheck[] = {                         25,
   26,   12,   58,   48,   64,   13,   67,   54,  260,  261,
  259,  263,  257,  117,  258,  267,  274,  275,  276,  268,
   46,   81,  258,   49,  128,  277,  269,  261,  280,  281,
  259,  283,  276,  261,  260,  279,   96,  263,  282,   65,
  258,  259,  258,  277,  296,  297,  289,   94,  291,  277,
  278,  269,  270,  281,  260,  116,  112,  263,   66,  259,
   71,  106,  122,  260,  261,  258,  263,  263,  268,  265,
  267,  289,  270,  291,  272,  273,  294,  296,  297,  105,
  277,  278,  260,  280,  281,  263,  283,  284,  285,  286,
  287,  288,  289,  290,  291,  292,  293,  261,  264,  296,
  297,  260,  261,  266,  263,  292,  293,  270,  267,  272,
  273,   82,   83,  277,  274,  275,  276,  281,  277,  261,
  258,  280,  281,  258,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  262,  261,  296,  297,  260,
  261,  263,  263,  265,  259,  277,  267,  284,  285,  286,
  287,  288,  289,  290,  291,  289,  277,  291,  261,  280,
  281,  278,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  260,  261,  268,  263,  296,  297,  261,  267,  264,
  261,  280,  265,  269,  260,  283,  260,  267,  277,  295,
  261,  280,  281,  268,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  260,  261,  267,  263,  296,  297,  281,
  267,  260,  261,  261,  263,  265,  271,  261,  267,  277,
  277,  258,  281,  280,  281,  260,  283,   20,  277,   35,
   72,  280,  281,   23,  283,  127,   77,   90,   -1,  296,
  297,   91,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PROGRAM","IDENTIFIER","LPAREN",
"RPAREN","SEMICOLON","DOT","COMMA","VAR","COLON","ARRAY","RBRAC","LBRAC","NUM",
"STRINGCONSTANT","OF","INTEGER","REAL","FUNCTION","PROCEDURE","PBEGIN","END",
"ASSIGNMENT","IF","THEN","ELSE","WHILE","DO","GE","GT","LE","LT","EQUAL",
"MINUS","notEQUAL","PLUS","SLASH","STAR","NOT","DOTDOT","AND","OR",
};
static const char *yyrule[] = {
"$accept : prog",
"prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list COMMA IDENTIFIER",
"declarations : declarations VAR identifier_list COLON type SEMICOLON",
"declarations :",
"type : standard_type",
"type : ARRAY LBRAC number DOTDOT number RBRAC OF type",
"standard_type : INTEGER",
"standard_type : REAL",
"standard_type : STRINGCONSTANT",
"subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON",
"subprogram_declarations :",
"subprogram_declaration : subprogram_head declarations subprogram_declarations compound_statement",
"subprogram_head : FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON",
"subprogram_head : PROCEDURE IDENTIFIER arguments SEMICOLON",
"arguments : LPAREN parameter_list RPAREN",
"arguments :",
"parameter_list : optional_var identifier_list COLON type",
"parameter_list : optional_var identifier_list COLON type SEMICOLON parameter_list",
"optional_var : VAR",
"optional_var :",
"compound_statement : PBEGIN optional_statements END",
"optional_statements : statement_list",
"statement_list : statement",
"statement_list : statement_list SEMICOLON statement",
"statement : variable ASSIGNMENT expression",
"statement : procedure_statement",
"statement : compound_statement",
"statement : IF expression THEN statement ELSE statement",
"statement : WHILE expression DO statement",
"statement :",
"variable : IDENTIFIER tail",
"tail : LBRAC expression RBRAC tail",
"tail :",
"procedure_statement : IDENTIFIER",
"procedure_statement : IDENTIFIER LPAREN expression_list RPAREN",
"expression_list : expression",
"expression_list : expression_list COMMA expression",
"expression : boolexpression",
"expression : boolexpression AND boolexpression",
"expression : boolexpression OR boolexpression",
"boolexpression : simple_expression",
"boolexpression : simple_expression relop simple_expression",
"simple_expression : term",
"simple_expression : simple_expression addop term",
"term : factor",
"term : term mulop factor",
"factor : IDENTIFIER tail",
"factor : IDENTIFIER LPAREN expression_list RPAREN",
"factor : number",
"factor : STRINGCONSTANT",
"factor : LPAREN expression RPAREN",
"factor : NOT factor",
"addop : PLUS",
"addop : MINUS",
"mulop : STAR",
"mulop : SLASH",
"relop : LT",
"relop : GT",
"relop : EQUAL",
"relop : LE",
"relop : GE",
"relop : notEQUAL",
"number : NUM",
"number : addop NUM",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 171 "parser.y"

int main(int argc, char** argv) { 
    yyparse();
	if(error==0){
		printf("OK\n");
	}
    return 0;
}


#line 376 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
