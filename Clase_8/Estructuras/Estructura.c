#include <stdio.h>
#include <stdlib.h>
#include "Estructura.h"

void altaEmpleado(struct ePersona* eEmpleado)
{
    printf("Ingrese nombre del empleado: \n");
    fflush(stdin);
    scanf("%s",(*eEmpleado).nombre);
    printf("Ingrese legajo del empleado: \n");
    fflush(stdin);
    scanf("%d",eEmpleado->legajo);
    printf("Ingrese salario del empleado: \n");
    fflush(stdin);
    scanf("%f",eEmpleado->salario);
    (*eEmpleado).isEmpty = 1;
}

void informarEmpleado(struct ePersona* eEmpleado)
{
    printf("Nombre del empleado: %s",(*eEmpleado).nombre);
    printf("Legajo del empleado: %d",(*eEmpleado).legajo);
    printf("Salario del empleado: %f",(*eEmpleado).salario);
}

