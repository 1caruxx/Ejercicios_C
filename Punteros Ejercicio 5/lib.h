#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int codigo;
    int stock;
    float precio;
}EMedicamento;

void menu();
void carga(EMedicamento*);

#endif
