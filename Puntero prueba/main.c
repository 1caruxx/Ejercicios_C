#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    int numero;
}EEstructura;

int main()
{
    EEstructura estructura;
    EEstructura* p;
    p = &estructura;

    p->numero = 3;

    printf("%d", p->numero);





   // printf("%d -- %d", *a, b);
    return 0;
}
