//Leer 20 n�meros enteros positivos, indicar cu�l es el mayor y en qu� orden fue le�do (a que elemento pertenece). Mostrar el vector completo
#include <stdio.h>
#include <stdlib.h>
#define constante 20

int main()
{
    int i,vector [constante],Posicion,max;

    for (i=0 ; i<constante ; i++)
    {
        printf("Ingrese un numero [%d/%d]: ",i+1,constante);
        scanf("%d", &vector [i]);

        if (vector [i]>max || i==0)
        {
            max = vector [i];
            Posicion = i;
        }

    }

    printf("El mayor elemento del vector es: %d y su posicion en el vector es: %d",max,Posicion);
    printf("\nLos elementos ingresados fueron:");

    for (i=0 ; i<constante ; i++)
    {
       printf(" %d",vector [i]);
    }

    return 0;
}
