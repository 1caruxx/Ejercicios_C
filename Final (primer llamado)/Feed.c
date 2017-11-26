#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Mensajes.h"
#include "Usuarios.h"
#include "Feed.h"

ArrayList* crearFeed(ArrayList* pListFeed, ArrayList* pListUsuarios, ArrayList* pListMensajes)
{
    int i, j;
    EFeed* punteroAuxiliarFeed;
    EMensaje* punteroAuxiliarMensaje;
    EUsuario* punteroAuxiliarUsuario;

    pListFeed = al_newArrayList();

    printf("declaradas las variable de crear feed\n");

    for(i=0 ; i<pListMensajes->len(pListMensajes) ; i++)
    {
        printf("Entrada al for\n");
        punteroAuxiliarFeed = (EFeed*) malloc(sizeof(EFeed));
        punteroAuxiliarMensaje = pListMensajes->get(pListMensajes , i);

        strcpy(punteroAuxiliarFeed->id_mensaje , punteroAuxiliarMensaje->id_mensaje);
        strcpy(punteroAuxiliarFeed->mensaje , punteroAuxiliarMensaje->mensaje);
        strcpy(punteroAuxiliarFeed->popularidad_mensaje , punteroAuxiliarMensaje->popularidad_mensaje);
        strcpy(punteroAuxiliarFeed->id_usuario , punteroAuxiliarMensaje->id_usuario);

        printf("%s\n" , punteroAuxiliarFeed->id_usuario);
        //system("pause");

        printf("se asignaron los campos\n");
        for(j=0 ; j<pListUsuarios->len(pListUsuarios) ; j++)
        {
            punteroAuxiliarUsuario = pListUsuarios->get(pListUsuarios , j);
            printf("entrada al for para comprar id de usuarios\n");
            if((strcmp(punteroAuxiliarMensaje->id_usuario , punteroAuxiliarUsuario->id_usuario)) == 0)
            {
                printf("entrada al if\n");

                strcpy(punteroAuxiliarFeed->nick , punteroAuxiliarUsuario->nick);
                strcpy(punteroAuxiliarFeed->popularidad_usuario , punteroAuxiliarUsuario->popularidad_usuario);

                printf("se copio el nick y la popularidad del usuario\n");
                break;
            }
        }

        printf("justo antes de hacer el add\n");
        printf("%s\t%s\t%s\t%s\t%s\n" , punteroAuxiliarFeed->id_mensaje , punteroAuxiliarFeed->popularidad_mensaje , punteroAuxiliarFeed->id_usuario , punteroAuxiliarFeed->nick , punteroAuxiliarFeed->popularidad_usuario /*puntero->mensaje*/);

        pListFeed->add(pListFeed , punteroAuxiliarFeed);
        printf("se hizo el add\n");
    }
    printf("A punto de retornar\n");

    return pListFeed;
}

void imprimirFeed(ArrayList* pListFeed)
{
    int i;
    EFeed* puntero;

    printf("ID (mensaje)\tPopularidad (mensaje)\tID (usuario)\tNick\tPopularidad (usuario)\n\n");

    for(i=0 ; i<pListFeed->len(pListFeed) ; i++)
    {
        puntero = pListFeed->get(pListFeed , i);
        printf("%s\t%s\t%s\t%s\t%s\n" , puntero->id_mensaje , puntero->popularidad_mensaje , puntero->id_usuario , puntero->nick , puntero->popularidad_usuario /*puntero->mensaje*/);
    }
    system("pause");
    system("cls");
}

int criterioDeOrdenamiento(EFeed* pElement , EFeed* pElement2)
{
    int auxiliar, auxiliar2, retorno;

    auxiliar = atoi(pElement->popularidad_mensaje);
    auxiliar2 = atoi(pElement2->popularidad_mensaje);

    if(auxiliar > auxiliar2)
    {
        retorno = 1;
    }
    else
    {
        if(auxiliar < auxiliar2)
        {
            retorno = 0;
        }
        else
        {
            auxiliar = atoi(pElement->popularidad_usuario);
            auxiliar2 = atoi(pElement2->popularidad_usuario);

            if(auxiliar > auxiliar2)
            {
                retorno = 1;
            }
            else
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

void guardarFeed(FILE* pFILEfeed, ArrayList* pListFeed)
{
    int i;
    EFeed* puntero;

    pFILEfeed = fopen("feed.doc" , "w");

    if(pFILEfeed == NULL)
    {
        printf("No se ha podido crear el archivo.\n");
        exit(1);
    }

    fprintf(pFILEfeed , "id_usuario,nick,popularidad_usuario,id_mensaje,popularidad_mensaje,mensaje\n");

    for(i=0 ; i<pListFeed->len(pListFeed) ; i++)
    {
        puntero = pListFeed->get(pListFeed , i);
        fprintf(pFILEfeed , "%s,%s,%s,%s,%s\n" , puntero->id_usuario , puntero->nick , puntero->popularidad_usuario , puntero->id_mensaje , puntero->popularidad_mensaje/* , puntero->mensaje*/);
    }
}

