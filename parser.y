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

#define GLOBAL_SCOPE "GLOBAL"
#define TYPES_SCOPE "TYPES"
#define FUNCTIONS_SCOPE "FUNCTIONS"
#define MAIN_SCOPE "MAIN"


extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern void yyerror();
extern int yylex();

char SYMBOL_SCOPE[100] = "GLOBAL"; // la inceput intram in global(default)
char FUNCTION_SCOPE[100] = "FUNCTIONS"; // la inceput intram in functions(default)

int symbol_scope_position = 0;
int function_scope_position = 0;

int types_position = 0;
int suntem_in_types = 0;



struct symbol_table symbols[100]; // aici vor fi stocate variabilele si array-urile
struct functions_table functions[100]; // aici vor fi stocate functiile si metodele
struct types_table types[100];

int index_symbols_table = 0;
int index_functions_table = 0;
int index_types_table = 0;






char UNDEFINED_ARRAY[200][1000]={"N/A"};
char ARRAY_VALUES[200][1000];
int index_arr = 0;

char FUNCTION_PARAMS[50][1000];
char NO_PARAMS[50][1000] = {"N/A"};

int index_par = 0;






%}

/*tipuri de date pe care le ia yylval*/
%union {
      
int int_value;
char* string_value;
float float_value;


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





%type<string_value>value
%type<string_value>func_param







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
block : GLOBAL global_block END_GLOBAL {
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "functions");
}
      | GLOBAL  END_GLOBAL{

      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "functions");
}
      | FUNCTIONS functions_block END_FUNCTIONS {

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");

}
      |FUNCTIONS  END_FUNCTIONS{

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");

}
      | TYPES types_block END_TYPES {
      strcpy(SYMBOL_SCOPE,MAIN_SCOPE);
      suntem_in_types = 0;
}
      | TYPES  END_TYPES{

      strcpy(SYMBOL_SCOPE,MAIN_SCOPE);
      suntem_in_types = 0;
}
	| MAIN main_block END_MAIN 
      | MAIN  END_MAIN 
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
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, $1, $2, UNDEFINED,UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
} 
          | DATA_TYPE IDENTIFIER ASSIGN value{
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, $1, $2, $4,UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
}      
          | CONST DATA_TYPE IDENTIFIER    {/*thows error*/ yyerror("const without value asociated!");}
          | CONST DATA_TYPE IDENTIFIER ASSIGN value{
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, IS_CONST, $2, $3, $5, UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
}
          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB{      
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, UNDEFINED_ARRAY,$4,0);
      index_symbols_table++;
}
          | DATA_TYPE IDENTIFIER LSB RSB   {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}


          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN LCB array_values RCB{
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, ARRAY_VALUES ,$4,index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
}
          | DATA_TYPE IDENTIFIER LSB RSB ASSIGN LCB array_values RCB{
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, ARRAY_VALUES ,0,index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
}

          | TYPE IDENTIFIER IDENTIFIER{
      addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, IS_TYPE, NOT_ARRAY, NOT_CONST, $2, $3, UNDEFINED, UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
}
          ;


/*valorile pe care le poate lua o declaratie_variabila*/
value : INTEGER_VALUE {$$ = strdup(yytext);}
      | BOOL_VALUE    {$$ = strdup(yytext);}
      | STRING_VALUE  {$$ = strdup(yytext);}
      | CHAR_VALUE    {$$ = strdup(yytext);}
      | FLOAT_VALUE   {$$ = strdup(yytext);}
      ;
      

array_values : array_value 
             | array_values COMMA array_value 
             ;
array_value : value{
      strcpy(ARRAY_VALUES[index_arr],$1); index_arr++;
}
            ;



/*functions_block contine declaratiile si implementarea de functii-----------------------------------------------------------------------------------*/
functions_block : functions_decl{symbol_scope_position = 0;}
          ;

functions_decl : func_decl
      | functions_decl func_decl
      ;



func_decl : DATA_TYPE IDENTIFIER LPB function_params RPB  LCB statements RETURN expression SEMICOLON RCB{
      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");
           
      addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, FUNCTION_PARAMS, index_par);
      memset(FUNCTION_PARAMS,0,50*1000*sizeof(char));

      index_par = 0;
      index_functions_table++;

}
          | DATA_TYPE IDENTIFIER LPB  RPB  LCB statements RETURN expression SEMICOLON RCB{

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");

      addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, NO_PARAMS, 0);

      index_par = 0;
      index_functions_table++;
     
}
          | DATA_TYPE IDENTIFIER LPB function_params RPB  LCB  RETURN expression SEMICOLON RCB{

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");

      addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, FUNCTION_PARAMS, index_par);
      memset(FUNCTION_PARAMS,0,50*1000*sizeof(char));

      index_par = 0;
      index_functions_table++;


}
          | DATA_TYPE IDENTIFIER LPB  RPB  LCB  RETURN expression SEMICOLON RCB{

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");
           
      addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, NO_PARAMS, 0);

      index_par = 0;
      index_functions_table++;
}
          ;

function_params : func_param 
       | function_params COMMA func_param  
       ;

func_param : DATA_TYPE IDENTIFIER {strcpy($$,$1); strcat($$," "); strcat($$,$2); strcpy(FUNCTION_PARAMS[index_par],$$); index_par++;}
      | CONST DATA_TYPE IDENTIFIER {strcpy($$,"const"); strcat($$," "); strcat($$,$2); strcat($$," "); strcat($$,$3); strcpy(FUNCTION_PARAMS[index_par],$$); index_par++;}
      | DATA_TYPE IDENTIFIER LSB RSB {strcpy($$,$1); strcat($$," "); strcat($$,$2);strcat($$,"["); strcat($$,"]"); strcpy(FUNCTION_PARAMS[index_par],$$); index_par++;}
      | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB {
      strcpy($$,$1); strcat($$," "); strcat($$,$2);strcat($$,"[");

      char intstring[20]= "\0";
      sprintf(intstring,"%d", $4);
      strcat($$,intstring);
      strcat($$,"]");

      strcpy(FUNCTION_PARAMS[index_par],$$);
      index_par++;
}
      | IDENTIFIER IDENTIFIER {strcpy($$,$1); strcat($$," "); strcat($$,$2); strcpy(FUNCTION_PARAMS[index_par],$$); index_par++;}/*pentru tipuri custom*/
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
          | EVAL LPB expression RPB SEMICOLON
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


type : IDENTIFIER LCB inner_content RCB {
      symbol_scope_position = 0; types_position++;  
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");

      addType(index_types_table, $1, types);
      index_types_table++;

}
     | IDENTIFIER LCB RCB {
      symbol_scope_position = 0; types_position++;
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position,FUNCTION_SCOPE,"types");

      addType(index_types_table, $1, types);
      index_types_table++;
      }
     ;

inner_content : MEMBERS declaratii_variabile METHODS functions_decl{

}
          | MEMBERS declaratii_variabile METHODS{
}
          | MEMBERS METHODS functions_decl{
}
          | MEMBERS METHODS{
}
          | MEMBERS{
}
          | MEMBERS declaratii_variabile{
}
          | METHODS{
} 
          | METHODS functions_decl{
}
          ;





main_block : statement 
     | main_block statement
     ;


%%


void showError(int error_code){

}




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