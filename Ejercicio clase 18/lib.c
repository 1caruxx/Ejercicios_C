#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int loadDataFile(char file_name, EDatos* dato, int longitud)
{
    int i=0;
    EDatos* pAUXILIAR;
    FILE* pFILE;
    pFILE = fopen(file_name , "r");

    if(pFILE == NULL)
    {
        printf("El archivo no pudo ser abierto.\n");
        exit(0);
    }

    while(!feof(pFILE))
    {
        fscanf(pFILE , "%[^,],%[^,],%[^,],%[^\n]", (*(dato+i)).id , (*(dato+i)).nombre , (*(dato+i)).apellido , (*(dato+i)).estado);
        i++;
        if(i == longitud)
        {
            pAUXILIAR = (EDatos*) realloc(&dato , sizeof(EDatos)*i+1);
            longitud++;
        }

        if(pAUXILIAR == NULL)
        {
            printf("No se pudo redimensionar la memoria.\n");
            exit(0);
        }
        else
        {
            dato = pAUXILIAR;
        }
    }

    for (i=0 ; i<longitud ; i++)
    {
        printf("ID: %c, Apellido: %s, Nombre: %s, Estado: %s\n",(*(dato+i)).id , (*(dato+i)).apellido, (*(dato+i)).nombre, (*(dato+i)).estado);
    }

    fclose(pFILE);


}
