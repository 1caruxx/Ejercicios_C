#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int  dia, mes, anio;
}EFecha;

typedef struct
{
    char nombre[30], paisDeOrigen[30];
    EFecha nacimiento;
    int  id, estado;
}EDirectores;

typedef struct
{
    char titulo[30], nacionalidad[30];
    int  codigo, estado, anio;
    EDirectores director;
}EPeliculas;

void estilizarArrayDeChars (char[] , int);
void menu(void);
void alta (EPeliculas[] , int);
void nuevoDirector (EDirectores[] , int);
int buscarPorIdentificardorUnivoco (EPeliculas[] , int);
void baja (EPeliculas[] , int);
void eliminarDirector (EDirectores[] , int);
void modificar (EPeliculas[] , int);
void ordenamientoMedianteBurbujeo (EPeliculas[] , int);
void listar (EPeliculas[] , int);

#endif
