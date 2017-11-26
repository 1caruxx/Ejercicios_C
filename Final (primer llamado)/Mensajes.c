#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Mensajes.h"

ArrayList* abrirArchivoDeMensajes(ArrayList* pListMensajes , FILE* pFILEmensajes)
{
    int flag=0;
    EMensaje* puntero;

    pListMensajes = al_newArrayList();

    if(pListMensajes == NULL)
    {
        printf("No hay suficiente espacio en memoria para crear la lista de mensajes.\n");
        exit(1);
    }

    pFILEmensajes = fopen("mensajes.csv" , "r");

    if(pFILEmensajes == NULL)
    {
        printf("No se ha podido abrir el archivo 'mensajes.csv'.\n");
        exit(1);
    }

    while(!feof(pFILEmensajes))
    {
        if(flag == 0)
        {
            flag = 1;
            continue;
        }

        printf("\t\t\t\t Espacio en memoria ocupado: %d / %d (%d%c)\n", pListMensajes->len(pListMensajes), pListMensajes->reservedSize, (pListMensajes->len(pListMensajes) * 100)/pListMensajes->reservedSize, 37);
        puntero = (EMensaje*) malloc(sizeof(EMensaje));

        fscanf(pFILEmensajes , "%[^,],%[^,],%[^,],%[^\n]\n" , puntero->id_mensaje , puntero->id_usuario , puntero->popularidad_mensaje , puntero->mensaje);

        pListMensajes->add(pListMensajes , puntero);
    }

    pListMensajes->remove(pListMensajes , 0);
    return pListMensajes;
}

void imprimirListaDeMensajes(ArrayList* pListMensajes)
{
    int i;
    EMensaje* puntero;

    printf("ID\tID usuario\tPopularidad\tMensaje\n\n");


    for(i=0 ; i<pListMensajes->len(pListMensajes) ; i++)
    {
        puntero = pListMensajes->get(pListMensajes , i);
        printf("%s\t%s\t%s\n" , puntero->id_mensaje , puntero->id_usuario , puntero->popularidad_mensaje /*puntero->mensaje*/);
    }
    system("pause");
    system("cls");
}
