#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>

int main()
{
    char input[] = "te Amo";

    char test[] = " me to";

    bzero(input,sizeof(input));

    strcat(input, test);

    printf("%s\n",input);
}