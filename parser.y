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


%token START
%token GLOBAL
%token END_GLOBAL
%token FUNCTIONS
%token END_FUNCTIONS
%token TYPES
%token END_TYPES
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


/*aici avem structura programului : in continut avem textul care se gaseste intre START si END*/
program :  START continut END {printf("Programul este corect sintactic!\n");}
     ;

/*continutul programului (continut) este format din 4 blocuri */
continut : block
		| continut block
		;

/*blocurile sunt GLOBAL, FUNCTIONS, TYPES, MAIN*/
block : GLOBAL global END_GLOBAL
     |FUNCTIONS functions END_FUNCTIONS
     |TYPES types END_TYPES
	|MAIN main END_MAIN
     ;

/*global contine declaratiile de variabile, array-uri si constante---------------------------------------------------------------------------*/
global : variabile ;

/*aici putem avea o declaratie sau mai multe*/
variabile : variabila ';'
		| variabile variabila ';'
		;

/*o declaratie(variabila) poate avea urmatoarele forme*/
variabila : DATA_TYPE IDENTIFIER  /*ex: int a;*/
           | DATA_TYPE IDENTIFIER ASSIGN value
           | CONST DATA_TYPE IDENTIFIER {/*thows error*/ yyerror("const without value asociated!");}
           | CONST DATA_TYPE IDENTIFIER ASSIGN value
           | DATA_TYPE IDENTIFIER '[' ABSOLUTE_VALUE ']'
           | DATA_TYPE IDENTIFIER '[' ']' {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}
           | DATA_TYPE IDENTIFIER '[' ABSOLUTE_VALUE ']' ASSIGN '{' array_values '}'
           | DATA_TYPE IDENTIFIER '[' ']' ASSIGN '{' array_values '}'



/*valorile pe care le poate lua o variabila*/
value : INTEGER_VALUE
     |BOOL_VALUE
     |STRING_VALUE
     |CHAR_VALUE
     |FLOAT_VALUE
     ;

array_values : value
            | array_values ',' value




/*functions contine declaratiile si implementarea de functii-----------------------------------------------------------------------------------*/
functions : routines ;

routines : routine ';'
		| routines routine ';'
		;
routine : ;






types : ;
main : ;

%%




void yyerror(char * s){

printf("EROARE: %s LA LINIA : %d\n",s,yylineno);

}

int main(int argc, char** argv){

yyin=fopen(argv[1],"r");
yyparse();
return 0;

} 