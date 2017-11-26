#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void primeraFuncion(int array[] , int longitud)
{
    int i;

    for (i=0 ; i<longitud ; i++)
    {
        printf("%d\n", array[i]);
    }
}
void segundaFuncion(int array[] , int longitud)
{
    int i;
    int *puntero;
    puntero = array;

    for (i=0 ; i<longitud ; i++)
    {
        printf("%d\n", *puntero+i);
    }

}

void terceraFuncion(int *array , int longitud)
{
    int i;

    for (i=0 ; i<longitud ; i++)
    {
        printf("%d\n", array[i]);
    }
}

void cuartaFuncion(int *array , int longitud)
{
    int i;

    for (i=0 ; i<longitud ; i++)
    {
        printf("%d\n", *array+i);
    }
}
