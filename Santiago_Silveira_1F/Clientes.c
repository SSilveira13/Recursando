#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"

void abm_Menu()
{
    printf("****MENU****\n");
    printf("1_JUEGOS.\n");
    printf("2_CLIENTES.\n");
    printf("3_ALQUILERES.\n");
    printf("4_INFORMACION.\n\n");
    printf("5_SALIR.\n");
}

void abm_Menu_Juegos()
{
    printf("****JUEGOS****\n");
    printf("1_Alta.\n");
    printf("2_Modificacion.\n");
    printf("3_Baja.\n");
    printf("4_Listar.\n\n");
    printf("5_Salir.\n");
}

void abm_Menu_Clientes()
{
    printf("****CLIENTES****\n");
    printf("1_Alta.\n");
    printf("2_Modificacion.\n");
    printf("3_Baja.\n");
    printf("4_Listar.\n\n");
    printf("5_Salir.\n");
}

void abm_Menu_Alquileres()
{
    printf("****ALQUILERES****\n");
    printf("1_Alta.\n");
    printf("2_Listar.\n\n");
    printf("3_Salir.\n");
}

void abm_Menu_Informes()
{
    printf("****INFORMACION EXTRA****\n");
    printf("1_Promedio y total de importe en juegos alquilados.\n");
    printf("2_Juegos que no superan el promedio de importe.\n");
    printf("3_Buscar clientes que alquilaron un juego.\n");
    printf("4_Buscar juegos que fueron alquilados por un cliente.\n");
    printf("5_Juegos menos alquilados.\n");
    printf("6_Clientes con mas alquileres.\n");
    printf("7_Buscar juegos alquilados en una fecha.\n");
    printf("8_Buscar clientes que alquilaron en una fecha.\n");
    printf("9_Listar juegos por importe(descendente).\n");
    printf("10_Listar clientes por apellidos(ascendente).\n\n");
    printf("11_Salir.\n");
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
        retorno = 0;
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
    }
    return retorno;
}

