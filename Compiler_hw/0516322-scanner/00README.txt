README for Compiler hw1 -- scanner.

To generate this scanner, run the following commands: (I run it in my Mac zsh)

>> flex SAMPLE1-standard-pascal-no-yacc.l
   The above command will generate a file named ``lex.yy.c''.

>> cc lex.yy.c
   The above command will produce an executable file, say ``a.out''.

>> ./a.out < scanner-test01.p"
 
The output of the scanner should be the list of the tokens produced by the scanner, together with the line number and character position in the line:

  0-th token(type:28) on line 1 : PROGRAM
  1-th token(type:39) on line 1 : mytest
  ... 

Some special parts:

  1. // This is C++ Style Comment
    -> print out "This is a C++ style comment at line x : ..."
  2. /* This is C Style Comment */
    -> print out "This is a C style comment ends at line x"
  3. String
    -> there is no multi-line string, so treat the first line as error, print out the content, and the other lines as usual tokens. For example,
    "Multi-line      ->print out " string error at line 1 : " Multi-Line  "
    String Content"  ->read as usual...