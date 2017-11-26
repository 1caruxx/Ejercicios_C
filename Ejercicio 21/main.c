#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,numero,contMultiplos=0;

    printf("Introduzca un numero: ");
    scanf("%d", &numero);
    printf("Todos los numeros multiplos de 3 que le anteceden son:");

    for (i=0 ; i<numero ; i++)
    {
        if (i%3 == 0)
        {
            contMultiplos ++;
            printf(" %d",i);
        }
    }
    printf("\nLa cantidad de numeros multiplos de 3 que anteceden al %d son: %d",numero,contMultiplos);
    return 0;
}
