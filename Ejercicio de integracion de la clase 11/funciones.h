#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codigo, cantidad, estado;
    char nombre [50];
    float importe;
}EProducto;

void cargarProducto(EProducto[] , int);

void modificarProducto(EProducto[] , int);

#endif

