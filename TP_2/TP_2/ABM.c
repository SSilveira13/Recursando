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
    printf("2_Modificacion.\n");
    printf("3_Baja.\n");
    printf("4_Informar.\n");
    printf("5_Salir.\n");
}

int abm_Alta(persona eEmpleado[],int cantidad)//listo
{
    int retorno=0;
    char alta = 's';
    do{
        system("cls");
        if(abm_ingresaEmpleado(eEmpleado,abm_espacioVacio(eEmpleado,cantidad),cantidad) == -1)
        {
            retorno=-1;
            break;
        }
        printf("\n\nQuiere seguir ingresando?(s/n) ");
        fflush(stdin);
        scanf("%c",&alta);
    }while(alta == 's');
    return retorno;
}

int abm_ingresaEmpleado(persona eEmpleado[],int vacio,int cantidad)//listo
{
    int retorno = -1;
    printf("Nombre: ");
    fflush(stdin);
    scanf("%s",eEmpleado[vacio].nombre);
    printf("\nApellido: ");
    fflush(stdin);
    scanf("%s",eEmpleado[vacio].apellido);
    eEmpleado[vacio].id = vacio + 1;
    printf("\nSalario: ");
    fflush(stdin);
    scanf("%f",&eEmpleado[vacio].salario);
    printf("\nSector: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[vacio].sector);
    eEmpleado[vacio].isEmpty = 0;
    retorno = 0;
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

void abm_imprimirEmpleados(persona eEmpleado[],int cantidad)//listo
{
    int iteracion;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            printf("-------------------------------------------------------------------------------\n");
            printf("Id: %d\t",eEmpleado[iteracion].id);
            printf("Nombre: %s\t",eEmpleado[iteracion].nombre);
            printf("Apellido: %s\n",eEmpleado[iteracion].apellido);
            printf("ID: %d\t",eEmpleado[iteracion].id);
            printf("Salario: %f\t",eEmpleado[iteracion].salario);
            printf("Sector: %d\t",eEmpleado[iteracion].sector);
        }
    }
}

void abm_Baja(persona eEmpleado[],int cantidad)//listo
{
    system("cls");
    int id,indice;
    abm_imprimirEmpleados(eEmpleado,cantidad);
    printf("\n\nIngrese el id del empleado a dar de baja: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarId(eEmpleado,cantidad,id);
    eEmpleado[indice].isEmpty = 1;
}

void abm_Modificar(persona eEmpleado[],int cantidad)
{
    system("cls");
    int indice,id,modificar;
    abm_imprimirEmpleados(eEmpleado,cantidad);
    printf("\n\nIngrese el id del empleado a modificar: ");
    fflush(stdin);
    scanf("%d",&id);
    indice = buscarId(eEmpleado,cantidad,id);
    printf("1_Nombre: %s\n",eEmpleado[indice].nombre);
    printf("2_Apellido: %s\n",eEmpleado[indice].apellido);
    printf("3_Salario: %f\n",eEmpleado[indice].salario);
    printf("4_Sector: %d\n",eEmpleado[indice].sector);
    fflush(stdin);
    scanf("%d",&modificar);
    system("cls");
    switch(modificar)
    {
        case 1:
            nombreMod(eEmpleado,indice);
            break;
        case 2:
            apellidoMod(eEmpleado,indice);
            break;
        case 3:
            salarioMod(eEmpleado,indice);
            break;
        case 4:
            sectorMod(eEmpleado,indice);
            break;
        default:
            system("cls");
            printf("Error: opcion no valida.");
            break;
    }
}

void nombreMod(persona eEmpleado[],int indice)//listo
{
    char auxiliar[31];
    printf("Nombre nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(eEmpleado[indice].nombre,auxiliar);
}

void apellidoMod(persona eEmpleado[],int indice)//listo
{
    char auxiliar[31];
    printf("Apelldio nuevo: ");
    fflush(stdin);
    scanf("%s",auxiliar);
    strcpy(eEmpleado[indice].apellido,auxiliar);
}

void idMod(persona eEmpleado[],int indice)//listo
{
    printf("ID nuevo: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[indice].id);
}

void sectorMod(persona eEmpleado[],int indice)//listo
{
    printf("Sector nuevo: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[indice].sector);
}

void salarioMod(persona eEmpleado[],int indice)//listo
{
    printf("Salario nuevo: ");
    fflush(stdin);
    scanf("%f",&eEmpleado[indice].salario);
}

int idUnico(persona eEmpleado[],int indice,int cantidad)
{
    int retorno = 0;
    int iteracion,comparacion;
    printf("\nID: ");
    fflush(stdin);
    scanf("%d",&eEmpleado[indice].id);
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0)
        {
            for(comparacion=iteracion+1;comparacion<cantidad;comparacion++)
            {
                if((eEmpleado[comparacion].isEmpty == 0) && (eEmpleado[iteracion].id == eEmpleado[comparacion].id))
                {
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}

void abm_informarEmpleados(persona eEmpleado[],int cantidad)
{
    int iteracion,comparacion,contador=0;
    float totalSal,promedioSal;
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
                else if((eEmpleado[comparacion].isEmpty==0) && (eEmpleado[iteracion].sector<=eEmpleado[comparacion].sector))
                {
                    intercambio(eEmpleado,iteracion,comparacion);
                }
            }
        }
    }
    abm_imprimirEmpleados(eEmpleado,cantidad);
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty==0)
        {
            totalSal = totalSal + eEmpleado[iteracion].salario;
            contador++;
        }
    }
    printf("\nSalario total: %f\n",totalSal);
    promedioSal = totalSal / contador;
    printf("Promedio de salarios: %f\n",promedioSal);
    contador=0;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty==0 && eEmpleado[iteracion].salario>promedioSal)
        {
            contador++;
        }
    }
    printf("Cantidad de empleados que superan el salario promedio: %d",contador);
}

void intercambio(persona eEmpleado[],int indice1,int indice2)
{
    persona aux;
    aux = eEmpleado[indice1];
    eEmpleado[indice1] = eEmpleado[indice2];
    eEmpleado[indice2] = aux;
}

int buscarId(persona eEmpleado[],int cantidad,int id)
{
    int iteracion,retorno=-1;
    for(iteracion=0;iteracion<cantidad;iteracion++)
    {
        if(eEmpleado[iteracion].isEmpty == 0 && eEmpleado[iteracion].id == id)
        {
            retorno = iteracion;
            break;
        }
    }
    return retorno;
}
