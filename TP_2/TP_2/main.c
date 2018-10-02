#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ABM.h"
#define CANT 1000

int main()
{
    persona eEmpleado[CANT];
    abm_Inicializar(eEmpleado,CANT);
    int opcion,flag=0;
    char salida = 's';
    do
    {
        system("cls");
        abm_Menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1://ALTA
                if(abm_Alta(eEmpleado,CANT)==0)
                {
                    flag = 1;
                }
                break;
            case 2://MOD
                if(flag == 1)
                {
                    abm_Modificar(eEmpleado,CANT);
                }
                else
                {
                    system("cls");
                    printf("Primero debe dar de alta por lo menos 1 empleado.");
                }
                break;
            case 3://BAJA
                if(flag == 1)
                {
                    abm_Baja(eEmpleado,CANT);
                }
                else
                {
                    system("cls");
                    printf("Primero debe dar de alta por lo menos 1 empleado.");
                }
                break;
            case 4://INFO
                if(flag == 1)
                {
                    system("cls");
                    abm_informarEmpleados(eEmpleado,CANT);
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("Primero debe dar de alta por lo menos 1 empleado.");
                }
                break;
            case 5://SALIR
                salida = 'n';
                break;
            default:
                system("cls");
                printf("Error: opcion no valida.");
                break;
        }

    }while(salida == 's');
    return 0;
}
