README for Compiler hw2 -- parser.

To run this parser, run the following commands:

>> lex lex.l

>> yacc -d -v parser.y

>> gcc -o parser lex.yy.c y.tab.c -ly -lfl

>> ./parser < ./test/test-minus-neg.p
 
If the input contains no syntactic errors, the output of the parser will be the string "OK".
Otherwise, the parser will issue an error message such as

        line 23: error token ident

This parser does not do error recovery. It stops at the first error.