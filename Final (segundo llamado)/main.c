#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "lib.h"
#define LIMPIEZA 1
#define FERRETERIA 2
#define LACTEOS 3
#define ELECTRO 4
#define BEBIDAS 5

int main()
{
    ArrayList* pListProductos;
    ArrayList* pListAuxiliar;
    FILE* pFILEproductos;
    float total;

    pListProductos = al_newArrayList();

    if(pListProductos == NULL)
    {
        printf("No se ha podido crear la lista de los productos.\n");
        exit(1);
    }

    pFILEproductos = fopen("productos.csv" , "r");

    if(pFILEproductos == NULL)
    {
        printf("No se ha podido abrir el arcihvo.");
        exit(1);
    }

    abrirArchivoDeProductos(pListProductos , pFILEproductos);
    imprimirListaDeProductos(pListProductos);
    pListAuxiliar = filter(pListProductos , LIMPIEZA);
    imprimirListaDeProductos(pListAuxiliar);
    pListAuxiliar = map(pListProductos , 25);
    imprimirListaDeProductos(pListAuxiliar);
    total = reduce(pListProductos);
    printf("El total de la suma de todos los productos es: %.2f" , total);

    return 0;
}
