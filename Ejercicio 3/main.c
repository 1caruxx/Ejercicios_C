#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    float num1,num2;

    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    while (num1==0)
    {
        printf("El valor debe ser distinto a cero, reingrese el numero:");
        scanf("%f", &num1);
    }
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
        while (num2==0)
    {
        printf("El valor debe ser distinto a cero, reingrese el numero:");
        scanf("%f", &num2);
    }

    printf("El producto de los dos numeros ingresados es: %f\n",num1*num2);
    printf("El cuadrado del primer numero ingresado es: %f",num1*num1);

    return 0;
}
