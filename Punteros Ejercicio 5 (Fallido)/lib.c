#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LONGITUD 50

void menu(void)
{
  int opcion, mesas[LONGITUD];

  inicializarVector (mesas);

  while(1)
  {
    printf("1- Cargar un nuevo importe.\n");
    printf("2- Informar\n");
    printf("3- Salir\n\n");
    printf("Elija una opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
      case 1:
          cargarImporte(mesas);
          break;

      case 2:
          //printf
          break;

      case 3:
        exit(9);
        break;

      default:
          printf("El valor ingresado no es valido.\n");

    }

    system("pause");
    system("cls");

  }

}

void inicializarVector (int* mesas)
{
    int i;

    for (i=0 ; i<LONGITUD ; i++)
    {
       *(mesas+i) = 0;
    }
}

void cargarImporte(int* mesas)
{
    int auxiliar, importe;

    printf("Indique el numero de la mesa: ");
    scanf("%d", &auxiliar);

    printf("Indique el importe: ");
    scanf("%d", &importe);

    *(mesas+auxiliar-1) += importe;
}

void informar(int* mesas)
{
    int i, j, ventaTotal, flag=0;

    for(i=0 ; i<LONGITUD ; i++)
    {
        ventaTotal += *(mesas+i);

        if (flag == 0)
        {
            printf("Las mesas que no han sido ocupadas fueron: ");
            flag = 1;
        }

        if(*(mesas+i) == 0)
        {
            printf("%d ", i+1);
        }
    }

    for(i=0 ; i<LONGITUD-1 ; i++)
    {
        for(j=i+1 ; j<LONGITUD ; j++)
        {
            if(1)
            {
                printf("Este ejercicio debia hacerse con estructuras");
            }
        }
    }

    printf("La venta total del dia fue: %d", ventaTotal);
}
