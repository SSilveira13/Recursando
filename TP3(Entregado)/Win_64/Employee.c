#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
{
    Employee* retorno;
    retorno = malloc(sizeof(Employee));
    return retorno;
}

Employee* employee_newParametros(Employee* this,char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int id,horasTrabajadas,sueldo;
    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);
    employee_setId(this,id);
    employee_setHorasTrabajadas(this,horasTrabajadas);
    employee_setSueldo(this,sueldo);
    employee_setNombre(this,nombreStr);
    return this;
}

int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(id >= 0 && this!=NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(nombre != NULL && this != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(horasTrabajadas > 0 && this!=NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(sueldo > 0 && this!=NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *sueldo = this->sueldo;
    }
    return retorno;
}

int ordenarNombre(void* pPersonA,void* pPersonB)
{
    int retorno = 0;
    if(strcmp(((Employee*)pPersonA)->nombre,((Employee*)pPersonB)->nombre)>0)
    {
        retorno = 1;
    }
    if(strcmp(((Employee*)pPersonA)->nombre,((Employee*)pPersonB)->nombre)<0)
    {
        retorno = -1;
    }
    return retorno;
}
