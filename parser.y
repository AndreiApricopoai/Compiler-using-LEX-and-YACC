%{

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <regex.h>
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



void showError(int error_code){

    switch (error_code)
    {
    case -1:
        yyerror("valoare variabilei are tip difert fata de cel declarat!"); // variable has diffrent datatype value in definition
        break;
    case -2:
        yyerror("valorile din array au tip diferit fata de cel declarat!"); // valorile din array nu sunt de tipul array-ului
        break;
    case -3:
        yyerror("membrul sau variabila este deja definita cu acest nume in acel scope!"); // eroare variabila sau membrul de tip definit este deja definita in acel scope
        break;
    case -4:
        yyerror("functia contine mai multi parametrii cu acelasi identificator!"); // functia contine mai multi parametrii cu acelasi nume
        break;
    case -5:
        yyerror("metoda sau functia este deja definita in acel scope!"); // eroare frunctia sau metoda este deja definita in acel scope
        break;
    case -6:
        yyerror("tipul este deja definit!"); // eroare tipul custom este deja definit
        break;
    case -7:
        yyerror("eroare la creare symbol_table.txt si functions_table.txt!"); // symbol_table.txt si functions_table.txt
        break;  
    case -15:
        yyerror("variabila este utilizata dar nu este definita nicaieri!"); // asignare
        break; 
    case -16:
        yyerror("variabilele au tipuri de date diferite!"); // asignare
        break; 
    case -20:
        yyerror("se incearca atrbuirea unei valori catre variabila const!"); // asignare
        break; 
    
    default:
        break;
    }

}



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
%type<string_value>leftexp







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
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");


}
      |FUNCTIONS  END_FUNCTIONS{

      symbol_scope_position = 0;
      types_position = 0;
      suntem_in_types = 1;
      setSymbolScope(symbol_scope_position, types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");


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
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, $1, $2, UNDEFINED,UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);
} 
          | DATA_TYPE IDENTIFIER ASSIGN value{
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, NOT_CONST, $1, $2, $4,UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}      
          | CONST DATA_TYPE IDENTIFIER    {/*thows error*/ yyerror("const without value asociated!");}
          | CONST DATA_TYPE IDENTIFIER ASSIGN value{
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, NOT_ARRAY, IS_CONST, $2, $3, $5, UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB{      
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, UNDEFINED_ARRAY,$4,0);
      index_symbols_table++;
      showError(code);

}
          | DATA_TYPE IDENTIFIER LSB RSB   {/*throws error array with no space allocated*/ yyerror("error array with no space allocated!");}


          | DATA_TYPE IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN LCB array_values RCB{
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, ARRAY_VALUES ,$4,index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
      showError(code);

}
          | DATA_TYPE IDENTIFIER LSB RSB ASSIGN LCB array_values RCB{
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, NOT_TYPE, IS_ARRAY, NOT_CONST, $1, $2, UNDEFINED, ARRAY_VALUES ,0,index_arr);
      index_symbols_table++;
      index_arr = 0;
      memset(ARRAY_VALUES,0,200*1000*sizeof(char));
      showError(code);

}

          | TYPE IDENTIFIER IDENTIFIER{
      int code = addSymbol(index_symbols_table, SYMBOL_SCOPE, symbols, IS_TYPE, NOT_ARRAY, NOT_CONST, $2, $3, UNDEFINED, UNDEFINED_ARRAY,0,0);
      index_symbols_table++;
      showError(code);

}
          ;


