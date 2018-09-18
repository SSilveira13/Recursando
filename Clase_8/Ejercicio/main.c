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
    int i;
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
                system("clr");
                for(i=0;i<200;i++)
                {
                    if(eEmpleado[i].isEmpty == 0)
                    {
                        printf("-------------------------------------------------------------------------------\n");
                        printf("Indice: %d\t",i);
                        printf("Nombre: %s\t",eEmpleado[i].nombre);
                        printf("Apellido: %s\n",eEmpleado[i].apellido);
                        printf("DNI: %ld\t",eEmpleado[i].dni);
                        printf("Fecha de nacimiento: %d/%d/%d\n",eEmpleado[i].fechaNacimiento.dia,eEmpleado[i].fechaNacimiento.mes,eEmpleado[i].fechaNacimiento.anio);
                    }
                }
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
