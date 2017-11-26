#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void cargarProducto(EProducto dato[] , int longitud)
{
    int i;

    for(i=0 ; i<longitud ; i++)
    {
        if(dato[i].estado != 1)
        {
            printf("Ingrese el codigo del producto: ");
            scanf("%d", &dato[i].codigo);
            printf("Ingrese el nombre del producto: ");
            fflush(stdin);
            gets(dato[i].nombre);
            printf("Ingrese la cantidad disponible del producto: ");
            scanf("%d", &dato[i].cantidad);
            printf("Ingrese el importe del producto: ");
            scanf("%f", &dato[i].importe);
            dato[i].estado = 1;
            break;
        }
    }
}
void modificarProducto(EProducto dato[] , int longitud)
{
    int i, codigoAuxiliar, opcion;

    printf("Ingrese el codigo del producto que desea modificar: ");
    scanf("%d", &codigoAuxiliar);

    for (i=0 ; i<longitud ; i++)
    {
        if(codigoAuxiliar == dato[i].codigo)
        {
            printf("Codigo\tNombre\tCantidad\tImporte\n");
            printf("%d\t%s\t%d\t%f\n\n",dato[i].codigo, dato[i].nombre, dato[i].cantidad, dato[i].importe);
            printf("¿Que desea modificar?\n");
            printf("1 - Nombre\n");
            printf("2 - Cantidad disponible\n");
            printf("3 - Importe");

            scanf("%d", &opcion);

            switch (opcion)
            {
               case 1:
                 printf("Ingrese el nuevo nombre para el producto: ");
                 fflush(stdin);
                 gets(dato[i].nombre);
                 break;

               case 2:
                 printf("Ingrese la cantidad disponible: ");
                 scanf("%d", &dato[i].cantidad);
                 break;

               case 3:
                 printf("Ingrese el nuevo importe: ");
                 scanf("%f", &dato[i].importe);
                 break;
            }
        }
    }
}
