#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "Arraylist.h"
#define LONGITUD 10

void menu(void)
{
    FILE* pFileUsuario;
    FILE* pFileTemas;
    ArrayList* pListUsuarios;
    ArrayList* pListTemas;
    EUsuario* pElementUsuario;
    char seguir='s';
    int opcion;
    int i;
    /*int flag=0;
    int contador=0;*/

    pListUsuarios = al_newArrayList();
    pListTemas = al_newArrayList();

    if(pListUsuarios==NULL || pListTemas==NULL)
    {
        printf("No hay suficiente espacio en memoria para crear las listas.\n");
        exit(1);
    }

    /*pFileUsuario = fopen("usuarios.dat" , "r");
    pFileTemas = fopen("temas.dat" , "r");*/

    /*if(pFileUsuario==NULL || pFileTemas==NULL)
    {
        printf("No se ha podido abrir algunos de los archivos.\n");
        exit(1);
    }

    while(!feof(pFileUsuario))
    {
        if(flag ==  0)
        {
            flag = 1;
            continue;
        }

        pElementUsuario = user_newUsuario();
        fread(pElementUsuario , sizeof(EUsuario) , 1 , pFileUsuario);
        pListUsuarios->add(pListUsuarios , pElementUsuario);
    }*/
    /*if(leerArchivoB(pFileUsuario , "usuarios.dat" , sizeof(EUsuario))==-1 || leerArchivoB(pFileTemas , "temas.dat" , sizeof(ETema))==-1)
    {
        printf("error, no se a podido abrir el archivo o leer alguno de sus elementos.\n");
        exit(1);
    }*/

    pElementUsuario = (EUsuario*) leerArchivoB(pFileUsuario , "usuarios.dat" , sizeof(EUsuario));

    if(pElementUsuario == NULL)
    {
        printf("error, no se a podido abrir el archivo o leer alguno de sus elementos.\n");
        printf("%p", *pFileUsuario);
        //fclose(pFileUsuario);
        /*exit(0);*/return 0;
    }

    while(!feof(pFileUsuario))
    {
        pListUsuarios->add(pListUsuarios , pElementUsuario+i);
        i++;
    }

    do
    {
        printf("\t\t\t\t\t Espacio en memoria ocupado: %d / %d \n", pListUsuarios->size, pListUsuarios->reservedSize);
        printf("1- Listar usuarios.\n");
        printf("2- Listar temas.\n");
        printf("3- Escuchar tema.\n");
        printf("4- Guardar estadistica.\n");
        printf("5- Informar.\n");
        printf("6- Salir\n\n");
        printf("Elija una de las opciones: ");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
              printf("Como desea ordenar a los usuarios?\n");
              printf("1- Solo por nombre.\n");
              printf("2- Por nacionalidad y nombre.\n");
              printf("3- Cancelar.\n\n");
              printf("Elija una de las opciones: ");

              fflush(stdin);
              scanf("%d", &opcion);

              switch(opcion)
              {
                  case 1:
                    //pListUsuarios->sort(pListUsuarios , user_compareNombre , 0);
                    user_print(pListUsuarios , pElementUsuario);
                    break;

                  case 2:
                    break;

                  case 3:
                    printf("Operacion abortada.\n");
                    break;

                  default:
                    printf("Error, valor ingresado no valido");
              }
              break;

            case 2:
              break;

            case 3:
              break;

            case 4:
              break;

            case 5:
              break;

            case 6:
              seguir = 'n';
              break;

            default:
                printf("Error, reingrese.\n");
        }

        system("pause");
        system("cls");

    } while(seguir=='s');

}

EUsuario* user_newUsuario(void)
{
        EUsuario* pEst = (EUsuario*) malloc(sizeof(EUsuario));

        if(pEst != NULL)
        {
            return pEst;
        }

    return NULL;
}

void user_print(ArrayList* pList , EUsuario* pElement)
{
    int i;

    printf("ID\t\tNacionalidad\t\tNombre\t\tSexo\n\n");

    for(i=0 ; i<pList->size ; i++)
    {
        if(i%200 == 0)
        {
            system("pause");
        }
        pElement = (EUsuario*) pList->get(pList , i);
        printf("%d\t\t%s\t\t%s\t\t%s\n", pElement->id, pElement->pais, pElement->nombre, pElement->sexo);
    }
}

int user_compareNombre(void* pElement , void* pElement2)
{
    int retorno=0;

    if(strcmp(((EUsuario*)pElement)->nombre , ((EUsuario*)pElement2)->nombre)>0)
    {
        retorno = 1;
    }

    return retorno;
}

void* leerArchivoB(FILE* pFILE, const char* archivo , int tamanio)
{
    int i=0, incremento=2, cant;
    void* puntero = malloc(tamanio);
    pFILE = fopen(archivo , "rb");

    if(pFILE != NULL)
    {
        while(!feof(pFILE))
        {
            printf("feof de la funcion [%d]\n", i);
            cant = fread(puntero+i , tamanio , 1 , pFILE);

            if(cant == 1)
            {
                puntero = realloc(puntero , tamanio*incremento);
                i++;
                incremento++;
            }
            else
            {
                printf("No se ha leido un elemento.\n");
                return NULL;
            }
        }
    }
    else
    {
        return NULL;
    }

    return puntero;
}