/*valorile pe care le poate lua o declaratie_variabila*/
value : INTEGER_VALUE {$$ = strdup(yytext); }
      | BOOL_VALUE    {$$ = strdup(yytext); }
      | STRING_VALUE  {$$ = strdup(yytext); }
      | CHAR_VALUE    {$$ = strdup(yytext); }
      | FLOAT_VALUE   {$$ = strdup(yytext); }
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
           
      int code = addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, FUNCTION_PARAMS, index_par);
      memset(FUNCTION_PARAMS,0,50*1000*sizeof(char));

      index_par = 0;
      index_functions_table++;
      showError(code);

}
          | DATA_TYPE IDENTIFIER LPB  RPB  LCB statements RETURN expression SEMICOLON RCB{

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");

      int code = addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, NO_PARAMS, 0);

      index_par = 0;
      index_functions_table++;
      showError(code);
     
}
          | DATA_TYPE IDENTIFIER LPB function_params RPB  LCB  RETURN expression SEMICOLON RCB{

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");

      int code = addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, FUNCTION_PARAMS, index_par);
      memset(FUNCTION_PARAMS,0,50*1000*sizeof(char));

      index_par = 0;
      index_functions_table++;
      showError(code);


}
          | DATA_TYPE IDENTIFIER LPB  RPB  LCB  RETURN expression SEMICOLON RCB{

      symbol_scope_position++;
      if(suntem_in_types == 1)
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      else
            setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "functions");
           
      int code = addFunction(index_functions_table, FUNCTION_SCOPE, $1, $2, functions, NO_PARAMS, 0);

      index_par = 0;
      index_functions_table++;
      showError(code);
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
                  | FOR LPB condition_assignment SEMICOLON conditions SEMICOLON condition_assignment RPB  LCB statements  RCB
                  | FOR LPB condition_assignment SEMICOLON conditions SEMICOLON condition_assignment RPB  LCB   RCB
                  | FOR LPB  SEMICOLON  SEMICOLON  RPB  LCB statements  RCB
                  | FOR LPB  SEMICOLON  SEMICOLON  RPB  LCB   RCB
                  ;

