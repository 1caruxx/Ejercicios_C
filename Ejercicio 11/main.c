#include <stdio.h>
#include <stdlib.h>

int main()
{
 int i,contPares=0;
    printf("Los numeros pares entre 0 y 100 son:");
    for (i=0 ; i>=0 && i<=100 ; i++)
   {
       if (i%2 == 0)
       {
           printf(" %d",i);
           contPares ++;
       }
   }
}
