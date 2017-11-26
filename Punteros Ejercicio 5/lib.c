#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LONGITUD 5

void menu(void)
{
  EMedicamento medicamentos[LONGITUD];
  int opcion;

  while(1)
  {
    printf("1- Cargar el vector.\n");
    printf("2- Informar\n");
    printf("3- Salir\n\n");
    printf("Elija una opcion: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
      case 1:
          carga(medicamentos);
          break;

      case 2:
          //informar(medicamento);
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

void carga(EMedicamento* medicamentos)
{
    int i;

    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("Ingrese el codigo del medicamento: ");
        scanf("%d", &(medicamentos+i)->codigo);

        printf("Ingrese el precio: ");
        scanf("%f", &(medicamentos+i)->precio);

        printf("Ingrese la cantidad en stock: ");
        scanf("%d", &(medicamentos+i)->stock);
    }
}


void ordenar(EMedicamento* medicamentos)
{
    EMedicamento auxiliar;
    int i, j, minimo, flag=0;

    for(i=0 ; i<LONGITUD-1 ; i++)
    {
        for(j=i+1 ; j<LONGITUD ; j++)
        {
            if((*(medicamentos+i)).codigo > (*(medicamentos+j)).codigo)
            {
                auxiliar = *(medicamentos+i);
                *(medicamentos+i) = *(medicamentos+j);
                *(medicamentos+j) = auxiliar;
            }
        }
    }

    printf("Codigo\t\tPrecio\t\tStock\n\n");

    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("%d\t\t%f\t\t%d", (*(medicamentos+i)).codigo, (*(medicamentos+i)).precio, (*(medicamentos+i)).stock);
        if ((*(medicamentos+i)).precio<minimo || flag==0)
        {
            minimo = i;
        }
    }
    printf("El medicamento mas barato: %d, Precio: %f ", (*(medicamentos+i)).codigo, (*(medicamentos+i)).precio);

}
