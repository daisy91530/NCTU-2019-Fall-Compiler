%{
/***************
*input type:String,Char,NUM
*number:int,float,scientific
****************/
#include<stdio.h>
#include<stdlib.h>

extern FILE *yyin;              /* declared by lex */

void yyerror (char const *s){
    extern char *yytext;
    extern int line_no;
    fprintf (stderr, "%s: at line %d symbol'%s'\n", s,line_no,yytext);
 }

%}

%token PROGRAM ELSE WHILE DO THEN IF OF FUNCTION PROCEDURE PBEGIN
%token END ARRAY VAR NOT STRINGCONSTANT ASSIGNMENT COLON COMMA INTEGER COMMENT
%token DOT DOTDOT EQUAL notEQUAL GE GT LBRAC LE LPAREN LT 
%token MINUS PLUS RBRAC REAL RPAREN SEMICOLON SLASH STAR OR AND
%token NUM
%token IDENTIFIER

%%


prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON
  	    declarations
	    subprogram_declarations
	    compound_statement
	    DOT
	 ;

identifier_list : IDENTIFIER
	| identifier_list COMMA IDENTIFIER
	;

declarations : declarations VAR identifier_list COLON type SEMICOLON
	| 
	;

type : standard_type
	| ARRAY LBRAC NUM DOTDOT NUM RBRAC OF type
	;


standard_type : INTEGER
	| REAL
    | STRINGCONSTANT
    ;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON
	|
	;

subprogram_declaration : subprogram_head declarations compound_statement
					  ;

subprogram_head : FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON
	| PROCEDURE IDENTIFIER arguments
	;


arguments : LPAREN parameter_list RPAREN
	| 
	;


parameter_list : optional_var identifier_list COLON type
	| optional_var identifier_list COLON type SEMICOLON parameter_list
	;

optional_var : VAR
    | 
    ;

compound_statement : PBEGIN optional_statements END
	;



optional_statements : statement_list
	;


statement_list : statement 
	| statement_list SEMICOLON statement
	;


statement : variable ASSIGNMENT expression
	| procedure_statement
	| compound_statement
	| IF expression THEN statement ELSE statement
	| WHILE expression DO statement
	| 
	;


variable : IDENTIFIER tail
	;


tail : LBRAC expression RBRAC tail
	|
	;


procedure_statement : IDENTIFIER
	| IDENTIFIER LPAREN expression_list RPAREN
	;


expression_list : expression
	| expression_list COMMA expression
	;

expression : boolexpression
    | boolexpression AND boolexpression
    | boolexpression OR  boolexpression
	;

boolexpression : simple_expression
	| simple_expression relop simple_expression
	;


simple_expression : term
	| simple_expression addop term
	;


term : factor
	| term mulop factor
	;


factor : IDENTIFIER tail
	| IDENTIFIER LPAREN expression_list RPAREN
	| NUM
	| STRINGCONSTANT
	| LPAREN expression RPAREN
	| NOT factor
	;


addop : PLUS 
	  | MINUS
	  ;


mulop : STAR
	  | SLASH
	  ;



relop : LT 
	| GT
	| EQUAL
	| LE
	| GE
	| notEQUAL
	;

%%

int main(int argc, char** argv) { 
    fprintf(stderr, "call yyparse\n");
    yyparse();
    printf("-----------------------------------------------\n");
    return 0;
}


