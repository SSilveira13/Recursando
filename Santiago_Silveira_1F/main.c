#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#define CCLIENTES 20
#define CJUEGOS 20

int main()
{
    juegos eJuego[CJUEGOS];
    cliente eCliente[CCLIENTES];
    alquileres eAlquiler[CJUEGOS*CCLIENTES];
    abm_Inicializar(eCliente,CCLIENTES,eJuego,CJUEGOS,eAlquiler,CJUEGOS*CCLIENTES);
    int opcion,flagJuego=0,flagCliente=0,flagAlquiler=0;
    char salida = 's';
    do
    {
        system("cls");
        abm_Menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1://ALTA_J
                if(abm_Juego_Alta(eJuego,CJUEGOS)==0)
                {
                    flagJuego = 1;
                }
                else
                {
                    system("cls");
                    printf("Error al dar de alta");
                    system("pause");
                }
                break;
            case 2://MOD_J
                if(flagJuego == 1)
                {
                    abm_Juego_Modificar(eJuego,CJUEGOS);
                }
                break;
            case 3://BAJA_J
                if(flagJuego == 1)
                {
                    abm_Juego_Baja(eJuego,CJUEGOS);
                }
                break;
            case 4://LISTA_J
                if(flagJuego == 1)
                {
                    abm_juego_Listar(eJuego,CJUEGOS);
                    system("pause");
                }
                break;
            case 5://ALTA_C
                if(abm_Cliente_Alta(eCliente,CCLIENTES)==0)
                {
                    flagCliente = 1;
                }
                else
                {
                    system("cls");
                    printf("Error al dar de alta");
                    system("pause");
                }
                break;
            case 6://MOD_C
                if(flagCliente == 1)
                {
                    abm_Cliente_Modificar(eCliente,CCLIENTES);
                }
                break;
            case 7://BAJA_C
                if(flagCliente == 1)
                {
                    abm_Cliente_Baja(eCliente,CCLIENTES);
                }
                break;
            case 8://LISTA_C
                if(flagCliente == 1)
                {
                    abm_cliente_Listar(eCliente,CCLIENTES);
                    system("pause");
                }
                break;
            case 9://ALTA_A
                if(flagCliente == 1 && flagJuego == 1)
                {
                    if(abm_Alquiler_Alta(eAlquiler,CJUEGOS*CCLIENTES,eJuego,CJUEGOS,eCliente,CCLIENTES) == 0)
                    {
                        flagAlquiler = 1;
                    }
                    else
                    {
                        system("cls");
                        printf("Error al dar de alta");
                        system("pause");
                    }
                }
                break;
            case 10://LISTA_A
                if(flagAlquiler == 1)
                {
                    abm_Alquiler_Listar(eAlquiler,CJUEGOS*CCLIENTES);
                    system("pause");
                }
                break;
            case 11://SALIR
                salida = 'n';
                break;
            default:
                break;
        }

    }while(salida == 's');
    return 0;
}
