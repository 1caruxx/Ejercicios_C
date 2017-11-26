#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,numero;

    printf("Introduzca un numero: ");
    scanf("%d", &numero);
    printf("Todos los numeros reales que le anteceden son:");

    for (i=0 ; i<numero ; i++)
    {
        if (i>=1)
        {
            printf(" %d",i);
        }
    }

    return 0;
}
