#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float num1,num2,resta;

    printf("Ingrese el primer valor: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo valor: ");
    scanf("%f", &num2);

    resta = num1 - num2;
     if (resta == 0)
     {
         printf("El resultado de la resta entre los dos valores ingresados es 0.");
     }
     else
     {
         if (resta > 0)
         {
            printf("El resultado de la resta entre los dos valores ingresados es positivo.");
         }
         else
            printf("El resultado de la resta entre los dos valores ingresados es negativo.");
     }

    return 0;
}
