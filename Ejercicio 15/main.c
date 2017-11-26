#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Los multiplos de 6 entre el 0 y el 100 son:");

    for (i=0 ; i>=0 && i<=100 ; i++)
     {
       /* multiplo = 6*i;
        printf(" %d",multiplo);*/
        if (i%6 == 0)
        {
            printf(" %d",i);
        }
     }
    return 0;
}
