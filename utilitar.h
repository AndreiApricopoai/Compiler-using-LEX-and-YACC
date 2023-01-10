#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




struct symbol_table{

    char* data_type ;
    char* identifier;
    int int_val;
    int bool_val;
    float float_val;
    char char_val;
    char* string_val;

    char* scope;

    int is_const;
    int is_array;
    int is_type;

    int int_array_values[200];
    char char_array_values[200];
    char* string_array_values[200];
    int bool_array_values[200];

    int array_number_elements;
    int array_allocated_memory;
};




struct param{
    char* data_type ;
    char* identifier;
    char* scope;
    int is_const;
    int is_array;
    int is_type;

    int array_number_elements;
    int array_allocated_memory;
};

struct functions_table{
    char* data_type ;
    char* identifier;

    int param_index;
    struct param params[50];
};


struct types_table
{
    char* identifier;
};











void setSymbolScope(int index, int type_index, char scope[100], char* block){
    if(strcmp(block,"functions") == 0){

        char intstring[5]= "\0";
        sprintf(intstring,"%d", index);
        strcpy(scope,"FUNCTIONS ");
        strcat(scope,"function ");
        strcat(scope, intstring);
    }
    if(strcmp(block,"types") == 0){

        strcpy(scope,"TYPES ");

        if(index == 0){

            char intstring[5]= "\0";
            sprintf(intstring,"%d", type_index);
            strcat(scope,"type");
            strcat(scope,intstring);
            strcat(scope," members");
        }
        else{

            char intstring[5]= "\0";
            sprintf(intstring,"%d", type_index);
            strcat(scope,"type");
            strcat(scope,intstring);
            strcat(scope," methods");

            sprintf(intstring,"%d", index);
            strcat(scope," method ");
            strcat(scope, intstring);


        }
    }

}

void setFunctionScope(int type_index, char scope[100], char* block){

    if(strcmp(block,"types") == 0){

        char intstring[5]= "\0";
        sprintf(intstring,"%d", type_index);
        strcpy(scope,"TYPES ");
        strcat(scope,"type");
        strcat(scope, intstring);
    }
}



int existsVariable(char* scope, char* symbol){

    return 0;
}

int existsFunction(char* scope, char* function){

    return 0;
}

int existsType(char* scope, char* type){

    return 0;
}




int addSymbol(int table_index, char* scope, struct symbol_table symbols[100],
              int is_type, int is_array, int is_const,char* data_type, char* identifier,
              char* value, char array_values[200][1000], int array_allocated_memory,  int array_number_elements){


   //printf("identifier : %s\nscope : %s\ndata_type : %s\nvalue : %s\narray_values : %s , %s\n\n\n",identifier,scope,data_type,value,array_values[0],array_values[1]);
    printf("%d ",table_index);

    return 0;
}

int addFunction(int table_index, char* scope, char* data_type, char* identifier, struct functions_table functions[100], char params[50][1000], int params_number){

    return 0;
}

int addType(int table_index ,char* identifier, struct types_table types[100]){

    //printf("type: %s\n",identifier);
    //printf("%d",table_index);

    return 0;
}






