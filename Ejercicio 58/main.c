//Leer 10 elementos de un vector de enteros y mostrar su contenido
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,vector [10];

    for (i=0 ; i<10 ; i++)
    {
        printf("Ingrese un numero [%d/10]: ",i+1);
        scanf("%d", &vector [i]);
        system("cls");
    }

        printf("Los numeros que usted ingreso fueron:");
        for (i=0 ; i<10 ; i++)
    {
        printf(" %d",vector [i]);
    }

    return 0;
}
