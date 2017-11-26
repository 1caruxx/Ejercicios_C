/**Desarrollar una aplicación para un comercio que le permita administrar sus productos.
Datos de cada producto:
Código (1 a 1000) (Validar)
Descripción (máximo 50 caracteres) (Validar)
Importe (Validar)
Cantidad (Validar)
1. ALTAS: No es necesario el ingreso de todos los productos.
2. MODIFICAR: Se ingresará el Código de Producto, permitiendo modificar:
Descripción
Importe
Cantidad
3. BAJA: Se ingresa el Código de Producto y se limpiarán los datos asociados
4. LISTAR: Realizar un solo listado de los datos ordenados por descripción (descendente)*/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define C 25

int main()
{
    int opcion, i;
    EProducto dato[C];
    char rta = 's';

    printf("1 - Dar de alta un producto\n");
    printf("2 - Modificar un producto\n");
    printf("3 - Dar de baja un producto\n");
    printf("4 - Realizar listado\n");
    printf("5 - Salir\n");

    do
    {
        scanf("%d", &opcion);

        switch(opcion)
          {

            case 1:
             cargarProducto(dato , C);
             break;

            case 2:
             modificarProducto(dato , C);
             break;

            case 3:
             break;

            case 4:
                printf("Codigo\tNombre\t\tCantidad\tImporte\n");
                for(i=0 ; i<C ; i++)
                {
                   if (dato[i].estado == 1)
                   {
                      printf("%d\t%s\t%d\t\t%.2f\n",dato[i].codigo, dato[i].nombre, dato[i].cantidad, dato[i].importe);
                      printf("[%d/%d]\n",i+1,C);
                   }

                }
             break;

            case 5:
             break;
         }

    }while (rta == 's');


    return 0;
}
