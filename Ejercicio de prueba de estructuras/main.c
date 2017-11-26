/*1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes
datos (utilizar una estructura para representar a la persona.):
Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.

b- Mostrar un listado ordenado por Apellido*/
#include <stdio.h>
#include <stdlib.h>

/*typedef struct
{
    char nombre [30];
    char apellido [30];
    int legajo;
}persona;*/

int main()
{
    persona tipo1;
    strcpy(tipo1.nombre,"Juan Carlos");
    strcpy(tipo1.apellido,"Mendez");
    tipo1.legajo = 145;
    printf("Apellido y nombre: %s",tipo1.apellido,tipo1.nombre);
    return 0;
}
