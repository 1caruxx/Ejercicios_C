#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char nombre,nomMax,apellido,apeMax,rta; //Si no trabajasemos con un do while, tendriamos que aignarle un valor a rta
    int cont=0;
    float altMax,altura;

    do //------> es mas rentable usar do while por que al menos un alumno se va a cvargar
    {
        system("cls"); //----> para limpiar la pantalla, asi solo me quede con el dialogo actual, por cada bloque dialogo limpia la pantalla
        printf("Introduzca el nombre del alumno");
        fflush(stdin); //------> el enter es un caracter, esto limpia lo que haya en el buffer (espacio en memoria donde se guardan los caracteres para luiego mostrarloos) y asi evitamos que el texto nos salga separado. Si son datos numericos no es necesario usarlo
        scanf("%c",&nombre);
        printf("Ingrese el apellido")
        fflush(stdin);
        scanf("%c",apellido);

        do
        {
            printf("ingrese la altura");
            scanf("%f",&altura)
        }while(altura<=0);//------> esto es la validacion de la altura, si es menor o igual a 0, volvera al printf("ingrese la altura"); los do while si terminan con ;

        if(flag==0 || altura>altMax) //-----> creo una bandera para sacar el maximo
        {
            altMax = altura;
            nomMax = nombre;
            apeMax = apellido;
        }
       do{
       printf("Desea continuar[s/n]");
       fflush(stdin);
       scanf("%c",&rta);
       seguir = tolower(seguir); // -----> pasa cualquier caracter a minuscula, tuopper por el contrario pasa cualquier caracter a mayuscula
       }while(seguir != 's'&& !='n');

    }while(rta=='s'); //----> esto sirve para que se siga iteran cuando hasta que el usuario diga que si, si rta es una s volver al primer do y volvera a ejecutar todas las sentencias
    system("els"); // limpio la pantalla
    printf("Nombre: %c\nApellido: %c\nAltura: %2f",nomMax,apeMax,altMax); //----> muestro todo
    system("pause"); //-----> tambien se puede hacer con getch ();

    return 0;
}
//isalpha ------> es un caracter, si es, devuelve un 1, si no lo es, devuelve un 0
//isdigit-------> lo mismo que is alpha, pero con un numero
