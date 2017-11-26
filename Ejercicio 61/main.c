/*Una persona desea saber en qué día del mes realizó más gastos en compras, para ello ingresa por teclado
día a día lo que gastó por día, cargando un vector definido en memoria. Puede haber varias o ninguna
compra para un determinado día. Informar cual fue el día de mayor gasto*/
#include <stdio.h>
#include <stdlib.h>
#define constante 30

int main()
{

    int i,dia,vector[constante],suma,max,flag=0,diaMaximo;
    char rta1 [2] = "si",rta2 [2] = "si";

    for(i=0 ; i<constante ; i++)
    {
        vector [i] = 0;
    }
    do
    {
        printf("Ingrese el dia: ");
        scanf("%d", &dia);
        printf("Ingrese el monto: ");
        scanf("%d", &vector[dia]);
        suma += vector[dia];
        printf("¿Desea sumarle otra compra?[si/no]: ");
        scanf("%s", rta1);
        while (strcmp(rta1,"si")==0)//(strcmp(texto,"1234")==0)
        {
            printf("Ingrese otro monto: ");
            scanf("%d", &vector[dia]);
            suma += vector[dia];
            printf("¿Desea sumarle otra compra?[si/no]: ");
            scanf("%s", rta1);
        }
        vector[dia] = suma;
        printf("¿Desea ingresar las compras de otro dia? [si/no]");
        scanf("%s", rta2);

        if (vector [dia]>max || flag==0)
        {
            max = vector [dia];
            diaMaximo = dia;
            flag = 1;
        }

    } while(strcmp(rta2,"si")==0);

    printf("El dia en el cual mas gasto fue el: %d, con un total de: %d",diaMaximo,vector [diaMaximo]);

    return 0;
}
