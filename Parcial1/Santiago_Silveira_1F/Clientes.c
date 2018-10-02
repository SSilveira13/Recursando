#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"

void abm_Menu()
{
    printf("****JUEGOS****\n\n");
    printf("1_Alta.\n");
    printf("2_Modificacion.\n");
    printf("3_Baja.\n");
    printf("4_Listar.\n");
    printf("****CLIENTES****\n\n");
    printf("5_Alta.\n");
    printf("6_Modificacion.\n");
    printf("7_Baja.\n");
    printf("8_Listar.\n\n");
    printf("9_Salir.\n");
}

void abm_Inicializar(cliente* eCliente,int cantidadC,juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidadC;iteracion++)
    {
        eCliente[iteracion].isEmpty = 1;
    }
    for(iteracion=0;iteracion<cantidadJ;iteracion++)
    {
        eJuego[iteracion].isEmpty = 1;
    }
    for(iteracion=0;iteracion<cantidadA;iteracion++)
    {
        eAlquiler[iteracion].isEmpty = 1;
    }
}

int abm_Juego_espacioVacio(juegos* eJuego,int cantidadJ)
{
    int iteracion,retorno = -1;
    for(iteracion=0;iteracion<cantidadJ;iteracion++)
    {
        if(eJuego[iteracion].isEmpty == 1)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

int abm_Cliente_espacioVacio(cliente* eCliente,int cantidadC)
{
    int iteracion,retorno = -1;
    for(iteracion=0;iteracion<cantidadC;iteracion++)
    {
        if(eCliente[iteracion].isEmpty == 1)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

int abm_Juego_Alta(juegos* eJuego,int cantidad)
{
    int retorno = -1;
    if(eJuego != NULL && cantidad>0)
    {
        int retorno = 0;
        char alta = 's';
        do{
            system("cls");
            if(abm_ingresaJuego(eJuego,abm_Juego_espacioVacio(eJuego,cantidad),cantidad) == -1)
            {
                retorno = -1;
                break;
            }
            system("cls");
            printf("\n\nQuiere seguir ingresando?(s/n) ");
            fflush(stdin);
            scanf("%c",&alta);
        }while(alta == 's');
    return retorno;
    }
    return retorno;
}

int abm_Cliente_Alta(cliente* eCliente,int cantidad)
{
    int retorno = -1;
    if(eCliente != NULL && cantidad>0)
    {
        int retorno = 0;
        char alta = 's';
        do{
            system("cls");
            if(abm_ingresaCliente(eCliente,abm_Cliente_espacioVacio(eCliente,cantidad),cantidad) == -1)
            {
                retorno = -1;
                break;
            }
            system("cls");
            printf("\n\nQuiere seguir ingresando?(s/n) ");
            fflush(stdin);
            scanf("%c",&alta);
        }while(alta == 's');
    return retorno;
    }
    return retorno;
}

int abm_ingresaJuego(juegos* eJuego,int vacio,int cantidadJ)
{
    int retorno=0,indice;
    float auxiliar;
    indice = abm_Juego_espacioVacio(eJuego,cantidadJ);
    eJuego[indice].codigoDeJuego = indice+1;
    printf("****JUEGO ALTA****\n\n");
    printf("Ingrese descripcion: \n");
    fflush(stdin);
    retorno = utn_getCadena(eJuego[indice].descripcion,"","Error",0);
    printf("Ingrese importe: \n");
    fflush(stdin);
    retorno = utn_getFlotante(&auxiliar,"","Error",0,99999,0);
    eJuego[indice].importe = auxiliar;
    if(retorno == 0)
    {
        eJuego[indice].isEmpty = 0;
    }
    return retorno;
}

int abm_ingresaCliente(cliente* eCliente,int vacio,int cantidadC)
{
    int retorno=0,indice;
    indice = abm_Cliente_espacioVacio(eCliente,cantidadC);
    eCliente[indice].codigoDeCliente = indice+1;
    printf("****CLIENTE ALTA****\n\n");
    printf("Ingrese apellido: \n");
    fflush(stdin);
    retorno = utn_getCadena(eCliente[indice].apellido,"","Error",0);
    printf("Ingrese nombre: \n");
    fflush(stdin);
    retorno = utn_getCadena(eCliente[indice].nombre,"","Error",0);
    printf("Ingrese domicilio: \n");
    fflush(stdin);
    retorno = utn_getCadena(eCliente[indice].domicilio,"","Error",0);
    printf("Ingrese telefono: \n");
    fflush(stdin);
    retorno = utn_getCadena(eCliente[indice].telefono,"","Error",0);
    if(retorno == 0)
    {
        eCliente[indice].isEmpty = 0;
    }
    return retorno;
}

int abm_Juego_Modificar(juegos* eJuego,int cantidadJ)
{
    system("cls");
    int indice,codigo,modificar,retorno = 0;
    float auxiliar;
    abm_imprimirJuegos(eJuego,cantidadJ);
    printf("\n\nIngrese el codigo del juego a modificar: ");
    fflush(stdin);
    scanf("%d",&codigo);
    indice = juego_buscarPorCodigo(eJuego,cantidadJ,codigo);
    printf("1_Descripcion: %s\n",eJuego[indice].descripcion);
    printf("2_Importe: %f\n",eJuego[indice].importe);
    fflush(stdin);
    scanf("%d",&modificar);
    system("cls");
    switch(modificar)
    {
        case 1:
            retorno = utn_getCadena(eJuego[indice].descripcion,"","Error",0);
            break;
        case 2:
            retorno = utn_getFlotante(&auxiliar,"","Error",0,99999,0);
            eJuego[indice].importe = auxiliar;
            break;
        default:
            system("cls");
            printf("Error: opcion no valida.");
            break;
    }
    return retorno;
}

int abm_Cliente_Modificar(cliente* eCliente,int cantidadC)
{
    system("cls");
    int indice,codigo,modificar,retorno = 0;
    abm_imprimirClientes(eCliente,cantidadC);
    printf("\n\nIngrese el codigo del cliente a modificar: ");
    fflush(stdin);
    scanf("%d",&codigo);
    indice = cliente_buscarPorCodigo(eCliente,cantidadC,codigo);
    printf("1_Apellido: %s\n",eCliente[indice].apellido);
    printf("2_Nombre: %s\n",eCliente[indice].nombre);
    printf("3_Domicilio: %s\n",eCliente[indice].domicilio);
    printf("4_Telefono: %s\n",eCliente[indice].telefono);
    fflush(stdin);
    scanf("%d",&modificar);
    system("cls");
    switch(modificar)
    {
        case 1:
            retorno = utn_getCadena(eCliente[indice].apellido,"","Error",0);
            break;
        case 2:
            retorno = utn_getCadena(eCliente[indice].nombre,"","Error",0);
            break;
        case 3:
            retorno = utn_getCadena(eCliente[indice].domicilio,"","Error",0);
            break;
        case 4:
            retorno = utn_getCadena(eCliente[indice].telefono,"","Error",0);
            break;
        default:
            system("cls");
            printf("Error: opcion no valida.");
            break;
    }
    return retorno;
}

void abm_imprimirJuegos(juegos* eJuego,int cantidadJ)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidadJ;iteracion++)
    {
        if(eJuego[iteracion].isEmpty == 0)
        {
            printf("-------------------------------------------------------------------------------\n");
            printf("Codigo de juego: %d\t",eJuego[iteracion].codigoDeJuego);
            printf("Descripcion: %s\t",eJuego[iteracion].descripcion);
            printf("Importe: %f\n",eJuego[iteracion].importe);
        }
    }
}

void abm_imprimirClientes(cliente* eCliente,int cantidadC)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidadC;iteracion++)
    {
        if(eCliente[iteracion].isEmpty == 0)
        {
            printf("-------------------------------------------------------------------------------\n");
            printf("Codigo de cliente: %d\t",eCliente[iteracion].codigoDeCliente);
            printf("Apellido: %s\t",eCliente[iteracion].apellido);
            printf("Nombre: %s\n",eCliente[iteracion].nombre);
            printf("Domicilio: %s\t",eCliente[iteracion].domicilio);
            printf("Telefono: %s\n",eCliente[iteracion].telefono);
        }
    }
}

int juego_buscarPorCodigo(juegos* eJuego,int cantidadJ,int codigo)
{
    int iteracion,retorno=-1;
    for(iteracion=0;iteracion<cantidadJ;iteracion++)
    {
        if(eJuego[iteracion].isEmpty == 0 && eJuego[iteracion].codigoDeJuego == codigo)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

int cliente_buscarPorCodigo(cliente* eCliente,int cantidadC,int codigo)
{
    int iteracion,retorno=-1;
    for(iteracion=0;iteracion<cantidadC;iteracion++)
    {
        if(eCliente[iteracion].isEmpty == 0 && eCliente[iteracion].codigoDeCliente == codigo)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

int abm_Juego_Baja(juegos* eJuego,int cantidadJ)
{
    int retorno = 0;
    return retorno;
}

int abm_Cliente_Baja(cliente* eCliente,int cantidadC)
{
    int retorno = 0;
    return retorno;
}
