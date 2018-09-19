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
    printf("****AGENDA****\n\n");
    printf("1_Alta.\n");
    printf("2_Baja.\n");
    printf("3_Modificacion.\n");
    printf("4_Lista.\n");
    printf("5_Ordenar.\n");
    printf("6_Salir.\n");
}

void abm_Alta(persona eEmpleado[],int cantidad)
{
    char alta = 's';
    do{
        //system("clr");
        if(abm_ingresaEmpleado(eEmpleado,abm_espacioVacio(eEmpleado,cantidad),cantidad) == -1)
        {
            break;
        }
        printf("\n\nQuiere seguir ingresando?(s/n) ");
        fflush(stdin);
        scanf("%c",&alta);
    }while(alta == 's');
}

int abm_ingresaEmpleado(persona eEmpleado[],int vacio,int cantidad)
{
    int retorno = -1;
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s",eEmpleado[vacio].nombre);
    printf("\nApellido: ");
    fflush(stdin);
    scanf("%s",eEmpleado[vacio].apellido);
    if(dniUnico(eEmpleado,vacio,cantidad) == -1)
    {
        //system("clr");
        printf("Error el dni ya se encuentra registrado.");
    }
    else
    {
        printf("\nFecha de nacimiento(dd/mm/aaaa): ");
        fflush(stdin);
        scanf("%d/%d/%d",&eEmpleado[vacio].fechaNacimiento.dia,&eEmpleado[vacio].fechaNacimiento.mes,&eEmpleado[vacio].fechaNacimiento.anio);
        eEmpleado[vacio].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
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

void abm_imprimirEmpleados(persona eEmpleado[],int cantidad)
{
    int iteracion;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            printf("-------------------------------------------------------------------------------\n");
            printf("Indice: %d\t",iteracion);
            printf("Nombre: %s\t",eEmpleado[iteracion].nombre);
            printf("Apellido: %s\n",eEmpleado[iteracion].apellido);
            printf("DNI: %ld\t",eEmpleado[iteracion].dni);
            printf("Fecha de nacimiento: %d/%d/%d\n",eEmpleado[iteracion].fechaNacimiento.dia,eEmpleado[iteracion].fechaNacimiento.mes,eEmpleado[iteracion].fechaNacimiento.anio);
        }
    }
}

void abm_Baja(persona eEmpleado[],int cantidad)
{
    //system("clr");
    int indice;
    abm_imprimirEmpleados(eEmpleado,cantidad);
    printf("\n\nIngrese el indice a dar de baja: ");
    fflush(stdin);
    scanf("%d",&indice);
    eEmpleado[indice].isEmpty = 1;
}

void abm_Modificar(persona eEmpleado[],int cantidad)
{
    //system("clr");
    int indice,modificar;
    abm_imprimirEmpleados(eEmpleado,cantidad);
    printf("\n\nIngrese el indice a modificar: ");
    fflush(stdin);
    scanf("%d",&indice);
    printf("1_Nombre: %s\n",eEmpleado[indice].nombre);
    printf("2_Apellido: %s\n",eEmpleado[indice].apellido);
    printf("3_DNI: %ld\n",eEmpleado[indice].dni);
    printf("4_Fecha de nacimiento: %d/%d/%d\n",eEmpleado[indice].fechaNacimiento.dia,eEmpleado[indice].fechaNacimiento.mes,eEmpleado[indice].fechaNacimiento.anio);
    fflush(stdin);
    scanf("%d",&modificar);
    system("clr");
    switch(modificar)
    {
        case 1:
            nombreMod(eEmpleado,indice);
            break;
        case 2:
            apellidoMod(eEmpleado,indice);
            break;
        case 3:
            dniMod(eEmpleado,indice);
            break;
        case 4:
            fechaDeNacimientoMod(eEmpleado,indice);
            break;
        default:
            break;
    }
}

void nombreMod(persona eEmpleado[],int indice)
{
    char auxiliar[31];
    printf("Nombre nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(eEmpleado[indice].nombre,auxiliar);
}

void apellidoMod(persona eEmpleado[],int indice)
{
    char auxiliar[31];
    printf("Apelldio nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(eEmpleado[indice].apellido,auxiliar);
}

void dniMod(persona eEmpleado[],int indice)
{
    printf("DNI nuevo: ");
    fflush(stdin);
    scanf("%ld",&eEmpleado[indice].dni);
}

void fechaDeNacimientoMod(persona eEmpleado[],int indice)
{
    printf("Fecha de nacimiento nueva(dd/mm/aaaa): ");
    fflush(stdin);
    scanf("%d/%d/%d",&eEmpleado[indice].fechaNacimiento.dia,&eEmpleado[indice].fechaNacimiento.mes,&eEmpleado[indice].fechaNacimiento.anio);
}

int dniUnico(persona eEmpleado[],int indice,int cantidad)
{
    int retorno = 0;
    int iteracion,comparacion;
    printf("\nDNI: ");
    fflush(stdin);
    scanf("%ld",&eEmpleado[indice].dni);
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidad;comparacion++)
            {
                if((eEmpleado[comparacion].isEmpty == 0) && (eEmpleado[iteracion].dni == eEmpleado[comparacion].dni))
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

void abm_Ordenar(persona eEmpleado[],int cantidad)
{
    int iteracion,comparacion;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidad;comparacion++)
            {
                if((eEmpleado[comparacion].isEmpty==0) && (strcmp(eEmpleado[iteracion].apellido,eEmpleado[comparacion].apellido)>0))
                {
                    intercambio(eEmpleado,iteracion,comparacion);
                }
                else if((eEmpleado[comparacion].isEmpty==0) && (strcmp(eEmpleado[iteracion].apellido,eEmpleado[comparacion].apellido)==0))
                {
                    intercambio(eEmpleado,iteracion,comparacion);
                }
            }
        }
    }
    abm_imprimirEmpleados(eEmpleado,cantidad);
}

void intercambio(persona eEmpleado[],int indice1,int indice2)
{
    persona aux;
    aux = eEmpleado[indice1];
    eEmpleado[indice1] = eEmpleado[indice2];
    eEmpleado[indice2] = aux;
}
