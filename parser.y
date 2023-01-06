%{

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern void yyerror();
extern int yylex();

%}

%union {
int intval;
char* strval;
}


%token NEWLINE

%token START
%token GLOBAL
%token FUNCTIONS
%token TYPES
%token MEMBERS
%token METHODS
%token MAIN
%token END_MAIN
%token END

%token DATA_TYPE
%token CONST
%token ACCES

%token CUSTOM_TYPE
%token IDENTIFIER
%token INTEGER_VALUE
%token ABSOLUTE_VALUE
%token BOOL_VALUE
%token FLOAT_VALUE
%token STRING_VALUE
%token CHAR_VALUE

%token EVAL
%token PRINT
%token TYPEOF
%token IF
%token FOR
%token WHILE
%token RETURN

%token ASSIGN
%token ARITHMETIC_OPERATOR
%token RELATIONAL_OPERATOR





%left '+' '-'
%left '*' '/'

%start program


%%


program :  START continut END {printf("Programul este corect sintactic!\n");}
     ;


continut : linie
		| continut linie
		;

linie : NEWLINE {;}
     |DATA_TYPE IDENTIFIER
     |DATA_TYPE IDENTIFIER ASSIGN INTEGER_VALUE
	|PRINT '(' IDENTIFIER ')'
     |EVAL '(' IDENTIFIER '+' IDENTIFIER')'
     |IF '(' IDENTIFIER RELATIONAL_OPERATOR IDENTIFIER ')' '{' '}'
     ;


%%




void yyerror(char * s){

printf("EROARE: %s LA LINIA : %d\n",s,yylineno);

}

int main(int argc, char** argv){

yyin=fopen(argv[1],"r");
yyparse();
return 0;

} 