#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor;
    printf("Ingrese un valor: ");
    scanf ("%f", &valor);

    if (valor <= 0)
    {
        printf("ERROR, el número debe ser mayor que cero");
        return 0;
    }

    printf("El cuadrado del numero ingresado es: %f", valor*valor);


    return 0;
}
