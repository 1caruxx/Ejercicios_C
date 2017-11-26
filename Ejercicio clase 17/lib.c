#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

char* getDynamicString()
{
    char* vector = (char*) malloc(sizeof(char)*24);

    printf("Ingrese una cadena de caracteres: ");
    fflush(stdin);
    gets(vector);

    vector = (char*) realloc (vector , sizeof(char)*strlen(vector)+1);
    return vector;

}