int abm_Cliente_Alta(cliente* eCliente,int cantidad)
{
    int retorno = -1;
    if(eCliente != NULL && cantidad>0)
    {
        retorno = 0;
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
    int codigo,indice,retorno = -1;
    system("cls");
    if(eJuego != NULL && cantidadJ>0)
    {
        abm_imprimirJuegos(eJuego,cantidadJ);
        printf("\n\nIngrese el codigo del juego a dar de baja: ");
        fflush(stdin);
        scanf("%d",&codigo);
        indice = juego_buscarPorCodigo(eJuego,cantidadJ,codigo);
        eJuego[indice].isEmpty = 1;
    }
    return retorno;
}

int abm_Cliente_Baja(cliente* eCliente,int cantidadC)
{
    int codigo,indice,retorno = -1;
    system("cls");
    if(eCliente != NULL && cantidadC>0)
    {
        abm_imprimirClientes(eCliente,cantidadC);
        printf("\n\nIngrese el codigo del cliente a dar de baja: ");
        fflush(stdin);
        scanf("%d",&codigo);
        indice = cliente_buscarPorCodigo(eCliente,cantidadC,codigo);
        eCliente[indice].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}

void juego_ordenar(juegos* eJuego,int cantidadJ)
{
    int iteracion,comparacion;
    for(iteracion=0;iteracion<cantidadJ;iteracion++)
    {
        if(eJuego[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidadJ;comparacion++)
            {
                if((eJuego[comparacion].isEmpty==0) && (eJuego[iteracion].importe<=eJuego[comparacion].importe))
                {
                    juego_intercambio(eJuego,iteracion,comparacion);
                }
                else if((eJuego[comparacion].isEmpty==0) && (strcmp(eJuego[iteracion].descripcion,eJuego[comparacion].descripcion)>0))
                {
                    juego_intercambio(eJuego,iteracion,comparacion);
                }
            }
        }
    }
}

void cliente_ordenar(cliente* eCliente,int cantidadC)
{
    int iteracion,comparacion;
    for(iteracion=0;iteracion<cantidadC;iteracion++)
    {
        if(eCliente[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidadC;comparacion++)
            {
                if((eCliente[comparacion].isEmpty==0) && (strcmp(eCliente[iteracion].apellido,eCliente[comparacion].apellido)>0))
                {
                    cliente_intercambio(eCliente,iteracion,comparacion);
                }
                else if((eCliente[comparacion].isEmpty==0) && (strcmp(eCliente[iteracion].nombre,eCliente[comparacion].nombre)>0))
                {
                    cliente_intercambio(eCliente,iteracion,comparacion);
                }
            }
        }
    }
}

void juego_intercambio(juegos* eJuego,int indice1,int indice2)
{
    juegos aux;
    aux = eJuego[indice1];
    eJuego[indice1] = eJuego[indice2];
    eJuego[indice2] = aux;
}

void cliente_intercambio(cliente* eCliente,int indice1,int indice2)
{
    cliente aux;
    aux = eCliente[indice1];
    eCliente[indice1] = eCliente[indice2];
    eCliente[indice2] = aux;
}

int abm_juego_Listar(juegos* eJuego,int cantidadJ)
{
    int retorno = -1;
    if(eJuego != NULL && cantidadJ>0)
    {
        retorno = 0;
        juego_ordenar(eJuego,cantidadJ);
        abm_imprimirJuegos(eJuego,cantidadJ);
    }
    return retorno;
}

int abm_cliente_Listar(cliente* eCliente,int cantidadC)
{
    int retorno = -1;
    if(eCliente != NULL && cantidadC>0)
    {
        retorno = 0;
        cliente_ordenar(eCliente,cantidadC);
        abm_imprimirClientes(eCliente,cantidadC);
    }
    return retorno;
}

int abm_Alquiler_espacioVacio(alquileres* eAlquiler,int cantidadA)
{
    int iteracion,retorno = -1;
    for(iteracion=0;iteracion<cantidadA;iteracion++)
    {
        if(eAlquiler[iteracion].isEmpty == 1)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}

int abm_Alquiler_Alta(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC)
{
    int retorno = -1;
    if(eAlquiler != NULL && cantidadA>0)
    {
        retorno = 0;
        char alta = 's';
        do{
            system("cls");
            if(abm_ingresaAlquiler(eAlquiler,abm_Alquiler_espacioVacio(eAlquiler,cantidadA),cantidadA,eJuego,cantidadJ,eCliente,cantidadC) == -1)
            {
                retorno = -1;
                break;
            }
            system("cls");
            printf("\n\nQuiere seguir ingresando?(s/n) ");
            fflush(stdin);
            scanf("%c",&alta);
        }while(alta == 's');

    }
    return retorno;
}

int abm_ingresaAlquiler(alquileres* eAlquiler,int vacio,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC)
{
    int auxiliar,retorno = 0;
    eAlquiler[vacio].codigoDeAlquiler = vacio + 1;
    abm_juego_Listar(eJuego,cantidadJ);
    printf("\n\nINGRESE EL CODIGO DEL JUEGO A ALQUILAR: ");
    fflush(stdin);
    retorno = utn_getEntero(&auxiliar,"","Error",0,99999,0);
    eAlquiler[vacio].codigoDeJuego = auxiliar;
    system("cls");
    abm_cliente_Listar(eCliente,cantidadC);
    printf("\n\nINGRESE EL CODIGO DEL CLIENTE: ");
    fflush(stdin);
    retorno = utn_getEntero(&auxiliar,"","Error",0,99999,0);
    eAlquiler[vacio].codigoDeCliente = auxiliar;
    system("cls");
    printf("Ingrese dia: ");
    retorno = utn_getEntero(&auxiliar,"","Error",1,31,0);
    eAlquiler[vacio].eFecha.dia = auxiliar;
    system("cls");
    printf("Ingrese mes: ");
    retorno = utn_getEntero(&auxiliar,"","Error",1,12,0);
    eAlquiler[vacio].eFecha.mes = auxiliar;
    system("cls");
    printf("Ingrese anio: ");
    retorno = utn_getEntero(&auxiliar,"","Error",2015,3000,0);
    eAlquiler[vacio].eFecha.anio = auxiliar;
    if(retorno == 0)
    {
        eAlquiler[vacio].isEmpty = 0;
    }
    return retorno;
}

void abm_Alquiler_Listar(alquileres* eAlquiler,int cantidadA)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidadA;iteracion++)
    {
        if(eAlquiler[iteracion].isEmpty == 0)
        {
            printf("-------------------------------------------------------------------------------\n");
            printf("Codigo de alquiler: %d\t",eAlquiler[iteracion].codigoDeAlquiler);
            printf("Codigo de cliente: %d\t",eAlquiler[iteracion].codigoDeCliente);
            printf("Codigo de juego: %d\n",eAlquiler[iteracion].codigoDeJuego);
            printf("Fecha de alquiler: %d/%d/%d\n",eAlquiler[iteracion].eFecha.dia,eAlquiler[iteracion].eFecha.mes,eAlquiler[iteracion].eFecha.anio);
        }
    }
}

void abm_Informe_ImportePyT(juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA)
{
    float promedio,total = 0;
    abm_Informe_PromedioYtotal(eJuego,cantidadJ,eAlquiler,cantidadA,&total,&promedio);
    system("cls");
    printf("El importe total de los juegos alquilados es: %f\n",total);
    printf("El promedio de los juegos alquilados es: %f",promedio);
    system("pause");
}

void abm_Informe_PromedioYtotal(juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA,float* total,float* promedio)
{
    int iteracion,auxiliar,contador;
    for(iteracion=0;iteracion<cantidadA;iteracion++)
    {
        if(eAlquiler[iteracion].isEmpty == 0)
        {
            auxiliar = juego_buscarPorCodigo(eJuego,cantidadJ,eAlquiler[iteracion].codigoDeJuego);
            *total = *total + eJuego[auxiliar].importe;
            contador++;
        }
    }
    *promedio = *total / contador;
}

void abm_Informe_JuegosDebajoDelPromedio(juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA)
{
    float promedio,total = 0;
    int iteracion,contador;
    abm_Informe_PromedioYtotal(eJuego,cantidadJ,eAlquiler,cantidadA,&total,&promedio);
    for(iteracion=0;iteracion<cantidadJ;iteracion++)
    {
        if(eJuego[iteracion].isEmpty == 0 && eJuego[iteracion].importe < promedio)
        {
            contador++;
        }
    }
    system("cls");
    printf("La cantidad de juegos que no superan el importe promedio: %d",contador);
    system("pause");
}

void abm_Informe_BuscarClientePorJuego(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC)
{
    int iteracion1,iteracion2,codigoAux;
    system("cls");
    abm_imprimirJuegos(eJuego,cantidadJ);
    printf("\nIngrese el codigo del juego:");
    fflush(stdin);
    utn_getEntero(&codigoAux,"","Error",0,cantidadJ,0);
    system("cls");
    for(iteracion1=0;iteracion1<cantidadA;iteracion1++)
    {
        if(eAlquiler[iteracion1].isEmpty == 0 && eAlquiler[iteracion1].codigoDeJuego == codigoAux)
        {
            for(iteracion2=0;iteracion2<cantidadC;iteracion2++)
            {
                if(eCliente[iteracion2].isEmpty == 0 && eCliente[iteracion2].codigoDeCliente == eAlquiler[iteracion1].codigoDeCliente)
                {
                    printf("-------------------------------------------------------------------------------\n");
                    printf("Codigo de cliente: %d\t",eCliente[iteracion2].codigoDeCliente);
                    printf("Apellido: %s\t",eCliente[iteracion2].apellido);
                    printf("Nombre: %s\n",eCliente[iteracion2].nombre);
                    printf("Domicilio: %s\t",eCliente[iteracion2].domicilio);
                    printf("Telefono: %s\n",eCliente[iteracion2].telefono);
                }
            }
        }
    }
}

void abm_Informe_BuscarJuegoPorCliente(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC)
{
    int iteracion1,iteracion2,codigoAux;
    system("cls");
    abm_imprimirClientes(eCliente,cantidadC);
    printf("\nIngrese el codigo del cliente:");
    fflush(stdin);
    utn_getEntero(&codigoAux,"","Error",0,cantidadJ,0);
    system("cls");
    for(iteracion1=0;iteracion1<cantidadA;iteracion1++)
    {
        if(eAlquiler[iteracion1].isEmpty == 0 && eAlquiler[iteracion1].codigoDeCliente == codigoAux)
        {
            for(iteracion2=0;iteracion2<cantidadJ;iteracion2++)
            {
                if(eJuego[iteracion2].isEmpty == 0 && eJuego[iteracion2].codigoDeJuego == eAlquiler[iteracion1].codigoDeJuego)
                {
                    printf("-------------------------------------------------------------------------------\n");
                    printf("Codigo de juego: %d\t",eJuego[iteracion2].codigoDeJuego);
                    printf("Descripcion: %s\t",eJuego[iteracion2].descripcion);
                    printf("Importe: %f\n",eJuego[iteracion2].importe);
                }
            }
        }
    }
}

void abm_Informe_JuegosMenosAlquilados(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ)
{
    int iteracion1,iteracion2,minimo,flag=0,contador,indice,contadorMin=0,iterMin,indiceMin[cantidadJ];
    for(iteracion1=0;iteracion1<cantidadJ;iteracion1++)
    {
        if(eJuego[iteracion1].isEmpty == 0)
        {
            for(iteracion2=0;iteracion2<cantidadA;iteracion2++)
            {
                if(eAlquiler[iteracion2].isEmpty == 0 && eAlquiler[iteracion2].codigoDeJuego == eJuego[iteracion1].codigoDeJuego)
                {
                    contador++;
                }
            }
            if(minimo>contador || flag == 0)
            {

                minimo = contador;
                indice = iteracion1;
                flag = 1;
                contadorMin = 0;
                for(iterMin=0;iterMin<cantidadJ;iterMin++)
                {
                    indiceMin[iterMin] = -1;
                }
            }
            else if(minimo == contador)
            {
                iteracion1 = indiceMin[contadorMin];
                contadorMin++;
            }
        }
    }
    system("cls");
    printf("-------------------------Juegos menos alquilado--------------------------------\n");
    printf("Codigo de juego: %d\t",eJuego[indice].codigoDeJuego);
    printf("Descripcion: %s\t",eJuego[indice].descripcion);
    printf("Importe: %f\n",eJuego[indice].importe);
    for(iteracion1=0;iteracion1<contadorMin;iteracion1++)
    {
        indice = indiceMin[iteracion1];
        printf("-------------------------------------------------------------------------------\n");
        printf("Codigo de juego: %d\t",eJuego[indice].codigoDeJuego);
        printf("Descripcion: %s\t",eJuego[indice].descripcion);
        printf("Importe: %f\n",eJuego[indice].importe);
    }
    system("pause");
}

void abm_Informe_ClientesConMasAlquileres(alquileres* eAlquiler,int cantidadA,cliente* eCliente,int cantidadC)
{
    int iteracion1,iteracion2,minimo,flag=0,contador,indice,contadorMin=0,iterMin,indiceMin[cantidadC];
    for(iteracion1=0;iteracion1<cantidadC;iteracion1++)
    {
        if(eCliente[iteracion1].isEmpty == 0)
        {
            for(iteracion2=0;iteracion2<cantidadA;iteracion2++)
            {
                if(eAlquiler[iteracion2].isEmpty == 0 && eAlquiler[iteracion2].codigoDeCliente == eCliente[iteracion1].codigoDeCliente)
                {
                    contador++;
                }
            }
            if(minimo>contador || flag == 0)
            {

                minimo = contador;
                indice = iteracion1;
                flag = 1;
                contadorMin = 0;
                for(iterMin=0;iterMin<cantidadC;iterMin++)
                {
                    indiceMin[iterMin] = -1;
                }
            }
            else if(minimo == contador)
            {
                iteracion1 = indiceMin[contadorMin];
                contadorMin++;
            }
        }
    }
    system("cls");
    printf("-------------------------Clientes que mas alquilan-----------------------------\n");
    printf("Codigo de cliente: %d\t",eCliente[indice].codigoDeCliente);
    printf("Apellido: %s\t",eCliente[indice].apellido);
    printf("Nombre: %s\n",eCliente[indice].nombre);
    printf("Domicilio: %s\t",eCliente[indice].domicilio);
    printf("Telefono: %s\n",eCliente[indice].telefono);
    for(iteracion1=0;iteracion1<contadorMin;iteracion1++)
    {
        indice = indiceMin[iteracion1];
        printf("-------------------------------------------------------------------------------\n");
        printf("Codigo de cliente: %d\t",eCliente[indice].codigoDeCliente);
        printf("Apellido: %s\t",eCliente[indice].apellido);
        printf("Nombre: %s\n",eCliente[indice].nombre);
        printf("Domicilio: %s\t",eCliente[indice].domicilio);
        printf("Telefono: %s\n",eCliente[indice].telefono);
    }
    system("pause");
}

void abm_Informe_BuscarJuegoPorFecha(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ)
{
    int iteracion1,iteracion2,dia,mes,anio;
    system("cls");
    abm_Alquiler_Listar(eAlquiler,cantidadA);
    printf("\nIngrese la fecha de alquiler:");
    fflush(stdin);
    utn_getEntero(&dia,"\nDia: ","Error",0,31,1);
    fflush(stdin);
    utn_getEntero(&mes,"\nMes: ","Error",0,12,1);
    fflush(stdin);
    utn_getEntero(&anio,"\nAnio: ","Error",2000,3000,1);
    system("cls");
    for(iteracion1=0;iteracion1<cantidadA;iteracion1++)
    {
        if(eAlquiler[iteracion1].isEmpty == 0 && eAlquiler[iteracion1].eFecha.dia == dia && eAlquiler[iteracion1].eFecha.mes == mes && eAlquiler[iteracion1].eFecha.anio == anio)
        {
            for(iteracion2=0;iteracion2<cantidadJ;iteracion2++)
            {
                if(eJuego[iteracion2].isEmpty == 0 && eJuego[iteracion2].codigoDeJuego == eAlquiler[iteracion1].codigoDeJuego)
                {
                    printf("-------------------------------------------------------------------------------\n");
                    printf("Codigo de juego: %d\t",eJuego[iteracion2].codigoDeJuego);
                    printf("Descripcion: %s\t",eJuego[iteracion2].descripcion);
                    printf("Importe: %f\n",eJuego[iteracion2].importe);
                }
            }
        }
    }
    printf("\n\nALQUILADOS EL %d/%d/%d.",dia,mes,anio);
}

void abm_Informe_BuscarClientePorFecha(alquileres* eAlquiler,int cantidadA,cliente* eCliente,int cantidadC)
{
    int iteracion1,iteracion2,dia,mes,anio;
    system("cls");
    abm_Alquiler_Listar(eAlquiler,cantidadA);
    printf("\nIngrese la fecha del alquiler:");
    fflush(stdin);
    fflush(stdin);
    utn_getEntero(&dia,"\nDia: ","Error",0,31,1);
    fflush(stdin);
    utn_getEntero(&mes,"\nMes: ","Error",0,12,1);
    fflush(stdin);
    utn_getEntero(&anio,"\nAnio: ","Error",2000,3000,1);
    system("cls");
    for(iteracion1=0;iteracion1<cantidadA;iteracion1++)
    {
        if(eAlquiler[iteracion1].isEmpty == 0 && eAlquiler[iteracion1].eFecha.dia == dia && eAlquiler[iteracion1].eFecha.mes == mes && eAlquiler[iteracion1].eFecha.anio == anio)
        {
            for(iteracion2=0;iteracion2<cantidadC;iteracion2++)
            {
                if(eCliente[iteracion2].isEmpty == 0 && eCliente[iteracion2].codigoDeCliente == eAlquiler[iteracion1].codigoDeCliente)
                {
                    printf("-------------------------------------------------------------------------------\n");
                    printf("Codigo de cliente: %d\t",eCliente[iteracion2].codigoDeCliente);
                    printf("Apellido: %s\t",eCliente[iteracion2].apellido);
                    printf("Nombre: %s\n",eCliente[iteracion2].nombre);
                    printf("Domicilio: %s\t",eCliente[iteracion2].domicilio);
                    printf("Telefono: %s\n",eCliente[iteracion2].telefono);
                }
            }
        }
    }
    printf("\n\nALQUILARON EL %d/%d/%d.",dia,mes,anio);
}
