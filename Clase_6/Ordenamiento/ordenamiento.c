#include <stdio.h>
#include <stdlib.h>

void ordenamientoPorBurbujeo(int array[],int tamanio)
{
    int posicion,comparacion,temporal;
    for(posicion=0;posicion<tamanio;posicion++)
    {
        for(comparacion=posicion+1;comparacion<tamanio;comparacion++)
        {
            if(array[posicion]<array[comparacion])
            {
                temporal=array[posicion];
                array[posicion]=array[comparacion];
                array[comparacion]=temporal;
            }
        }
    }
}

void ordenamientoPorInsercion(int array[],int tamanio)
{
    int posicion,comparacion,temporal;
    for(posicion=1;posicion<tamanio;posicion++)
    {
        temporal=array[posicion];
        comparacion = posicion - 1;
        while((comparacion>=0) && (temporal<array[comparacion]))
        {
        array[comparacion+1]=array[comparacion];
        comparacion--;
        }
    array[comparacion+1]=temporal;
    }
    printf("Ordenamiento completado...\n");
    system("pause");
}

void informar(int array[],int TAMANIO)
{
    int iteracion;
    for(iteracion=0;iteracion<TAMANIO;iteracion++)
    {
        printf("%d) %d\n",iteracion+1,array[iteracion]);
    }
}
