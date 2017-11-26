#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,inversion1,inversion2;

    printf("Introduzca un valor a num1: ");
    scanf("%d", &num1);
    inversion1 = num1;

    printf("Introduzca un valor a num2: ");
    scanf("%d", &num2);
    inversion2 = num2;

    num1 = inversion2;
    num2 = inversion1;

    printf("num1: %d\nnum2: %d",num1,num2);

    return 0;
}
