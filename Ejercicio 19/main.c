#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,numero,acumulador=0;

    printf("Introduzca un numero: ");
    scanf("%d", &numero);

    for (i=0 ; i<numero ; i++)
    {
        acumulador += i;
    }
    printf("La suma de todos sus numeros antecesores es: %d",acumulador);

    return 0;
}
