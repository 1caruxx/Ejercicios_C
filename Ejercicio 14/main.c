#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, acum;
    i = 3;
    do
    {
        printf("%d",i);
        i += 3;// es lo mismo que escribir i = i
        acum += i;

    }while (i<100);
    printf("Datos acumulados: %i",acum);
    system ("pause");

    return 0;
}
