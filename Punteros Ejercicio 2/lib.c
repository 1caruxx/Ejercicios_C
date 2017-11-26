#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LONGITUD 5
#define ESC 27

void menu(void)
{
  int opcion;
  int vector[LONGITUD];

  while(1)
  {
    printf("1- Cargar el vector.\n");
    printf("2- Ordenar el vector.\n");
    printf("3- Mostrar el vector.\n");
    printf("ESC- Salir\n\n");
    printf("Elija una opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
      case 1:
          carga(vector);
          break;

      case 2:
          ordenar(vector);
          break;

      case 3:
          mostrar(vector);
          break;

      case ESC:
        exit(9);
        break;

      default:
          printf("El valor ingresado no es valido.\n");

    }

    system("pause");
    system("cls");

  }

}


void carga(int* vector)
{
    int i;

    for (i=0 ; i<LONGITUD ; i++)
    {
        printf("Ingrese un numero [%d/%d]", i+1 , LONGITUD);
        scanf("%d", vector+i);
    }
}

void ordenar(int* vector)
{
    int i, j, auxiliar;

    for(i=0 ; i<LONGITUD-1 ; i++)
    {
        for(j=i+1 ; j<LONGITUD ; j++)
        {
            if(*(vector+i) > *(vector+j))
            {
                auxiliar = *(vector+i);
                *(vector+i) = *(vector+j);
                *(vector+j) = auxiliar;
            }
        }
    }
}
void mostrar(int* vector)
{
    int i;

    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("%d\n", *(vector+i));
    }

}
