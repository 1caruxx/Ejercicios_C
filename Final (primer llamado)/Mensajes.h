#ifndef MENSAJES_H_INCLUDED
#define MENSAJES_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    char id_mensaje[5];
    char id_usuario[5];
    char popularidad_mensaje[10];
    char mensaje[1800];
}EMensaje;

/** \brief Abre el archivo "Mensajes.csv" y carga sus elementos en un Arraylist.
 * \param Un puntero al Arraylist (ArrayList*).
 * \param Un puntero a FILE (FILE*).
 * \return Un puntero al Arralist (ArrayList*).
 */
ArrayList* abrirArchivoDeMensajes(ArrayList* , FILE*);

/** \brief Despliega la lista de mensajes.
 * \param Un puntero al Arraylist (ArrayList*).
 * \return No retorna nada (void).
 */
void imprimirListaDeMensajes(ArrayList*);

#endif
