#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#define CANT 200

int main()
{
    persona eEmpleado[CANT];
    abm_Inicializar(eEmpleado,CANT);
    int opcion;
    char salida = 's';
    do
    {
        //system("clear");
        abm_Menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                abm_Alta(eEmpleado,CANT);
                break;
            case 2:
                abm_Baja(eEmpleado,CANT);
                break;
            case 3:
                abm_Modificar(eEmpleado,CANT);
                break;
            case 4:
                //system("clr");
                abm_imprimirEmpleados(eEmpleado,CANT);
                system("pause");
                break;
            case 5:
                salida = 'n';
                break;
            default:
                break;
        }

    }while(salida == 's');
    return 0;
}
