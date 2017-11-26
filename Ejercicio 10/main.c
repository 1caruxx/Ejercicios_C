#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,contNegativos=0;
    printf("Los numeros impares entre 0 y 100 son");
    for (i=0 ; i>=0 && i<=100 ; i++)
   {
       if (i%2 != 0)
       {
           printf(" %d",i);
           contNegativos ++;
       }

   }
    printf("\nLa cantidad de numeros impares entre 0 y 100 es de: %d",contNegativos);
    return 0;
}
