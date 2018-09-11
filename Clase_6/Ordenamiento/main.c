#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"
#define TAMANIO 5

int main()
{
    int array[TAMANIO],i;
    printf("Ingrese %d numeros a continuacion: \n",TAMANIO);
    for(i=0;i<TAMANIO;i++)
    {
        scanf("%d",&array[i]);
    }
    ordenamientoPorInsercion(array,TAMANIO);
    informar(array,TAMANIO);
    return 0;
}
