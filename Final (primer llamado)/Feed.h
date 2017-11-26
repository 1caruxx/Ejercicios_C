#ifndef FEED_H_INCLUDED
#define FEED_H_INCLUDED

typedef struct
{
    char id_mensaje[5];
    char mensaje[1800];
    char popularidad_mensaje[10];
    char id_usuario[5];
    char nick[20];
    char popularidad_usuario[10];
}EFeed;

/** \brief Crear la lista "Feed" en base a los elementos de las listas: Usuarios y Mensajes.
 * \param Un puntero al Arraylist (ArrayList*).
 * \param Un puntero al Arraylist (ArrayList*).
 * \param Un puntero al Arraylist (ArrayList*).
 * \return Un puntero al Arraylist (ArrayList*).
 */
 ArrayList* crearFeed(ArrayList* , ArrayList* , ArrayList*);

/** \brief Despliega la lista "Feed".
 * \param Un puntero al Arraylist (ArrayList*).
 * \return No retorna nada (void).
 */
void imprimirFeed(ArrayList*);

/** \brief Estable el criterio de ordenamiendo de los elementos de la lista "Feed".
 * \param Un puntero al tipo de elemento Feed (EFeed*).
 * \param Un puntero al tipo de elemento Feed (EFeed*).
 * \return Retorna un entero (int).
 */
int criterioDeOrdenamiento(EFeed* pElement , EFeed* pElement2);

/** \brief
 * \param
 * \param
 * \return
 */
void guardarFeed(FILE* , ArrayList*);

#endif
