#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char test[] = "var[5]";

    char *p=strtok(test,"]");

    printf("%d\n",atoi(p[strlen(p)-1]));
    return 0;
}