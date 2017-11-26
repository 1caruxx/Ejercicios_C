#include <stdio.h>
#include <stdlib.h>
#define LONGITUD 20

int main()
{
    int* vector[20];
    int i;

    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("Ingrese un numero [%d/%d]: ", i+1 , LONGITUD);
        scanf("%d", vector+i);
    }

    printf("Los numeros que usted ingreso fueron:\n");
    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("%d\n", *(vector+i));
    }
    return 0;
}
