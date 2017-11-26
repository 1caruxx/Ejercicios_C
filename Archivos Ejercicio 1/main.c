#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    char seguir;
    int i, longitud = 0;
    FILE* pFILE;
    EEstructura vector[20];
    pFILE = fopen("BIN.DAT" , "r");

    if(pFILE == NULL)
    {
        pFILE = fopen("BIN.DAT" , "w");

        if (pFILE == NULL)
        {
            printf("El archivo no pude ser creado.\n");
            exit(0);
        }
    }

    do
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(vector[longitud].nombre);

        printf("Ingrese la edad: ");
        scanf("%d", &vector[longitud].edad);

        printf("Desea seguir? [Pulse cualquier tecla para continuar, n para salir.]: ");
        fflush(stdin);
        scanf("%c", &seguir);
        longitud++;
    }while(seguir != 'n');

    for(i=0 ; i<longitud ; i++)
    {
        fprintf(pFILE,"Nombre: %s, edad: %d\n", vector[i].nombre, vector[i].edad);
    }

    fclose(pFILE);

    return 0;
}
