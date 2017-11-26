#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#define VALOR_INICIAL 10
#define INCREMENTO 10

ArrayList* al_newArrayList(void)
{
    ArrayList* pList = (ArrayList*) malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pList->pElements = malloc(sizeof(void*)*VALOR_INICIAL);

        if(pList->pElements != NULL)
        {
            pList->size = 0;
            pList->reservedSize = VALOR_INICIAL;

            pList->add = al_add;
            //pList->len = al_len;
            //pList->contains = al_contains;
            //pList->set = al_set;
            //pList->remove = al_remove;
            //pList->clear = al_clear;
            //pList->push = al_push;
            //pList->indexOf = al_indexOf;
            //pList->isEmpty = al_isEmpty;
            pList->get = al_get;
            //pList->pop = al_pop;
            //pList->containsAll = al_containsAll;
            pList->sort = al_sort;
            //pList->clone = al_clone;
            //pList->subList = al_subList;
            //pList->deleteArrayList = al_deleteArrayList;

            return pList;
        }
    }

    free(pList);

    return NULL;
}

int al_add(ArrayList* pList , void* pElement)
{
    int retorno=-1, espacioLibre=1;

    if(pList!=NULL && pElement!=NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            if(resizeUp(pList) != 0)
            {
                printf("No se a podido redimenzionar memoria.\n");
                espacioLibre = 0;
            }
        }

        if(espacioLibre != 0)
        {
            *(pList->pElements + (pList->size)) = pElement;
            pList->size++;

            retorno = 0;
        }
    }

    return retorno;
}

void* al_get(ArrayList* pList , int index)
{
    if(pList!=NULL && index>=0 && index<pList->size)
    {
        return *(pList->pElements+index);
    }
    else
    {
        return NULL;
    }
}

int al_sort(ArrayList* pList , int (*pFunc)(void* , void*) , int order)
{
    int i, j, retorno=-1;
    void* pAuxiliar;

    if(pList!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        if(order)
        {
            for(i=0 ; i<pList->size-1 ; i++)
            {
                for(j=i+1 ; j<pList->size ; j++)
                {
                    if(pFunc(al_get(pList , i) , al_get(pList , j)))
                    {
                        pAuxiliar = *(pList->pElements+i);
                        *(pList->pElements+i) = *(pList->pElements+j);
                        *(pList->pElements+j) = pAuxiliar;

                        retorno = 1;
                    }
                }
            }
        }
        else
        {
            for(i=0 ; i<pList->size-1 ; i++)
            {
                for(j=i+1 ; j<pList->size ; j++)
                {
                    if(!pFunc(al_get(pList , i) , al_get(pList , j)))
                    {
                        pAuxiliar = *(pList->pElements+i);
                        *(pList->pElements+i) = *(pList->pElements+j);
                        *(pList->pElements+j) = pAuxiliar;

                        retorno = 1;
                    }
                }
            }
        }
    }

    return retorno;
}

int resizeUp(ArrayList* pList)
{
    int retorno=-1;
    void** pAuxiliar;

    if(pList != NULL)
    {
        pAuxiliar = realloc(pList->pElements , sizeof(void*) * (pList->reservedSize+INCREMENTO)); //Preguntar por el primer parametro. Tener en cuanta que el primer parametro es un puntero de aquello que quiero redimensionar

        if(pAuxiliar != NULL)
        {
            pList->pElements = pAuxiliar;
            pList->reservedSize += INCREMENTO;

            retorno = 0;
        }
    }

    return retorno;
}

