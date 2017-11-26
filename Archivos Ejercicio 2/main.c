#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LONGITUD 3

int main()
{
    FILE* pFILE;
    EEstructura vector[LONGITUD];
    int i;

    pFILE = fopen("./BIN.dat" , "rb");

    if(pFILE == NULL)
    {
        pFILE = fopen ("./BIN.dat" , "wb");

        if(pFILE == NULL)
        {
            printf("No se pudo crear el archivo.\n");
            exit(0);
        }
    }

    for(i=0 ; i<LONGITUD ; i++)
    {
        printf("Ingrese el nombre: [%/]");
        fflush(stdin);
        gets(vector[i].nombre);

        printf("Ingrese la edad: ");
        scanf("%d", &vector[i].edad);
    }

    fwrite(vector , sizeof(EEstructura) , 1 , pFILE);

    fclose(pFILE);

    return 0;
}
