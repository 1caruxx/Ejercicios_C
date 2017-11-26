#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,numero,acumSuma=0,acumMultiplicacion=1;

    for (i=0 ; i<10 ; i++)
    {
        printf("Introduzca un numero [%d/10]: ",i+1);
        scanf("%d", &numero);

    while (numero == 0)
     {
        printf("ERROR, el numero debe ser distonto de 0. Reintroduzca un numero [%d/10]: ",i+1);
        scanf("%d", &numero);
     }

    if (numero > 0)
     {
        acumSuma = acumSuma + numero;//acumSuma += numero;
     }
     else
        acumMultiplicacion = acumMultiplicacion * numero;//acumMultiplicacion *= numero;
    }

    printf("La suma de los numeros positivos es: %d\nEl producto de los numeros negativos es: %d",acumSuma,acumMultiplicacion);

    return 0;
}
