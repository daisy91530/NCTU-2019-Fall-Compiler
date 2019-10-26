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
#define   COMMENT     41
#define   AND     42
#define   OR    43

int line_no = 1;
int i=0;

%}

%x COMMENTSPACE
%x PLUSSPACE
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
{O}{R}                       return(OR);
{A}{N}{D}                    return(AND);
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
")"                          return(RPAREN);
";"                          return(SEMICOLON);
"/"                          return(SLASH);
"*"                          return(STAR);
[-+]?[1-9][0-9]*|[0]         {BEGIN PLUSSPACE;return(NUM);}
[-+]?[0-9]+[.][0-9]+         {BEGIN PLUSSPACE;return(NUM);}
([-+]?[1-9][0-9]*|[0]|[-]?[0-9]*[.][0-9]*)[eE][\+\-]?[0-9]+ {BEGIN PLUSSPACE;return(NUM);}

<PLUSSPACE>"+"                          {BEGIN 0;return(PLUS);}
<PLUSSPACE>"-"                          {BEGIN 0;return(MINUS);}
<PLUSSPACE>"/"                          {BEGIN 0;return(SLASH);}
<PLUSSPACE>"*"                          {BEGIN 0;return(STAR);}
<PLUSSPACE>\n                           {++line_no; BEGIN 0;}
<PLUSSPACE>{P}{R}{O}{G}{R}{A}{M}        {BEGIN 0;return(PROGRAM);}
<PLUSSPACE>{I}{D}                       {BEGIN 0;return(IDENTIFIER);}
<PLUSSPACE>{V}{A}{R}                    {BEGIN 0;return(VAR);}
<PLUSSPACE>{A}{R}{R}{A}{Y}              {BEGIN 0;return(ARRAY);}
<PLUSSPACE>{O}{F}                       {BEGIN 0;return(OF);}
<PLUSSPACE>{I}{N}{T}{E}{G}{E}{R}        {BEGIN 0;return(INTEGER);}
<PLUSSPACE>{R}{E}{A}{L}                 {BEGIN 0;return(REAL);}
<PLUSSPACE>{F}{U}{N}{C}{T}{I}{O}{N}     {BEGIN 0;return(FUNCTION);}
<PLUSSPACE>{P}{R}{O}{C}{E}{D}{U}{R}{E}  {BEGIN 0;return(PROCEDURE);}
<PLUSSPACE>{B}{E}{G}{I}{N}              {BEGIN 0;return(PBEGIN);}
<PLUSSPACE>{E}{N}{D}                    {BEGIN 0;return(END);}
<PLUSSPACE>{I}{F}                       {BEGIN 0;return(IF);}
<PLUSSPACE>{T}{H}{E}{N}                 {BEGIN 0;return(THEN);}
<PLUSSPACE>{E}{L}{S}{E}                 {BEGIN 0;return(ELSE);}
<PLUSSPACE>{W}{H}{I}{L}{E}              {BEGIN 0;return(WHILE);}
<PLUSSPACE>{D}{O}                        {BEGIN 0;return(DO);}
<PLUSSPACE>{N}{O}{T}                    {BEGIN 0;return(NOT);}
<PLUSSPACE>{O}{R}                        {BEGIN 0;return(OR);}
<PLUSSPACE>{A}{N}{D}                    {BEGIN 0;return(AND);}
<PLUSSPACE>[a-zA-Z]([a-zA-Z0-9\_])*     {BEGIN 0;return(IDENTIFIER);}
<PLUSSPACE>":="                         {BEGIN 0;return(ASSIGNMENT);}
<PLUSSPACE>":"                          {BEGIN 0;return(COLON);}
<PLUSSPACE>","                          {BEGIN 0;return(COMMA);}
<PLUSSPACE>"."                          {BEGIN 0;return(DOT);}
<PLUSSPACE>".."                         {BEGIN 0;return(DOTDOT);}
<PLUSSPACE>"="                          {BEGIN 0;return(EQUAL);}
<PLUSSPACE>"!="                         {BEGIN 0;return(notEQUAL);}
<PLUSSPACE>">="                         {BEGIN 0;return(GE);}
<PLUSSPACE>">"                          {BEGIN 0;return(GT);}
<PLUSSPACE>"["                          {BEGIN 0;return(LBRAC);}
<PLUSSPACE>"<="                         {BEGIN 0;return(LE);}
<PLUSSPACE>"("                          {BEGIN 0;return(LPAREN);}
<PLUSSPACE>"<"                          {BEGIN 0;return(LT);}
<PLUSSPACE>"]"                          {BEGIN 0;return(RBRAC);}
<PLUSSPACE>")"                          {BEGIN 0;return(RPAREN);}
<PLUSSPACE>";"                          {BEGIN 0;return(SEMICOLON);}
<PLUSSPACE>"//".*[\r\n]                 {fprintf (stderr, "%3d-th token(type:%d) on line %d : %s",i, COMMENT,line_no, yytext);
                                        i++;
                                        line_no++;
                                        BEGIN 0;}
<PLUSSPACE>"/*"                         {fprintf (stderr, "%3d-th token(type:%d) on line %d : %s",i, COMMENT,line_no, yytext);
                                        BEGIN COMMENTSPACE;}
<PLUSSPACE>[\"]([^\"\n])*[\"]           {BEGIN 0;return (STRINGCONSTANT);}
<PLUSSPACE>[\"][^\n"]*                  {fprintf(stderr, "string error at line %d : %s\n",line_no,yytext);BEGIN 0;}
<PLUSSPACE>[ \t\f]                      {BEGIN 0;}
<PLUSSPACE>\r                           {BEGIN 0;}
<PLUSSPACE>.                            {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);BEGIN 0;}



"//".*[\r\n]  {
                fprintf (stderr, "%3d-th token(type:%d) on line %d : %s",i, COMMENT,line_no, yytext);
                i++;
                line_no++;
              }
"/*"                                    {fprintf (stderr, "%3d-th token(type:%d) on line %d : %s",i, COMMENT,line_no, yytext);
                                                  BEGIN COMMENTSPACE;}
<COMMENTSPACE>[^*\n]*                   {fprintf (stderr, "%s",yytext);}
<COMMENTSPACE>"*"+[^*/\n]*              {fprintf (stderr, "%s",yytext);}
<COMMENTSPACE>\n                        {fprintf (stderr, "%s",yytext); 
                                                            ++line_no;}
<COMMENTSPACE>"*/" {fprintf (stderr, "%s\n",yytext);
                                                  BEGIN 0; return(COMMENT); }

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
  int tok;
  yyin = fopen("test.txt", "r");
  for (i = 0; 1==1; i ++) {
    tok = yylex();
    if(tok!=COMMENT){
      fprintf(stderr, "%3d-th token(type:%d) on line %d : %s\n", i, tok,line_no, yytext);
    }
  }
  return(0);
} /* end of main */

yywrap() {
  fclose(yyin);
  exit(1);
}

