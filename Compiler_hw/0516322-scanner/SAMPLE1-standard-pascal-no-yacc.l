%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

#include <stdio.h>
#define   PROGRAM      1
#define   IDENTIFIER      2
#define   LPAREN      3
#define   RPAREN      4
#define   SEMICOLON      5
#define   DOT      6
#define   COMMA      7
#define   VAR      8
#define   COLON      9
#define   ARRAY      10
#define   RBRAC      11
#define   LBRAC      12
#define   NUM    13
#define   STRINGCONSTANT 14
#define   OF       16
#define   INTEGER               17
#define   REAL                  18
#define   FUNCTION      19
#define   PROCEDURE      20
#define   PBEGIN      21
#define   END     22
#define   ASSIGNMENT      23
#define   IF      24
#define   THEN      25
#define   ELSE      26
#define   WHILE      27
#define   DO      28
#define   GE      29
#define   GT      30
#define   LE      31
#define   LT      32
#define   EQUAL      33
#define   MINUS      34
#define   notEQUAL    35
#define   PLUS      36
#define   SLASH      37
#define   STAR      38
#define   NOT      39
#define   DOTDOT      40

int line_no = 1;


%}

%x COMMENT
A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]

%%

{P}{R}{O}{G}{R}{A}{M}        return(PROGRAM);
{I}{D}                       return(IDENTIFIER);
{V}{A}{R}                    return(VAR);
{A}{R}{R}{A}{Y}              return(ARRAY);
{O}{F}                       return(OF);
{I}{N}{T}{E}{G}{E}{R}        return(INTEGER);
{R}{E}{A}{L}                 return(REAL);
{F}{U}{N}{C}{T}{I}{O}{N}     return(FUNCTION);
{P}{R}{O}{C}{E}{D}{U}{R}{E}  return(PROCEDURE);
{B}{E}{G}{I}{N}              return(PBEGIN);
{E}{N}{D}                    return(END);
{I}{F}                       return(IF);
{T}{H}{E}{N}                 return(THEN);
{E}{L}{S}{E}                 return(ELSE);
{W}{H}{I}{L}{E}              return(WHILE);
{D}{O}                       return(DO);
{N}{O}{T}                    return(NOT);
[a-zA-Z]([a-zA-Z0-9\_])*     return(IDENTIFIER);

":="                         return(ASSIGNMENT);
":"                          return(COLON);
","                          return(COMMA);
"."                          return(DOT);
".."                         return(DOTDOT);
"="                          return(EQUAL);
"!="                         return(notEQUAL);
">="                         return(GE);
">"                          return(GT);
"["                          return(LBRAC);
"<="                         return(LE);
"("                          return(LPAREN);
"<"                          return(LT);
"-"                          return(MINUS);
"+"                          return(PLUS);
"]"                          return(RBRAC);
[-+]?[1-9][0-9]*|[0]          return(NUM);
[-+]?[0-9]*[.][0-9]*          return(NUM);
([-+]?[1-9][0-9]*|[0]|[-]?[0-9]*[.][0-9]*)[eE][\+\-]?[0-9]+ return(NUM);
")"                          return(RPAREN);
";"                          return(SEMICOLON);
"/"                          return(SLASH);
"*"                          return(STAR);

"//".*[\r\n]  {
                fprintf (stderr, "This is a C++ style comment at line %d: %s",line_no, yytext);
                line_no++;
              }

"/*" {BEGIN COMMENT;}
<COMMENT>[^*\n]*
<COMMENT>"*"+[^*/\n]*
<COMMENT>\n           ++line_no;
<COMMENT>"*/" {fprintf (stderr, "This is a C style comment ends at line %d\n",line_no);
                BEGIN 0;}

[\"]([^\"\n])*[\"]       return (STRINGCONSTANT);
[\"][^\n"]*              {
          fprintf(stderr, "string error at line %d : %s\n",line_no,yytext);
}

[ \t\f]    ;

\r         ;
\n   {
    line_no++;
  } 

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);
       }

%%

int main(int argc, char** argv) {
  int i, tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
    
  }
  return(0);
} /* end of main */

yywrap() {
  fclose(yyin);
  exit(1);
}

