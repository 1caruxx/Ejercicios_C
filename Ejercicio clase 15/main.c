#include <stdio.h>
#include <stdlib.h>
#define LONGITUD 3
#include "lib.h"

void main()
{
    int i;
    int array[LONGITUD];
    int opcion;

    for (i=0 ; i<LONGITUD ; i++)
    {
        printf("Ingrese un numero [%d/%d]", i+1, LONGITUD);
        scanf("%d", &array[i]);
    }

    printf("Como desea mostrar los datos?\n");
    printf("Segun el ejercicio 1\n");
    printf("Segun el ejercicio 2\n");
    printf("Segun el ejercicio 3\n");
    printf("Segun el ejercicio 4\n");

    scanf("%d", &opcion);

    switch (opcion)
    {
      case 1:
        primeraFuncion(array , LONGITUD);
        break;

      case 2:
        segundaFuncion(array , LONGITUD);
        break;

      case 3:
        terceraFuncion(array , LONGITUD);
        break;

      case 4:
        cuartaFuncion(array , LONGITUD);
        break;

      default:
        printf("Error, dato ingresado invalido.\n");
    }
    system("pause");
}
