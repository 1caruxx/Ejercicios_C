#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[25];
    char edad[5];
    FILE* pFILE;

    pFILE = fopen("C:\\Users\\Telefonica\\Desktop\\Archivos Ejercicio 1\\BIN.dat" , "r");

    if(pFILE == NULL)
    {
        printf("Error, el archivo no ha podido ser leido.\n");
        exit(0);
    }

    while(!feof(pFILE))
    {
        fscanf(pFILE , "%[^,] , %[^,] , %[\n]\n", nombre, edad);
        printf("%s, %s", nombre, edad);
    }

    fclose(pFILE);

    return 0;
}
