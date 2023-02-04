# Compiler-using-LEX-and-YACC

In order to run the compiler you need to install flex and yacc to your linux machine using the following commands:  
   -> [sudo apt-get update]  
   -> [sudo apt-get install flex]  
   -> [sudo apt-get install bison]  
  
After installation is complete run :  
   -> [flex lexer.l]  
   -> [yacc -d parser.y]  
   -> [gcc lex.yy.c y.tab.c]  
   -> [./a.out test.txt]  
