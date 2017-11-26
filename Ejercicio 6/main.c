#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int i,numero,contPositivos=0,contNegativos=0;

    for (i=0 ; i<10 ; i++)
    {
        printf("Ingrese un numero %d de 10: ",i+1);
        scanf("%d", &numero);

        if (numero > 0)
        {
            contPositivos ++;
        }

        if (numero < 0)
        {
            contNegativos ++;
        }

    }

    printf("La cantidad de numeros positivos ingresados es: %d\nLa cantidad de numeros negativos ingresados es: %d",contPositivos,contNegativos);

    return 0;
}
