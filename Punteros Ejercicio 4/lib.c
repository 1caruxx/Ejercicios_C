#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LONGITUD 5

void menu(void)
{
  int opcion, vector[LONGITUD];


  while(1)
  {
    printf("1- Cargar el vector.\n");
    printf("2- Ingresar un número y mostrar en que posición dentro del vector se encuentra\n");
    printf("3- Ingresar la posición del vector y mostrar el número que se encuentra en esa posición\n");
    printf("4- Salir\n\n");
    printf("Elija una opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
      case 1:
          carga(vector);
          break;

      case 2:
          puntoA(vector);
          break;

      case 3:
           puntoB(vector);
           break;

      case 4:
        exit(9);
        break;

      default:
          printf("El valor ingresado no es valido.\n");

    }

    system("pause");
    system("cls");

  }

}

void validarRango (int* numero , int minimo , int maximo)
{
    while (*(numero)<minimo || *(numero)>maximo)
    {
         printf("Error, el valor no cumple con el rango propuesto. Reingrese: ");
         scanf("%d", numero);
    }
}

void carga(int* vector)
{
    int i;

    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("Ingrese un nuemero [%d/%d]: ", i+1, LONGITUD);
        scanf("%d", (vector+i));
    }
}

void puntoA(int* vector)
{
   int i, auxiliar, contador=0;

    printf("Ingrese el numero que quiere buscar: ");
    scanf("%d", &auxiliar);

    printf("El numero se encuentra en la posicion: ");

    for(i=0 ; i<LONGITUD ; i++)
    {
        if(auxiliar == (*(vector+i)))
        {
            printf("%d ", i);
        }
        else
        {
            contador++;
        }
    }

    if(contador == LONGITUD)
    {
        printf("Error, el numero no existe");
    }

    printf("en el vector.\n");
}

void puntoB(int* vector)
{
    int auxiliar;

    printf("Ingrese la posicion del vector cuyo numero quiere ver: ");
    scanf("%d", &auxiliar);

    validarRango(&auxiliar , 0 , LONGITUD-1);

    printf("El numero que se encuentra en esa posicion es: %d\n", *(vector+auxiliar));

}
