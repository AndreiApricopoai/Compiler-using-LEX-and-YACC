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

%token IDENTIFIER
%token INTEGER_VALUE
%token BOOL_VALUE
%token FLOAT_VALUE
%token STRING_VALUE
%token CHAR_VALUE

%token EVAL
%token TYPEOF
%token IF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token PRINT

%token ASSIGN
%token ARITHMETIC_OPERATOR
%token RELATIONAL_OPERATOR
%token SEMICOLON
%token NOT
%token COMMA
%token LSB
%token RSB
%token LCB
%token RCB
%token RPB
%token LPB
%token BOOLEAN_OPERATOR
%token TYPE


%left BOOLEAN_OPERATOR
%left RELATIONAL_OPERATOR
%left ARITHMETIC_OPERATOR
%left NOT


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
      | FUNCTIONS functions END_FUNCTIONS
      | TYPES types END_TYPES
	 | MAIN main END_MAIN
      ; 

/*global contine declaratiile de variabile, array-uri si constante---------------------------------------------------------------------------*/
global : variabile
       ;
       

/*aici putem avea o declaratie sau mai multe*/
variabile : variabila SEMICOLON
		| variabile variabila SEMICOLON
		;

/*o declaratie(variabila) poate avea urmatoarele forme*/
variabila : DATA_TYPE IDENTIFIER  /*ex: int a;*/
          | DATA_TYPE IDENTIFIER ASSIGN value{;}
          | CONST DATA_TYPE IDENTIFIER {/*thows error*/ yyerror("const without value asociated!");}
          | CONST DATA_TYPE IDENTIFIER ASSIGN value
          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB
          | DATA_TYPE IDENTIFIER LSB RSB {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}
          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN LCB array_values RCB
          | DATA_TYPE IDENTIFIER LSB RSB ASSIGN LCB array_values RCB
          ;


/*valorile pe care le poate lua o variabila*/
value : INTEGER_VALUE
      | BOOL_VALUE
      | STRING_VALUE
      | CHAR_VALUE
      | FLOAT_VALUE
      ;
      

array_values : value
             | array_values COMMA value
             ;




/*functions contine declaratiile si implementarea de functii-----------------------------------------------------------------------------------*/
functions : funcs_decl
          ;

funcs_decl : func_decl
      | funcs_decl func_decl
      ;

func_decl : DATA_TYPE IDENTIFIER LPB func_params RPB  LCB statements RETURN return_format SEMICOLON RCB
          ;

func_params : func_param 
       | func_params COMMA func_param 
       ;

func_param : DATA_TYPE IDENTIFIER
      | CONST DATA_TYPE IDENTIFIER
      | DATA_TYPE IDENTIFIER LSB RPB
      ;
      


statements : statement 
           | statements statement
           ;

/*if while for, print(), eval(), a = expression*/
statement : assignment SEMICOLON
          | variabila  SEMICOLON
          | func_call SEMICOLON
          | IDENTIFIER ACCES func_call SEMICOLON
          | control_statement
          | TYPEOF LPB /*TODO*/ RPB SEMICOLON 
          | EVAL LPB /*TODO*/ RPB SEMICOLON
          | PRINT LPB /*TODO*/ RPB SEMICOLON
          ;
                    

return_format : IDENTIFIER  
              | value 
              | LPB expression RPB 
              ;
              

assignment : IDENTIFIER ASSIGN expression 
           | IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN expression
           | IDENTIFIER ACCES IDENTIFIER ASSIGN expression
           ;


expression : value
           | IDENTIFIER
           | IDENTIFIER LSB INTEGER_VALUE RSB
           | IDENTIFIER ACCES IDENTIFIER
           | IDENTIFIER ACCES func_call
           | func_call
           | LPB expression RPB
           | expression ARITHMETIC_OPERATOR expression
           ;


func_call : IDENTIFIER LPB func_arguments RPB 
          | IDENTIFIER LPB RPB
          ;


control_statement : IF LPB conditions RPB  LCB statements  RCB 
                  | IF LPB conditions RPB  LCB statements  RCB ELSE LCB statements RCB
                  | WHILE LPB conditions RPB  LCB statements  RCB
                  | FOR LPB assignment SEMICOLON conditions SEMICOLON assignment RPB  LCB statements  RCB
                  ;



conditions : condition
           | NOT LPB conditions RPB
           | LPB conditions RPB
           | conditions BOOLEAN_OPERATOR conditions
           ;
           



condition : expression RELATIONAL_OPERATOR expression 
          ;



func_arguments : expression 
               | func_arguments COMMA expression
               ;





types : type
      | types type
      ;

type : IDENTIFIER LCB innertype RCB 
     ;

innertype : MEMBERS variabile METHODS funcs_decl
          | MEMBERS variabile
          | METHODS funcs_decl
          ;





main : main_statement 
     | main main_statement
     ;

main_statement : statement
               | TYPE IDENTIFIER IDENTIFIER SEMICOLON
               ;

%%




void yyerror(char * s){

printf("EROARE: %s LA LINIA : %d\n",s,yylineno);

}

int main(int argc, char** argv){
     
extern int yydebug;
yydebug = 1;

yyin=fopen(argv[1],"r");
yyparse();
return 0;

} 