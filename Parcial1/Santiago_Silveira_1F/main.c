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
    int opcion,flagJuego=0,flagCliente=0;
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
                if(abm_Juego_Alta(eJuego,CJUEGOS)==0)
                {
                    flagJuego = 1;
                }
                break;
            case 2://MOD
                if(flagJuego == 1)
                {
                    abm_Juego_Modificar(eJuego,CJUEGOS);
                }
                break;
            case 3://BAJA
                if(flagJuego == 1)
                {

                }
                break;
            case 4://LISTA
                if(flagJuego == 1)
                {

                }
                break;
            case 5://ALTA
                if(abm_Cliente_Alta(eCliente,CCLIENTES)==0)
                {
                    flagCliente = 1;
                }
                break;
            case 6://MOD
                if(flagCliente == 1)
                {
                    abm_Cliente_Modificar(eCliente,CCLIENTES);
                }
                break;
            case 7://BAJA
                if(flagCliente == 1)
                {

                }
                break;
            case 8://LISTA
                if(flagCliente == 1)
                {

                }
                break;
            case 9:
                salida = 'n';
                break;
            default:
                break;
        }

    }while(salida == 's');
    return 0;
}
