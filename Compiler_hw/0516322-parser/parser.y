%{
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

%}

%token PROGRAM IDENTIFIER LPAREN RPAREN SEMICOLON DOT COMMA VAR COLON ARRAY
%token RBRAC LBRAC NUM STRINGCONSTANT OF INTEGER REAL FUNCTION PROCEDURE
%token PBEGIN END ASSIGNMENT IF THEN ELSE WHILE DO GE GT
%token LE LT EQUAL MINUS notEQUAL PLUS SLASH STAR NOT DOTDOT AND OR
%%


prog : PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON declarations subprogram_declarations compound_statement DOT
	;

identifier_list : IDENTIFIER
	| identifier_list COMMA IDENTIFIER
	;

declarations : declarations VAR identifier_list COLON type SEMICOLON
	| 
	;

type : standard_type
	| ARRAY LBRAC number DOTDOT number RBRAC OF type
	;


standard_type : INTEGER
	| REAL
    | STRINGCONSTANT
    ;

subprogram_declarations : subprogram_declarations subprogram_declaration SEMICOLON
	|
	;

subprogram_declaration : 
	subprogram_head
	declarations
	subprogram_declarations
	compound_statement
	;

subprogram_head : FUNCTION IDENTIFIER arguments COLON standard_type SEMICOLON
	| PROCEDURE IDENTIFIER arguments SEMICOLON
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

compound_statement : PBEGIN
	optional_statements
	END
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
	| number
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

number : NUM
	| addop NUM
	;

%%

int main(int argc, char** argv) { 
    yyparse();
	if(error==0){
		printf("OK\n");
	}
    return 0;
}


