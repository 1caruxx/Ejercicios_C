#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,max,flag=0;

    for(i=0 ; i<3 ; i++)
    {
        printf("Ingrese un numero [%d/3]: ",i+1);
        scanf("%d", &num);

        if (num>max || flag == 0)
        {
            max = num;
            flag = 1;
        }
    }
    printf("El mayor de los numeros introducidos es el: %d",max);
    return 0;
}
