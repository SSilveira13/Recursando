#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"

void abm_Inicializar(persona eEmpleado[],int cantidad)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        eEmpleado[iteracion].isEmpty = 1;
    }
}

void abm_Menu()
{
    printf("1_Alta.\n");
    printf("2_Baja.\n");
    printf("3_Modificacion.\n");
    printf("4_Lista.\n");
    printf("5_Salir.\n");
}

void abm_Alta(persona eEmpleado[],int cantidad)
{

}

int abm_espacioVacio(persona eEmpleado[],int cantidad)
{
    int iteracion,retorno = -1;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 1)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}
