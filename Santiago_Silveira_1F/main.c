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
    int opcion,opcionExtra,flagJuego=0,flagCliente=0,flagAlquiler=0;
    char salida = 's';
    do
    {
        system("cls");
        abm_Menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1://Juegos
                system("cls");
                abm_Menu_Juegos();
                fflush(stdin);
                scanf("%d",&opcionExtra);
                switch(opcionExtra)
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
                    case 5://SALIR
                        break;
                    default:
                        system("cls");
                        printf("Opcion no valida");
                        break;
                }
                break;
            case 2://Clientes
                system("cls");
                abm_Menu_Clientes();
                fflush(stdin);
                scanf("%d",&opcionExtra);
                switch(opcionExtra)
                {
                   case 1://ALTA_C
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
                    case 2://MOD_C
                        if(flagCliente == 1)
                        {
                            abm_Cliente_Modificar(eCliente,CCLIENTES);
                        }
                        break;
                    case 3://BAJA_C
                        if(flagCliente == 1)
                        {
                            abm_Cliente_Baja(eCliente,CCLIENTES);
                        }
                        break;
                    case 4://LISTA_C
                        if(flagCliente == 1)
                        {
                            abm_cliente_Listar(eCliente,CCLIENTES);
                            system("pause");
                        }
                        break;
                    case 5://SALIR
                        break;
                    default:
                        system("cls");
                        printf("Opcion no valida");
                        break;
                }
                break;
            case 3://Alquileres
                system("cls");
                abm_Menu_Alquileres();
                fflush(stdin);
                scanf("%d",&opcionExtra);
                switch(opcionExtra)
                {
                    case 1://ALTA_A
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
                    case 2://LISTA_A
                        if(flagAlquiler == 1)
                        {
                            abm_Alquiler_Listar(eAlquiler,CJUEGOS*CCLIENTES);
                            system("pause");
                        }
                        break;
                    case 3://SALIR
                        break;
                    default:
                        system("cls");
                        printf("Opcion no valida");
                        break;
                }
                break;
            case 4://Informes
                if(!(flagCliente == 1 && flagJuego == 1 && flagAlquiler == 1))
                {
                    system("cls");
                    printf("Primero necesita clientes, juegos y alquileres");
                    break;
                }
                system("cls");
                abm_Menu_Informes();
                fflush(stdin);
                scanf("%d",&opcionExtra);
                switch(opcionExtra)
                {
                    case 1://Promedio y total de los importes de los juegos alquilados
                        abm_Informe_ImportePyT(eJuego,CJUEGOS,eAlquiler,CJUEGOS*CCLIENTES);
                        break;
                    case 2://La cantidad de juegos cuyo importe NO superan el promedio del item anterior
                        abm_Informe_JuegosDebajoDelPromedio(eJuego,CJUEGOS,eAlquiler,CJUEGOS*CCLIENTES);
                        break;
                    case 3://Lista clientes que alquilaron un juego determinado
                        abm_Informe_BuscarClientePorJuego(eAlquiler,CJUEGOS*CCLIENTES,eJuego,CJUEGOS,eCliente,CCLIENTES);
                        break;
                    case 4://Lista juegos que fueron alquilados por un cliente determinado
                        abm_Informe_BuscarJuegoPorCliente(eAlquiler,CJUEGOS*CCLIENTES,eJuego,CJUEGOS,eCliente,CCLIENTES);
                        break;
                    case 5://Listar juegos menos alquilados
                        abm_Informe_JuegosMenosAlquilados(eAlquiler,CJUEGOS*CCLIENTES,eJuego,CJUEGOS);
                        break;
                    case 6://Listar clientes con mas alquileres
                        abm_Informe_ClientesConMasAlquileres(eAlquiler,CJUEGOS*CCLIENTES,eCliente,CCLIENTES);
                        break;
                    case 7://Listar juegos alquilados en una fecha determinada
                        abm_Informe_BuscarJuegoPorFecha(eAlquiler,CJUEGOS*CCLIENTES,eJuego,CJUEGOS);
                        break;
                    case 8://Listar clientes que realizaron alquileres en una fecha determinada
                        abm_Informe_BuscarClientePorFecha(eAlquiler,CJUEGOS*CCLIENTES,eCliente,CCLIENTES);
                        break;
                    case 9://Listar juegos ordenados por importe(descendente), utilizando burbujeo mas eficiente
                        abm_Informe_BurbujeoImporteJuegos(eJuego,CJUEGOS);
                        break;
                    case 10://Listar clientes ordenados por apellido(ascendente), utilizando insercion
                        break;
                    case 11://Salir
                        break;
                    default:
                        system("cls");
                        printf("Opcion no valida");
                        break;
                }
                break;
            case 5://Salir
                salida = 'n';
                break;
            default:
                system("cls");
                printf("Opcion no valida");
                break;
        }

    }while(salida == 's');
    return 0;
}
