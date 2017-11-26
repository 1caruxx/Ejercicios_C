#include <stdio.h>
#include <stdlib.h>

void modificacion(int*);

int main()
{
    int* i;
    int *j;
    int numero;

    numero = 8;

    printf("%p\n", i);
    printf("%d\n", i);
    printf("%p\n", j);
    printf("%d\n", j);

    i = numero;
    j = numero;

    printf("%d\n", i);
    printf("%d\n", j);

    i = &numero;

    printf("%d\n", i);
    printf("%p\n", i);
    printf("%c\n", i);
    printf("%d\n", *i);
    printf("%d\n", *(i));
    printf("%d\n", (*i));
    printf("%p\n", *i);

    i = j;

    printf("%d\n", i);
    printf("%p\n", i);

    j = NULL;

    printf("%d\n", j);

    printf("%d\n", &numero);
    printf("%p\n", &numero);

    modificacion(&numero);

    printf("%d\n", numero);
    printf("%d\n", &numero);

    return 0;
}

void modificacion(int* numero)
{
    *numero = 6;
     numero = 2;
}
