#include <stdio.h>
#include <stdlib.h>
#include <windows.h> //----> utilizo esta libreria para incluir las  variables system, no siempre es necesario, pero es mejor incluirlo

int main()
{
    int cont,num,acum=0;
    float prom;

    for (cont=0; cont<5; cont++)
    {
     printf("\nIngrese un numero"); //-----> el \n es un espacio
     scanf("%i" ,&num); //----->es importante separar los dosparametros por una coma yque el uper andsand este pegado a mi variable. El primer parametro siempre sera la mascara de capa, en el caso de que sea un numero entero, es indistinto poner "%d" o "%i".
     acum= acum + num;
    }
    prom = (float) acum/5; //-----> esto es un casteo, paso el acumulador a flotante ya que al dividirlo, puede dar como resultadoun numero decimal
    printf("El promedio es de: %f",prom);
    system ("pause"); //----> retiene por un momento la informacion en pantalla, tambien puedo utilizar un

    return 0;
}
