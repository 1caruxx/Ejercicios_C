#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1,num2,acum;
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    acum = num1 + num2;
    printf("El resultado de la suma es: %f",acum);

    return 0;
}
