#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
  char id;
  char nombre[20];
  char apellido[20];
  char estado[6];
}EDatos;

int loadDataFile(char , EDatos* , int);

#endif
