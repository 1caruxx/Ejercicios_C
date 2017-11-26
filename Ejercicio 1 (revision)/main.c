#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

int main()
{
    /**hola*/
    int i,numero;
    float acum;
    for (i=0 ; i<5 ; i++)
    {
        printf("Ingrese un numero: ");
        scanf ("%d", &numero);
        acum = acum + numero;
        //system ("cls");
    }
    printf("El promedio de los numeros es: %f",acum/5);
    return 0;
}
