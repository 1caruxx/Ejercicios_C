#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    char id_mensaje[5];
    char id_usuario[5];
    char popularidad_mensaje[10];
    char mensaje[1800];
}EMensaje;

typedef struct
{
    char id_usuario[5];
    char nick[20];
    char popularidad_usuario[10];
}EUsuario;

typedef struct
{
    char id_mensaje[5];
    char mensaje[1800];
    char popularidad_mensaje[10];
    char id_usuario[5];
    char nick[20];
    char popularidad_usuario[10];
}EFeed;

/** \brief
 * \param
 * \return
 */

#endif
