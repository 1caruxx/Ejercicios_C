#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,contA=0,contE=0,contI=0,contO=0,contU=0;
    char caracter;

    for (i=0 ; i<20 ; i++)
    {
        printf("Ingrese un caracter [%d de 20]: ",i+1);
        caracter = tolower(getche());

        switch (caracter)
        {
           case 'a':
               contA ++;
               break;

            case 'e':
               contE ++;
               break;

            case 'i':
               contI ++;
               break;

            case 'o':
               contO ++;
               break;

            case 'u':
               contU ++;

        }

       system("cls");

    }

    printf("La cantidad de 'a' introducidas es: %d\nLa cantidad de 'e' introducidas es: %d\nLa cantidad de 'i' introducidas es: %d\nLa cantidad de 'o' introducidas es: %d\nLa cantidad de 'o' introducidas es: %d\n",contA,contE,contI,contO,contU);

    return 0;
}


