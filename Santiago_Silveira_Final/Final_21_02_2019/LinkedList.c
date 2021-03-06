#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Socios.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int index;
    Node* pNode = NULL;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        for(index=0;index<=nodeIndex;index++)
        {
            if(pNode==NULL)
            {
                pNode = this->pFirstNode;
            }
            else
            {
                pNode = pNode->pNextNode;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;
    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));
            if(nuevoNodo != NULL)
            {
                nuevoNodo->pElement = pElement;
                nuevoNodo->pNextNode = NULL;
                if(nodeIndex == 0)
                {
                    nuevoNodo->pNextNode = this->pFirstNode;
                    this->pFirstNode = nuevoNodo;
                }
                else
                {
                    prev = this->pFirstNode;
                    next = prev->pNextNode;
                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev->pNextNode;
                        nodeIndex--;
                    }
                    prev->pNextNode = nuevoNodo;
                    nuevoNodo->pNextNode = next;
                }
                this->size++;
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;
    Node* actual;

    if(this!=NULL)
    {
        actual = this->pFirstNode;
        while(actual!=NULL)
        {
            actual = actual->pNextNode;
            indice++;
        }
        if(!addNode(this,indice,pElement))
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* actual;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        actual = getNode(this,index);
        returnAux = actual->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        actual = getNode(this,index);
        actual->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* previo;
    Node* actual;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        actual = getNode(this,index);
        if(actual!=NULL)
        {
            if(index==0)
            {
                this->pFirstNode = actual->pNextNode;
                this->size--;
                returnAux = 0;
            }
            else
            {
                previo = getNode(this,index-1);
                if(previo!=NULL)
                {
                    previo->pNextNode = actual->pNextNode;
                    this->size--;
                    returnAux = 0;
                }
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
        free(this);
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    Node* actual;
    if(this!=NULL)
    {
        for(index=0;index<ll_len(this);index++)
        {
            actual = getNode(this,index);
            if(actual->pElement == pElement)
            {
                returnAux = index;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(index>=0 && index<=ll_len(this))
        {
           if(!addNode(this,index,pElement))
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* aux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        aux = ll_get(this,index);
        if(aux!=NULL)
        {
            if(index==0)
            {
                ll_remove(this,index);
            }
            else
            {
                ll_remove(this,index);
            }
            returnAux = aux;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int index;
    void* aux;
    if(this!=NULL)
    {
        returnAux = 0;
        for(index=0;index<=ll_len(this);index++)
        {
            aux = ll_get(this,index);
            if(aux!=NULL)
            {
               if(pElement == aux)
                {
                    returnAux = 1;
                    break;
                }
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int index;
    int contador = 0;
    void* aux;
    if(this!=NULL && this2!=NULL)
    {
        returnAux = 0;
        for(index=0;index<=ll_len(this2);index++)
        {
            aux = ll_get(this2,index);
            if(aux!=NULL)
            {
                if(ll_contains(this,aux))
                {
                    contador++;
                }
            }
        }
        if(contador==ll_len(this2))
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* auxiliar = NULL;
    int index;
    void* elemento = NULL;
    if(this!=NULL && from>=0 && to>=0 && from<=ll_len(this) && to<=ll_len(this))
    {
        auxiliar = ll_newLinkedList();
        if(auxiliar!=NULL)
        {
            for(index=from;index<to;index++)
            {
                elemento = ll_get(this,index);
                if(elemento!=NULL)
                {
                    ll_add(auxiliar,elemento);
                }
            }
        }
        cloneArray = auxiliar;
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    //LinkedList* auxiliar = NULL;
    //int index;
    //void* elemento = NULL;
    if(this!=NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
        /*auxiliar = ll_newLinkedList();
        if(auxiliar!=NULL)
        {int index;
    Vendedor* aux;
    int monto,cantidad,comision,id;
    char nivel[25],nombre[25];
    for(index=0;index<=ll_len(this);index++)
    {
        aux = (Vendedor*)ll_get(this,index);
        vendedor_getNivel(aux,nivel);
        vendedor_getMontoVendido(aux,&monto);
        vendedor_getCantidadProductos(aux,&cantidad);
        vendedor_getId(aux,&id);
        vendedor_getNombre(aux,nombre);
        if(strcmp(nivel,"Junior")==0)
        {
            comision = monto * 0.02;
        }
        else if(strcmp(nivel,"Estandard")==0)
        {
            if(cantidad<100)
            {
                comision = monto * 0.035;
            }
            else
            {
                comision = monto * 0.05;
            }
        }
        else if(strcmp(nivel,"Experto")==0)
        {
            if(cantidad<100)
            {
                comision = monto * 0.035;
            }
            else
            {
                comision = monto * 0.05;
            }
        }
        printf("ID: %d\tVendedor: %s\tComision: %d\n",id,nombre,comision);
    }
            for(index=0;index<=ll_len(this);index++)
            {
                elemento = ll_get(this,index);
                if(elemento!=NULL)
                {
                    ll_add(auxiliar,elemento);
                }
            }
        }
        cloneArray = auxiliar;*/
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* elementoA;
    void* elementoB;
    void* elementoAuxiliar;
    int index;
    int comp;
    if(this!=NULL && pFunc!=NULL && (order==1 || order==0))
    {
        for(index=0;index<ll_len(this);index++)
        {
            for(comp=index+1;comp<ll_len(this);comp++)
            {
                elementoA = ll_get(this,index);
                elementoB = ll_get(this,comp);
                if(order==1 && pFunc(elementoA,elementoB)==1)
                {
                    elementoAuxiliar = elementoA;
                    ll_set(this,index,elementoB);
                    ll_set(this,comp,elementoAuxiliar);
                }
                if(order==0 && pFunc(elementoA,elementoB)==-1)
                {
                    elementoAuxiliar = elementoA;
                    ll_set(this,index,elementoB);
                    ll_set(this,comp,elementoAuxiliar);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

/*void ll_map(LinkedList* this)
{
    int index;
    Envios* aux;
    int kmRecorridos,costo,idEnvio,tipoEntrega;
    char ZonaDestino[25],nombreProducto[25];
    for(index=0;index<ll_len(this);index++)
    {
        aux = (Envios*)ll_get(this,index);
        envio_getTipoEntrega(aux,&tipoEntrega);
        envio_getKmRecorridos(aux,&kmRecorridos);
        envio_getIdenvio(aux,&idEnvio);
        envio_getNombreProducto(aux,nombreProducto);
        envio_getZonaDestino(aux,ZonaDestino);
        costo = envio_costos(tipoEntrega,kmRecorridos);
        printf("ID de Envio: %d\tProducto: %s\tCosto: %d\n",idEnvio,nombreProducto,costo);
    }
    system("pause");
}*/
/*
LinkedList* ll_filter(LinkedList* this,int zonaDestino)
{
    int index;
    char ZonaString[25];
    Envios* aux;
    LinkedList* copia;
    copia = ll_newLinkedList();
    switch(zonaDestino)
    {
        case 1:
            for(index=0;index<=ll_len(this);index++)
            {
                aux=ll_get(this,index);
                if(aux!=NULL)
                {
                    envio_getZonaDestino(aux,ZonaString);
                    if(strcmp(ZonaString,"1")==0)
                    {
                        ll_add(copia,(void*)aux);
                    }
                }
            }
            break;
        case 2:
            for(index=0;index<=ll_len(this);index++)
            {
                aux=ll_get(this,index);
                if(aux!=NULL)
                {
                    vendedor_getNivel(aux,nivelS);
                    if(strcmp(nivelS,"2")==0)
                    {
                        ll_add(copia,(void*)aux);
                    }
                }
            }
            break;
        case 3:
            for(index=0;index<=ll_len(this);index++)
            {
                aux=ll_get(this,index);
                if(aux!=NULL)
                {
                    vendedor_getNivel(aux,nivelS);
                    if(strcmp(nivelS,"3")==0)
                    {
                        ll_add(copia,(void*)aux);
                    }
                }
            }
            break;
    }
    return copia;
}

*/
