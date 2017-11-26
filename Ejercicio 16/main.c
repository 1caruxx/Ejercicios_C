#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    printf("Introduzca un numero: ");
    scanf("%d", &numero);

    if (numero > 0)
     {
      printf("El numero introducido es positivo.");
     }
    if (numero < 0)
     {
      printf("El numero introducido es negativo.");
     }

    return 0;
}
