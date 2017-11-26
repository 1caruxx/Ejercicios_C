#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "Arraylist.h"

typedef struct
{
    int id;
    char nombre[31];
    char email[31];
    char sexo[7];
    char pais[21];
    char password[21];
    char ip_address[21];
}EUsuario;

typedef struct
{
    int id;
    char nombre_tema[31];
    char artista[31];
}ETema;

/** \brief Despliega un menu de opciones.
 * \param Vacio (void).
 * \return Vacio (void).
 */
void menu(void);

/** \brief Crea y carga un nuevo elemento del tipo EUsuario.
 * \param Un puntero a FILE (FILE*).
 * \return Retorna un puntero al nuevo elemento (EUsuario*) u nulo (NULL) en caso de error (no se pudo reservar espacio en memoria).
 */
EUsuario* user_newUsuario(void);

/** \brief Despliega una lista de los elementos del tipo EUsuario.
 * \param Un puntero al Arraylist (Arraylist*).
 * \param Un puntero al elemento (void*).
 * \return Vacio (void).
 */
void user_print(ArrayList* , EUsuario*);

/** \brief Compuebra si el primer el nombre del primer parametro es mayor o menor al del segundo.
 * \param Un puntero al elemento (void*).
 * \param Un puntero al elemento (void*).
 * \return Retorna un entero (1) en caso de que el primer elemento sea menor al segundo o (0) en caso contrario.
 */
int user_compareNombre(void* , void*);

void* leerArchivoB(FILE* , const char* , int);

#endif
