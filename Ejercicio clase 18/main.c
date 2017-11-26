#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    char auxiliar[30];
    EDatos* vector = (EDatos*) malloc(sizeof(EDatos));

    printf("Ingrese el nombre del archivo: ");
    scanf("%s", &auxiliar);
    loadDataFile(auxiliar, vector, 1);
    return 0;
}
