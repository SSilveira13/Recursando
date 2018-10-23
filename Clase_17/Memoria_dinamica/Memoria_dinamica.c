#include <stdio.h>
#include <stdlib.h>

void Memoria_liberar(void *puntero)
{
    if(puntero != NULL)
    {
        free(puntero);
    }
    else
    {
        system("cls");
        printf("El puntero no apunta a nada");
        system("pause");
    }
}
