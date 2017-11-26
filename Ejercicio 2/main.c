#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int cont,num,acum=0,max,min;
    float prom;

    for (cont=0; cont<5; cont++)
    {
     printf("\nIngrese un numero");
     scanf("%d" ,&num);
     system("cls");
     printf ("\n Hola");
     //system("pause");
     //getch();
     //system("cls");

     acum= acum + num;
     if (cont==0 || num>max) //-----> no olvidar que es == y no =
     {
         max = num;
     }
     if (cont==0 || num<min)
     {
         min = num;
     }

    }

    prom = (float) acum/5;
    printf("\nEl promedio es de: %.2f",prom);
    printf("\nEl maximo es :%i",max);
    printf("\nEl minimo es: %i",min);

    //system ("pause");
    getch();

    return 0;
}
