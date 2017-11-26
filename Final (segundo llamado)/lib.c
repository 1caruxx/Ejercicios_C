#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "lib.h"

void abrirArchivoDeProductos(ArrayList* pList , FILE* pFILE)
{
    char codigo[20];
    char categoria[5];
    char precio[15];
    eProducto* puntero;

    while(!feof(pFILE))
    {

        printf("\t\t\t\t Espacio en memoria ocupado: %d / %d (%d%c)\n", pList->len(pList), pList->reservedSize, (pList->len(pList) * 100)/pList->reservedSize, 37);
        puntero = (eProducto*) malloc(sizeof(eProducto));

        fscanf(pFILE , "%[^,],%[^,],%[^,],%[^\n]\n" , codigo , puntero->descripcion , categoria , precio);

        puntero->codigo = atoi(codigo);
        puntero->categoria = atoi(categoria);
        puntero->precio = atof(precio);

        pList->add(pList , puntero);
    }

    pList->remove(pList , 0);
}

void imprimirListaDeProductos(ArrayList* pList)
{
    int i;
    eProducto* puntero;

    printf("Codigo\tCategoria\tDescripcion\tprecio\n\n");


    for(i=0 ; i<pList->len(pList) ; i++)
    {
        puntero = pList->get(pList , i);
        printf("%d\t%d\t%s\t%f\n" , puntero->codigo , puntero->categoria , puntero->descripcion , puntero->precio);
    }
    system("pause");
    system("cls");
}

ArrayList* filter(ArrayList* pLista , int cat)
{
    int i;
    eProducto* puntero;
    ArrayList* pListaNew;

    pListaNew = al_newArrayList();

    if(pListaNew == NULL)
    {
        printf("No se ha podido crear la lista filtrada.\n");
        exit(1);
    }

    for(i=0 ; i<pLista->len(pLista) ; i++)
    {
        puntero = pLista->get(pLista , i);

        if(puntero->categoria == cat)
        {
            pListaNew->add(pListaNew , puntero);
        }
    }

    return pListaNew;
}

ArrayList* map(ArrayList*  pLista , float porcentaje)
{
    int i;
    eProducto* puntero;
    ArrayList* pListaNew;

    pListaNew = al_newArrayList();

    if(pListaNew == NULL)
    {
        printf("No se ha podido crear la lista filtrada.\n");
        exit(1);
    }

    for(i=0 ; i<pLista->len(pLista) ; i++)
    {
        puntero = pLista->get(pLista , i);
        puntero->precio += ((puntero->precio)*porcentaje) / 100;

        pListaNew->add(pListaNew , puntero);
    }

    return pListaNew;
}

float reduce(ArrayList* pLista)
{
    int i;
    float total=0;
    eProducto* puntero;

    for(i=0 ; i<pLista->len(pLista) ; i++)
    {
        puntero = pLista->get(pLista , i);
        total += puntero->precio;
    }

    return total;
}
