#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[30];
    int legajo;
    char sexo;
    int edad;
    int estado;
}EEmpleado;

void menu();
void carga(EEmpleado*);
void listar(EEmpleado*);
void informar(EEmpleado*);

#endif
