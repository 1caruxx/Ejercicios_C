#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int codigo;
    char descripcion[20];
    int categoria;
    float precio;
}eProducto;

/** \brief Abre el archivo "productos.csv" y carga sus elementos en un Arraylist.
 * \param Un puntero al Arraylist (ArrayList*).
 * \param Un puntero a FILE (FILE*).
 * \return Vacio (void).
 */
void abrirArchivoDeProductos(ArrayList* , FILE*);

/** \brief Despliega la lista de los productos.
 * \param Un puntero al Arraylist (ArrayList*).
 * \return No retorna nada (void).
 */
void imprimirListaDeProductos(ArrayList*);

/** \brief Devuelve un nuevo ArrayList cargado con los productos pertenecientes a la categoria indicada por parametro.
 * \param pLista puntero al ArrayList a filtrar.
 * \param cat entero que indica categoria de filtrado.
 * \return Devuelve un nuevo ArrayList cargado con los productos aumentados.
 */
ArrayList* filter(ArrayList*  , int);

/** \brief Devuelve un nuevo ArrayList donde sus productos han sfrido un aumento del precio del porcentaje pasado por parametro.
 * \param pLista puntero al ArrayList a aplicar aumento.
 * \param Porcentaje en que se incrementaran los precios.
 * \return Devuelve un nuevo ArrayList cargado con los productos aumentados.
 */
ArrayList* map(ArrayList*  , float);

/** \brief Devuelve un float que indica la suma de los precios de todos los productos del puntero a ArrayList pasado como parametro.
 * \param pLista puntero al ArrayList a totalizar.
 * \return float Suma acumulada de los precios de todos los productos del ArrayList.
 */
float reduce(ArrayList*);

#endif
