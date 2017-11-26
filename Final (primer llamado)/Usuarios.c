#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Usuarios.h"

ArrayList* abrirArchivoDeUsuarios(ArrayList* pListUsuarios , FILE* pFILEusuarios)
{
    int flag=0;
    EUsuario* puntero;

    pListUsuarios = al_newArrayList();

    if(pListUsuarios == NULL)
    {
        printf("No hay suficiente espacio en memoria para crear la lista de mensajes.\n");
        exit(1);
    }

    pFILEusuarios = fopen("usuarios.csv" , "r");

    if(pFILEusuarios == NULL)
    {
        printf("No se ha podido abrir el archivo 'usuarios.csv'.\n");
        exit(1);
    }

    while(!feof(pFILEusuarios))
    {
        if(flag == 0)
        {
            flag = 1;
            continue;
        }

        printf("\t\t\t\t Espacio en memoria ocupado: %d / %d (%d%c)\n", pListUsuarios->len(pListUsuarios) , pListUsuarios->reservedSize, (pListUsuarios->len(pListUsuarios) * 100)/pListUsuarios->reservedSize, 37);
        puntero = (EUsuario*) malloc(sizeof(EUsuario));

        fscanf(pFILEusuarios , "%[^,],%[^,],%[^\n]\n" , puntero->id_usuario , puntero->nick , puntero->popularidad_usuario);

        pListUsuarios->add(pListUsuarios , puntero);
    }

    pListUsuarios->remove(pListUsuarios , 0);
    return pListUsuarios;
}

void imprimirListaDeUsuarios(ArrayList* pListUsuarios)
{
    int i;
    EUsuario* puntero;

    printf("ID\tNick\t\t\tPopularidad\n\n");

    for(i=0 ; i<pListUsuarios->len(pListUsuarios) ; i++)
    {
        puntero = pListUsuarios->get(pListUsuarios , i);
        printf("%s\t%s\t\t%s\n" , puntero->id_usuario , puntero->nick , puntero->popularidad_usuario);
    }
    system("pause");
    system("cls");
}