condition_assignment: IDENTIFIER ASSIGN expression 
                    | IDENTIFIER LSB INTEGER_VALUE RSB ASSIGN expression
                    | IDENTIFIER ACCES IDENTIFIER ASSIGN expression
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
          | TYPEOF LPB STRING_VALUE RPB SEMICOLON
            {
                  removeQuotes($3);
                  char identifier1[100];
                  char identifier2[100];
                  char sign[100];

                  char output[100];
                  bzero(output,sizeof(output));

                  sscanf($3,"%s %s %s",identifier1,sign,identifier2);
                  //printf("%s\n",identifier1);

                  if(strchr(identifier1,'[')!=0)
                  {
                        char aux[100];
                        strcpy(aux, identifier1);

                        char *p=strtok(aux,"[");

                        strcpy(identifier1, p);

                  }

                  if(strchr(identifier2,'[')!=0)
                  {
                        char aux[100];
                        strcpy(aux, identifier2);

                        char *p=strtok(aux,"[");

                        strcpy(identifier2, p);
                  }

                  if(existsVariable("MAIN",identifier1,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier1)==1)
                        {
                              strcat(output,"int ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==2)
                        {
                              strcat(output,"float ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==3)
                        {
                              strcat(output,"char ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==4)
                        {
                              strcat(output,"string ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==5)
                        {
                              strcat(output,"bool ");
                              strcat(output,sign);
                        }
                  }
                  else if(existsVariable("GLOBAL",identifier1,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier1)==1)
                        {
                              strcat(output,"int ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==2)
                        {
                              strcat(output,"float ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==3)
                        {
                              strcat(output,"char ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==4)
                        {
                              strcat(output,"string ");
                              strcat(output,sign);
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier1)==5)
                        {
                              strcat(output,"bool ");
                              strcat(output,sign);
                        }
                  }
                  else
                  {
                        yyerror("TypeOf: Variabila nu exista!");
                  }

                  if(existsVariable("MAIN",identifier2,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier2)== 1)
                        {
                              strcat(output," int");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==2)
                        {
                              strcat(output," float");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==3)
                        {
                              strcat(output," char");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==4)
                        {
                              strcat(output," string");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==5)
                        {
                              strcat(output," bool");
                        }
                  }
                  else if(existsVariable("GLOBAL",identifier2,symbols,index_symbols_table)==1)
                  {
                        if(getDataType(symbols,index_symbols_table,identifier2)== 1)
                        {
                              strcat(output," int");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==2)
                        {
                              strcat(output," float");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==3)
                        {
                              strcat(output," char");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==4)
                        {
                              strcat(output," string");
                        }
                        else if(getDataType(symbols,index_symbols_table,identifier2)==5)
                        {
                              strcat(output," bool");
                        }
                  }
                  else
                  {
                        yyerror("TypeOf: Variabila nu exista!");
                  }

                  bzero(identifier1,sizeof(identifier1));
                  bzero(identifier2,sizeof(identifier2));

                  sscanf(output,"%s %s %s",identifier1, sign, identifier2);

                  if(strcmp(identifier1,identifier2)==0)
                  {
                        printf("TypeOf(%s)\n",output);
                  }
                  else
                  {
                        yyerror("TypeOf -> Parametrii diferiti!");
                  }

            }
          | EVAL LPB STRING_VALUE RPB SEMICOLON 
            {
            if(strcmp(SYMBOL_SCOPE,"MAIN")==0)
            {          
                  removeQuotes($3);
                  char aux[500];
                  char finalString[500];
                  char simbol[100];
                  char varName[100];
                  char arrayName[100];
                  char arrayValue[100];
                  char expression[100];

                  strcpy(aux,$3);
                  strcpy(expression,$3);

                  
                  replace_function_calls(aux);

                  //printf("%s\n",aux);

                  int isNumber=0;
                  int isVar=0;
                  bzero(finalString,sizeof(finalString));
                  bzero(arrayName,sizeof(arrayName));
                  bzero(arrayValue,sizeof(arrayValue));
                  for(int i=0;i<strlen(aux);i++)
                  {
                        if(aux[i]=='+' || aux[i]=='-' || aux[i]=='*' ||
                           aux[i]=='/' || aux[i]=='(' || aux[i]==')') 
                           {
                              if(existsVariable("MAIN",varName,symbols,index_symbols_table)==1)
                              {
                                    int stringNumber;
                                    stringNumber=getIntValue(symbols,index_symbols_table,varName);

                                    char strNumber[100];
                                    sprintf(strNumber,"%i",stringNumber);

                                    strcat(finalString, strNumber);
                                    bzero(varName, sizeof(varName));
                              }
                              else if(existsVariable("GLOBAL",varName,symbols,index_symbols_table)==1)
                              {
                                    int stringNumber;
                                    stringNumber=getIntValue(symbols,index_symbols_table,varName);

                                    char strNumber[100];
                                    sprintf(strNumber,"%i",stringNumber);
                                    
                                    strcat(finalString, strNumber);
                                    bzero(varName, sizeof(varName));
                              }
                              bzero(varName,sizeof(varName));
                              sprintf(simbol,"%c",aux[i]);
                              strcat(finalString, simbol);
                              isNumber=0;
                              isVar=0;
                           }
                           else if(((aux[i] >= 'a' && aux[i] <= 'z') || (aux[i] >= 'A' && aux[i] <= 'Z')) && isVar == 0)
                           {
                              isVar=0;
                              isNumber=1;
                              sprintf(simbol,"%c",aux[i]);
                              strcat(varName, simbol);
                           }
                           else if(isdigit(aux[i]) && isNumber == 0 )
                           {
                              isVar=1;
                              isNumber=0;
                              sprintf(simbol,"%c",aux[i]);
                              strcat(finalString, simbol);
                           }
                           else if(aux[i]=='[')
                           {
                              isVar=1;
                              isNumber=1;
                              sprintf(simbol,"%c",aux[i]);
                              strcat(arrayValue,simbol);
                           }
                           else if(aux[i]== ']')
                           {
                              sprintf(simbol,"%c",aux[i]);
                              strcat(arrayValue,simbol);

                              if(existsVariable("MAIN",varName,symbols,index_symbols_table)==1)
                              {
                                    strcat(varName,arrayValue);

                                    int stringNumber;
                                    stringNumber=getIntValue(symbols,index_symbols_table,varName);

                                    char strNumber[100];

                                    sprintf(strNumber,"%i",stringNumber);

                                    strcat(finalString, strNumber);
                                    bzero(varName, sizeof(varName));
                              }
                           }
                           else
                           {
                              sprintf(simbol,"%c",aux[i]);
                              strcat(arrayValue,simbol);
                           }

                        //    printf("%s - > %i\n",finalString,i);
                        //    printf("%s - > %i\n",arrayValue,i);
                           
                  }

                  //printf("%s\n",finalString);
                  //printf("VAL:%i\n",atoi(finalString));
                  infixToPostfix(finalString);

                  //printf("%s\n",finalString);
                  struct Node *root = buildTree(finalString);


                  printf("(Eval)Rezultatul expresiei %s este : %i\n",expression, evaluate(root));
                  
            }
            }
          ;
                    
              

assignment : leftexp ASSIGN value{

      if(strcmp($1,"N/A") != 0){

            if($1[strlen($1)-1] == 'V'){
                  $1[strlen($1)-1] = '\0';
                  int res = assign($1,$3, 1 , 1,symbols,index_symbols_table);
                  showError(res);



            }
            else if($1[strlen($1)-1] == 'A'){
                  $1[strlen($1)-1] = '\0';
                  int res = assign($1,$3, 2 , 1,symbols,index_symbols_table) ;
                  showError(res);
            }
      }
} 
           | leftexp ASSIGN IDENTIFIER{

      if(strcmp($1,"N/A") !=0){

            if($1[strlen($1)-1] == 'V'){
                  $1[strlen($1)-1] = '\0';
                  int res = assign($1,$3, 1 , 2,symbols,index_symbols_table);
                  showError(res);
                  

            }
            else if($1[strlen($1)-1] == 'A'){
                  $1[strlen($1)-1] = '\0';
                  int res = assign($1,$3, 2 , 2,symbols,index_symbols_table);
                  showError(res);
            }
      }
}
           | leftexp ASSIGN IDENTIFIER LSB INTEGER_VALUE RSB{

      if(strcmp($1,"N/A") !=0){

            char aux[100];
            char intToString[50];

            strcpy(aux,$3); strcat(aux,"["); 
            sprintf(intToString,"%d",$5);
            strcat(aux,intToString); 
            strcat(aux,"]");
            

            if($1[strlen($1)-1] == 'V'){
                  $1[strlen($1)-1] = '\0';
                  int res = assign($1,aux, 1 , 3,symbols,index_symbols_table);
                  showError(res);

            }
            else if($1[strlen($1)-1] == 'A'){
                  $1[strlen($1)-1] = '\0';
                  int res = assign($1,aux, 2 , 3,symbols,index_symbols_table);
                  showError(res);
            }
      }
}
           | leftexp ASSIGN EVAL LPB STRING_VALUE RPB{

      if(strcmp($1,"N/A") !=0){
            //asteptam functia EVAL();

      }
}
           | leftexp ASSIGN IDENTIFIER ACCES IDENTIFIER //nimic
           | leftexp ASSIGN IDENTIFIER ACCES function_call //nimic
           ;

leftexp : IDENTIFIER {strcpy($$,$1); strcat($$,"V");}
        | IDENTIFIER LSB INTEGER_VALUE RSB {
            strcpy($$,$1); strcat($$,"["); 
            char aux[100];
            sprintf(aux,"%d",$3);
            strcat($$,aux); 
            strcat($$,"]");
            strcat($$,"A");
            }
        | IDENTIFIER ACCES IDENTIFIER {strcat($$,"N/A");}
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




types_block : type
      | types_block type
      ;


type : IDENTIFIER LCB inner_content RCB {
      symbol_scope_position = 0; types_position++;  
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position, FUNCTION_SCOPE,"types");

      int code = addType(index_types_table, $1, types);
      index_types_table++;
      showError(code);

}
     | IDENTIFIER LCB RCB {
      symbol_scope_position = 0; types_position++;
      setSymbolScope(symbol_scope_position,types_position, SYMBOL_SCOPE, "types");
      setFunctionScope(types_position,FUNCTION_SCOPE,"types");

      int code = addType(index_types_table, $1, types);
      index_types_table++;
      showError(code);
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

int res = symbol_table_file(symbols, index_symbols_table); // aici printam tabela de simboluri in symbol_table.txt
showError(res);
res = functions_table_file(functions, index_functions_table); // aici printam tabela de functii in functions_table.txt
showError(res);


return 0;

} 