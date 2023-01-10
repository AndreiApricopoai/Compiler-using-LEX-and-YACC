%{

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "utilitar.h"


#define IS_TYPE 1
#define NOT_TYPE 0
#define IS_ARRAY 1
#define NOT_ARRAY 0
#define IS_CONST 1
#define NOT_CONST 0

#define UNDEFINED "N/A"

#define GLOBAL_SCOPE "global"
#define TYPES_SCOPE "types"
#define FUNCTIONS_SCOPE "functions"
#define MAIN_SCOPE "main"


extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern void yyerror();
extern int yylex();



struct symbol_table symbols[100]; // aici vor fi stocate variabilele si array-urile
int index_symbol = 0;


char SCOPE[50] = "global"; // la inceput intram in global(default)
char UNDEFINED_ARRAY[200][1000]={"N/A"};









%}

/*tipuri de date pe care le ia yylval*/
%union {
      
int int_value;
char* string_value;
float float_value;

struct variableInformation* varInfo;

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

%token <string_value> DATA_TYPE
%token CONST
%token ACCES

%token <string_value> IDENTIFIER
%token <int_value> INTEGER_VALUE
%token <int_value> BOOL_VALUE
%token <float_value> FLOAT_VALUE
%token <string_value> STRING_VALUE
%token <string_value> CHAR_VALUE

%token EVAL
%token TYPEOF
%token IF
%token ELSE
%token FOR
%token WHILE
%token RETURN
%token PRINT

%token ASSIGN
%token <string_value> ARITHMETIC_OPERATOR
%token <string_value> RELATIONAL_OPERATOR
%token SEMICOLON
%token <string_value> NOT
%token COMMA
%token LSB
%token RSB
%token LCB
%token RCB
%token RPB
%token LPB 
%token <string_value> BOOLEAN_OPERATOR
%token TYPE



%type<varInfo>declaratie_variabila



%type<string_value>value


%type<varInfo>array_values

%type<string_value>expression
/*
%type<varInfo>functions_decl
%type<varInfo>func_decl
%type<varInfo>function_params
%type<varInfo>func_param
%type<varInfo>function_arguments

*/





%left BOOLEAN_OPERATOR
%left RELATIONAL_OPERATOR
%left ARITHMETIC_OPERATOR
%left NOT
%left ACCES
%left LSB
%left RSB
%left LPB
%left RPB


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
block : GLOBAL global_block END_GLOBAL {strcpy(SCOPE,FUNCTIONS_SCOPE);}
      | FUNCTIONS functions_block END_FUNCTIONS {strcpy(SCOPE,TYPES_SCOPE);}
      | TYPES types_block END_TYPES {strcpy(SCOPE,MAIN_SCOPE);}
	| MAIN main_block END_MAIN 
      ; 


/*global_block contine declaratiile de declaratii_variabile, array-uri si constante---------------------------------------------------------------------------*/
global_block : declaratii_variabile
             ;
       

/*aici putem avea o declaratie sau mai multe*/
declaratii_variabile : declaratie_variabila SEMICOLON
		| declaratii_variabile declaratie_variabila SEMICOLON
		;

/*o declaratie(declaratie_variabila) poate avea urmatoarele forme*/
declaratie_variabila : DATA_TYPE IDENTIFIER{
      addVariable(SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, $1, $2, UNDEFINED,UNDEFINED_ARRAY,0,0);
   /*ex: int a;*/
} 
          | DATA_TYPE IDENTIFIER ASSIGN value{
      addVariable(SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, $1, $2, $4,UNDEFINED_ARRAY,0,0);
}      
          | CONST DATA_TYPE IDENTIFIER    {/*thows error*/ yyerror("const without value asociated!");}
          | CONST DATA_TYPE IDENTIFIER ASSIGN value{
      addVariable(SCOPE, symbols, NOT_TYPE, NOT_ARRAY, IS_CONST, $2, $3, $5, UNDEFINED_ARRAY,0,0);
}
          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB{
      addVariable(SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, UNDEFINED_ARRAY,$4,111);
}
          | DATA_TYPE IDENTIFIER LSB RSB   {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}



          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN LCB array_values RCB{
      //addVariable(SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, ,$4);
}
          | DATA_TYPE IDENTIFIER LSB RSB ASSIGN LCB array_values RCB{
      //addVariable(SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, ,0);
}



          | TYPE IDENTIFIER IDENTIFIER{
      addVariable(SCOPE, symbols, IS_TYPE, NOT_ARRAY, NOT_CONST, $2, $3, UNDEFINED, UNDEFINED_ARRAY,0,0);
}
          ;


/*valorile pe care le poate lua o declaratie_variabila*/
value : INTEGER_VALUE {$$ = strdup(yytext);}
      | BOOL_VALUE    {$$ = strdup(yytext);}
      | STRING_VALUE  {$$ = strdup(yytext);}
      | CHAR_VALUE    {$$ = strdup(yytext);}
      | FLOAT_VALUE   {$$ = strdup(yytext);}
      ;
      

array_values : value
             | array_values COMMA value
             ;



/*functions_block contine declaratiile si implementarea de functii-----------------------------------------------------------------------------------*/
functions_block : functions_decl
          ;

functions_decl : func_decl
      | functions_decl func_decl
      ;

func_decl : DATA_TYPE IDENTIFIER LPB function_params RPB  LCB statements RETURN expression SEMICOLON RCB
          | DATA_TYPE IDENTIFIER LPB  RPB  LCB statements RETURN expression SEMICOLON RCB
          | DATA_TYPE IDENTIFIER LPB function_params RPB  LCB  RETURN expression SEMICOLON RCB
          | DATA_TYPE IDENTIFIER LPB  RPB  LCB  RETURN expression SEMICOLON RCB
          ;

function_params : func_param 
       | function_params COMMA func_param 
       ;

func_param : DATA_TYPE IDENTIFIER
      | CONST DATA_TYPE IDENTIFIER
      | DATA_TYPE IDENTIFIER LSB RSB
      | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB
      | IDENTIFIER IDENTIFIER /*pentru tipuri custom*/
      ;


function_call : IDENTIFIER LPB function_arguments RPB 
          | IDENTIFIER LPB RPB
          ; 
    

function_arguments : expression 
               | function_arguments COMMA expression
               ;




control_statement : IF LPB conditions RPB  LCB statements  RCB 
                  | IF LPB conditions RPB  LCB  RCB
                  | IF LPB conditions RPB  LCB statements  RCB ELSE LCB statements RCB
                  | IF LPB conditions RPB  LCB   RCB ELSE LCB statements RCB
                  | IF LPB conditions RPB  LCB statements  RCB ELSE LCB  RCB
                  | IF LPB conditions RPB  LCB  RCB ELSE LCB  RCB
                  | WHILE LPB conditions RPB  LCB statements  RCB
                  | WHILE LPB conditions RPB  LCB  RCB
                  | FOR LPB assignment SEMICOLON conditions SEMICOLON assignment RPB  LCB statements  RCB
                  | FOR LPB assignment SEMICOLON conditions SEMICOLON assignment RPB  LCB   RCB
                  | FOR LPB  SEMICOLON  SEMICOLON  RPB  LCB statements  RCB
                  | FOR LPB  SEMICOLON  SEMICOLON  RPB  LCB   RCB
                  ;


conditions : condition
           | NOT LPB conditions RPB
           | LPB conditions RPB
           | conditions BOOLEAN_OPERATOR conditions
           ;
           

condition : expression RELATIONAL_OPERATOR expression 
          ;



statements : statement 
           | statements statement
           ;


statement : assignment SEMICOLON
          | declaratie_variabila  SEMICOLON
          | function_call SEMICOLON
          | IDENTIFIER ACCES function_call SEMICOLON
          | control_statement
          | TYPEOF LPB typeof_arguments RPB SEMICOLON 
          | EVAL LPB STRING_VALUE RPB SEMICOLON {Eval($3,yylineno);}
          | PRINT LPB value RPB SEMICOLON
          ;
                    
              

assignment : IDENTIFIER ASSIGN expression 
           | IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN expression
           | IDENTIFIER ACCES IDENTIFIER ASSIGN expression
           ;


expression : value
           | IDENTIFIER 
           | IDENTIFIER LSB INTEGER_VALUE RSB 
           | IDENTIFIER ACCES IDENTIFIER 
           | IDENTIFIER ACCES function_call 
           | function_call 
           | LPB expression RPB 
           | expression ARITHMETIC_OPERATOR expression
           ;


typeof_arguments : ;


types_block : type
      | types_block type
      ;

type : IDENTIFIER LCB inner_content RCB 
     | IDENTIFIER LCB RCB
     ;

inner_content : MEMBERS declaratii_variabile METHODS functions_decl
          | MEMBERS declaratii_variabile METHODS
          | MEMBERS METHODS functions_decl
          | MEMBERS METHODS
          | MEMBERS
          | MEMBERS declaratii_variabile
          | METHODS 
          | METHODS functions_decl
          ;





main_block : statement 
     | main_block statement
     ;


%%




void yyerror(char * s){

printf("EROARE: %s LA LINIA : %d\n",s,yylineno);

}

int main(int argc, char** argv){

 /*  
extern int yydebug;
yydebug = 1;
*/

yyin=fopen(argv[1],"r");
yyparse();
return 0;

} 