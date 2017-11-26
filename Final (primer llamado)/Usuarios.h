#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    char id_usuario[5];
    char nick[20];
    char popularidad_usuario[10];
}EUsuario;

/** \brief Abre el archivo "Usuarios.csv" y carga sus elementos en un Arraylist.
 * \param Un puntero al Arraylist (ArrayList*).
 * \param Un puntero a FILE (FILE*).
 * \return Un puntero al Arralist (ArrayList*).
 */
ArrayList* abrirArchivoDeUsuarios(ArrayList* , FILE*);

/** \brief Despliega la lista de Usuarios.
 * \param Un puntero al Arraylist (ArrayList*).
 * \return No retorna nada (void).
 */
void imprimirListaDeUsuarios(ArrayList*);

#endif
