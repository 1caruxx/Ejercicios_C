#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Mensajes.h"
#include "Usuarios.h"
#include "Feed.h"

int main()
{
    FILE* pFILEmensajes;
    FILE* pFILEusuarios;
    FILE* pFILEfeed;
    ArrayList* pListMensajes;
    ArrayList* pListUsuarios;
    ArrayList* pListFeed;

    pListMensajes = abrirArchivoDeMensajes(pListMensajes , pFILEmensajes);
    imprimirListaDeMensajes(pListMensajes);

    pListUsuarios = abrirArchivoDeUsuarios(pListUsuarios , pFILEusuarios);
    imprimirListaDeUsuarios(pListUsuarios);

    pListFeed = crearFeed(pListFeed , pListUsuarios , pListMensajes);
    imprimirFeed(pListFeed);

    pListFeed->sort(pListFeed , criterioDeOrdenamiento , 1);
    printf("-----------------------------------------------------------\n");
    printf("                         Lista ordenada                    \n");
    printf("-----------------------------------------------------------\n");
    imprimirFeed(pListFeed);

    guardarFeed(pFILEfeed, pListFeed);

    return 0;
}
