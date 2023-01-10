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

    int array_index;
};





struct param{
    char* data_type;
    char* identifier;
};


struct functionInformation
{
    char* data_type;
    char* identifier;
    char* scope;
    struct param params[100];

};


struct typeInformation
{
    /* data */
};




void setScope(int index, int type_index, char scope[100], char* block){
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


int addVariable(char* scope, struct symbol_table symbols[100], int is_type, int is_array, int is_const,char* data_type, char* identifier, char* value, char array_values[200][1000], int array_allocated_memory,  int array_number_elements){


   printf("identifier : %s\nscope : %s\ndata_type : %s\nvalue : %s\narray_values : %s , %s\n\n\n",identifier,scope,data_type,value,array_values[0],array_values[1]);




    return 0;
}


int existsVariable(char* scope, char* symbol){

    return 0;
}


