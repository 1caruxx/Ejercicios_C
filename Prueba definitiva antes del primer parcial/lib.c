#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define LONGPELICULA 10
#define LONGDIRECTOR 5

void estilizarArrayDeChars(char array[] , int longitud)
{
    int i;

    strlwr(array);
    array[0] = toupper(array[0]);
    for(i=0 ; i<longitud ; i++)
    {
        if(array[i] == ' ')
        {
            array[i+1] = toupper(array[i+1]);
        }
    }
}

void menu(void)
{
    char seguir='s';
    int opcion;
    EPeliculas pelicula[LONGPELICULA];
    EDirectores director[LONGDIRECTOR];

    do
    {
        printf("1- Dar de alta una pelicula\n");
        printf("2- Modificar datos de una pelicula\n");
        printf("3- Dar de baja una pelicula\n");
        printf("4- Dar de alta un director\n");
        printf("5- Dar de baja un director\n");
        printf("6- informar el director con ams peliculas\n");
        printf("7- Listar\n");
        printf("8- Salir\n\n");
        printf("Elija una de las opciones: ");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
              alta(pelicula , LONGPELICULA);
              break;

            case 2:
              modificacion(pelicula , LONGPELICULA);
              break;

            case 3:
              baja(pelicula , LONGPELICULA);
              break;

            case 4:
              nuevoDirector (pelicula , LONGPELICULA);
              break;

            case 5:
              break;

            case 6:
              break;

            case 7:
              listar(pelicula , LONGPELICULA);
              break;

            case 8:
              seguir = 'n';
              break;

            default:
                printf("Error, reingrese.\n");
        }

        system("pause");
        system("cls");

    } while(seguir=='s');

}

void alta(EPeliculas dato[] , int longitud)
{
   int i, contador=0;

   for (i=0 ; i<longitud ; i++)
   {
      if (dato[i].estado != 1)
      {
          printf("Ingrese el titulo: ");
          fflush(stdin);
          gets(dato[i].titulo);
          estilizarArrayDeChars(dato[i].titulo , longitud);

          printf("Ingrese el año de estreno: ");
          scanf("%d", &dato[i].anio);

          printf("Ingrese la nacionalidad: ");
          fflush(stdin);
          gets(dato[i].nacionalidad);
          estilizarArrayDeChars(dato[i].nacionalidad , longitud);

          printf("Ingrese el director: ");
          fflush(stdin);
          gets(dato[i].director.nombre);
          estilizarArrayDeChars(dato[i].director.nombre , longitud);
          dato[i].director.id = i;

          printf("Ingrese el codigo: ");
          scanf("%d", &dato[i].codigo);
          dato[i].estado = 1;
          break;
      }

      else
      {
          contador++;
      }
   }
   if(contador == longitud)
   {
      printf("No hay espacio disponible en el vector.\n");
   }
}

void nuevoDirector (EDirectores director[] , int longitud)
{
   int i, j, contador=0;
   char auxiliar[30];

   printf("Ingrese el nombre del nuevo director: ");
   fflush(stdin);
   gets(auxiliar);

   for(i=0 ; i<longitud ; i++)
   {
       if(strcmp(auxiliar , director[i].nombre) == 0)
       {
           printf("Este director ya existe.\n");
           return;
       }
   }

   for(j=0; j<longitud ; j++)
   {
      if (director[i].estado != 1)
      {

        estilizarArrayDeChars(auxiliar , 30);
        strcpy(director[i].nombre , auxiliar);

        printf("Ingrese la fecha de nacimiento:\n");
        printf("Dia: \n");
        scanf("%d", &director[i].nacimiento.dia);
        printf("Mes: \n");
        scanf("%d", &director[i].nacimiento.mes);
        printf("Año: \n");
        scanf("%d", &director[i].nacimiento.anio);


        printf("Ingrese el pais de origen: ");
        fflush(stdin);
        gets(director[i].paisDeOrigen);
        estilizarArrayDeChars(director[i].paisDeOrigen , longitud);

        director[i].id = i;

        director[i].estado = 1;
        break;
      }

      else
      {
         contador++;
      }
   }

   if(contador == longitud)
   {
      printf("No hay espacio disponible en el vector.\n");
   }
}

