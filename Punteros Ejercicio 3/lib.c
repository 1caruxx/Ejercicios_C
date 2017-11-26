#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LONGITUD 5

void menu(void)
{
  int opcion;
  EEmpleado vector[LONGITUD];
  //EEmpleado* punteroAestructura;
  //punteroAestructura = vector;

  while(1)
  {
    printf("1- Cargar un empleado.\n");
    printf("2- Listar\n");
    printf("3- Informar\n");
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
          listar(vector);
          break;

      case 3:
           informar(vector);
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

void carga(EEmpleado* empleado)
{
    int i, contador=0;

    for (i=0 ; i<LONGITUD ; i++)
    {
        if((*(empleado+i)).estado != 1)
        {
            printf("Ingrese el legajo del empleado: ");
            scanf("%d", &(empleado+i)->legajo);

            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            gets((*(empleado+i)).nombre);

            printf("Ingrese la edad del empleado: ");
            scanf("%d", &(empleado+i)->edad);

            printf("Ingrese el sexo del empleado [f/m]: ");
            fflush(stdin);
            scanf("%c", &(empleado+i)->sexo);

            (*(empleado+i)).estado = 1;
            break;
        }
        else
        {
            contador++;
        }
    }

    if(contador == LONGITUD)
    {
        printf("No hay espacio en el vector.\n");
    }

}

void listar(EEmpleado* empleado)
{
    int i, contador=0;

    printf("Legajo\t\tNombre\t\tEdad\t\tSexo\n");

    for(i=0 ; i<LONGITUD ; i++)
    {
        if((*(empleado+i)).estado == 1)
        {
            printf("%d\t\t%s\t\t%d\t\t%c\n", (*(empleado+i)).legajo, (*(empleado+i)).nombre, (*(empleado+i)).edad, (*(empleado+i)).sexo);
        }
        else
        {
            contador++;
        }
    }

    if(contador == LONGITUD)
    {
        printf("No se ha cargado ningun empleado.\n");
    }
}

void informar(EEmpleado* empleado)
{
    int i, acumulador=0, flag=0, maximo=0, contador=0;

    for(i=0 ; i<LONGITUD ; i++)
    {
        acumulador += (*(empleado+i)).edad;

        if((*(empleado+i)).edad>maximo || flag==0)
        {
            maximo = (*(empleado+i)).legajo;
        }

        if((*(empleado+i)).sexo=='f' && (*(empleado+i)).edad==38)
        {
            contador++;
        }
    }

    printf("La edad promedio de los empleados es: %d\n", acumulador/LONGITUD);

    for(i=0 ; i<LONGITUD ; i++)
    {
        if(maximo == (*(empleado+i)).legajo)
        {
            printf("El legajo y sexo de la persona de mayor edad: %d, %d\n", (*(empleado+i)).legajo, (*(empleado+i)).sexo);
        }
    }

    printf("Cantidad de mujeres que nacieron en el año 1978: %d", contador);
}