int buscarPorIdentificardorUnivoco (EPeliculas dato[], int longitud)
{
    int i, auxiliar, flag=0;

    printf("Ingrese el codigo de la pelicula: ");
    scanf("%d", &auxiliar);

    for (i=0 ; i<longitud ; i++)
    {
        if(dato[i].estado==1 && auxiliar==dato[i].codigo)
        {
            return i;
        }
    }

    if(flag == 0)
    {
        printf("El codigo introducido hace referencia a una pelicula inexistente\n");
        return -1;
    }
}

void modificacion(EPeliculas dato[] , int longitud)
{
    int posicion, opcion;

    posicion = buscarPorIdentificardorUnivoco (dato, longitud);

    if(posicion == -1)
    {
        return;
    }

    printf("Codigo\t\tTitulo\t\t\tNacionalidad\n");
    printf("%d\t%s\t\t%s\n", dato[posicion].codigo, dato[posicion].titulo, dato[posicion].nacionalidad);

    printf("%cQue parametro desea modificar?\n",168);
    printf("1- Titulo\n");
    printf("2- Anio\n");
    printf("3- Nacionalidad\n");
    printf("4- Director\n");
    printf("5- Cancelar\n");
    printf("Seleccione una de las opciones: ");

    fflush(stdin);
    scanf("%d", &opcion);

    switch (opcion)
    {
       case 1:
         printf("Ingrese el nuevo titulo: ");
         fflush(stdin);
         gets(dato[posicion].titulo);
         estilizarArrayDeChars(dato[posicion].titulo , 26);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 2:
         printf("Ingrese el nuevo anio: ");
         scanf("%d", &dato[posicion].anio);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 3:
         printf("Ingrese la nueva nacionalidad: ");
         fflush(stdin);
         gets(dato[posicion].nacionalidad);
         estilizarArrayDeChars(dato[posicion].nacionalidad , 26);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 4:
         printf("Ingrese el nuevo director: ");
         fflush(stdin);
         gets(dato[posicion].director.nombre);
         estilizarArrayDeChars(dato[posicion].director.nombre , 26);
         printf("Se ha modificado correctamente el dato\n");
         break;

       case 5:
         printf("Operacion abortada\n");
         break;

       default:
         printf("Opcion ingresada no valida\n");
    }
}

void baja(EPeliculas dato[] , int longitud)
{
    char opcion;
    int posicion;
    posicion = buscarPorIdentificardorUnivoco (dato, longitud);

    if(posicion == -1)
    {
        return;
    }

    printf("Codigo\t\tTitulo\t\t\t\tNacionalidad\n");
    printf("%d\t\t%s\t\t\t%s\n", dato[posicion].codigo, dato[posicion].titulo, dato[posicion].nacionalidad);

    printf("%cDesea dar de baja a esta pelicula? [s/n]: ", 168);
    fflush(stdin);
    scanf("%c", &opcion);

    switch (opcion)
    {
       case 's':
       dato[posicion].estado = 0;
       printf("Se ha dado de baja la pelicula\n");
       break;

       case 'n':
       printf("Operacion abortada\n");
       break;

       default:
       printf("Error, valor ingresado no valido\n");
    }
}


void listar(EPeliculas dato[] , int longitud)
{
    int i,contador=0;

    printf("Nombre\t\t\tDirector\t\tNacionalidad\n");

    for(i=0 ; i<longitud ; i++)
    {
      if(dato[i].estado == 1)
      {
        printf("%s\t\t\t%s\t\t%s\n", dato[i].titulo, dato[i].director.nombre, dato[i].nacionalidad);
      }
      else
      {
          contador++;
      }
    }

    if(contador == longitud)
    {
        printf("No se ha cargado ningun dato.\n");
    }
}
