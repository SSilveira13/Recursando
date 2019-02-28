#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Socios.h"
#include "utn.h"

void main_menu()
{
    printf("MENU\n\n1_Alta.\n2_Modificar.\n3_Baja.\n4_listar.\n5_Fichajes.\n6_Informar empleados presentes.\n7_Salir.");
}

Socios* socio_nuevo()
{
    Socios *aux, *retorno=NULL;
    aux = (Socios*)malloc(sizeof(Socios));
    if(aux!=NULL)
    {
        retorno = aux;
    }
    return retorno;
}

Fichajes* fichaje_nuevo()
{
    Fichajes *aux, *retorno=NULL;
    aux = (Fichajes*)malloc(sizeof(Fichajes));
    if(aux!=NULL)
    {
        retorno = aux;
    }
    return retorno;
}

int socio_parametros(Socios *aux,char *var1,char *var2,char *var3,char *var4,char *var5)
{
    int id,dni,retorno = -1;
    if(aux!=NULL)
    {
        retorno = 0;
        id = atoi(var1);
        dni = atoi(var4);
        socio_setId(aux,id);
        socio_setNombre(aux,var2);
        socio_setApellido(aux,var3);
        socio_setDni(aux,dni);
        socio_setClave(aux,var5);
    }
    return retorno;
}

int fichaje_parametros(Fichajes *aux,char *var1,char *var2,char *var3,char *var4,char *var5,char *var6,char *var7,char *var8)
{
    int id_fichaje,id_empleado,horas,minutos,dia,mes,anio,retorno = -1;
    if(aux!=NULL)
    {
        retorno = 0;
        id_fichaje = atoi(var1);
        id_empleado = atoi(var2);
        horas = atoi(var3);
        minutos = atoi(var4);
        dia = atoi(var5);
        mes = atoi(var6);
        anio = atoi(var7);
        fichaje_setIdFichaje(aux,id_fichaje);
        fichaje_setIdEmpleado(aux,id_empleado);
        fichaje_setHoras(aux,horas);
        fichaje_setMinutos(aux,minutos);
        fichaje_setDia(aux,dia);
        fichaje_setMes(aux,mes);
        fichaje_setAnio(aux,anio);
        fichaje_setInOut(aux,var8);
    }
    return retorno;
}

int socio_setId(Socios* this,int id)
{
    int retorno = -1;
    if(id >= 0 && this!=NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int socio_getId(Socios* this,int* id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int socio_setNombre(Socios* this,char* nombre)
{
    int retorno = -1;
    if(nombre != NULL && this != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}
int socio_getNombre(Socios* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int socio_setApellido(Socios* this,char* apellido)
{
    int retorno = -1;
    if(apellido != NULL && this != NULL)
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}
int socio_getApellido(Socios* this,char* apellido)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        strcpy(apellido,this->apellido);
    }
    return retorno;
}

int socio_setDni(Socios* this,int dni)
{
    int retorno = -1;
    if(dni >= 0 && this!=NULL)
    {
        this->dni = dni;
        retorno = 0;
    }
    return retorno;
}
int socio_getDni(Socios* this,int* dni)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *dni = this->dni;
    }
    return retorno;
}

int socio_setClave(Socios* this,char* clave)
{
    int retorno = -1;
    if(clave != NULL && this != NULL)
    {
        strcpy(this->clave,clave);
        retorno = 0;
    }
    return retorno;
}
int socio_getClave(Socios* this,char* clave)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        strcpy(clave,this->clave);
    }
    return retorno;
}


int fichaje_setIdFichaje(Fichajes* this,int id_fichaje)
{
    int retorno = -1;
    if(id_fichaje >= 0 && this!=NULL)
    {
        this->id_fichaje = id_fichaje;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getIdFichaje(Fichajes* this,int* id_fichaje)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *id_fichaje = this->id_fichaje;
    }
    return retorno;
}

int fichaje_setIdEmpleado(Fichajes* this,int id_empleado)
{
    int retorno = -1;
    if(id_empleado >= 0 && this!=NULL)
    {
        this->id_empleado = id_empleado;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getIdEmpleado(Fichajes* this,int* id_empleado)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *id_empleado = this->id_empleado;
    }
    return retorno;
}

int fichaje_setHoras(Fichajes* this,int horas)
{
    int retorno = -1;
    if(horas >= 0 && this!=NULL)
    {
        this->horas = horas;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getHoras(Fichajes* this,int* horas)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *horas = this->horas;
    }
    return retorno;
}

int fichaje_setMinutos(Fichajes* this,int minutos)
{
    int retorno = -1;
    if(minutos >= 0 && this!=NULL)
    {
        this->minutos = minutos;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getMinutos(Fichajes* this,int* minutos)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *minutos = this->minutos;
    }
    return retorno;
}

int fichaje_setDia(Fichajes* this,int dia)
{
    int retorno = -1;
    if(dia >= 0 && this!=NULL)
    {
        this->dia = dia;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getDia(Fichajes* this,int* dia)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *dia = this->dia;
    }
    return retorno;
}

int fichaje_setMes(Fichajes* this,int mes)
{
    int retorno = -1;
    if(mes >= 0 && this!=NULL)
    {
        this->mes = mes;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getMes(Fichajes* this,int* mes)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *mes = this->mes;
    }
    return retorno;
}

int fichaje_setAnio(Fichajes* this,int anio)
{
    int retorno = -1;
    if(anio >= 0 && this!=NULL)
    {
        this->anio = anio;
        retorno = 0;
    }
    return retorno;
}
int fichaje_getAnio(Fichajes* this,int* anio)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        *anio = this->anio;
    }
    return retorno;
}

int fichaje_setInOut(Fichajes* this,char* ingreso_egreso)
{
    int retorno = -1;
    if(ingreso_egreso != NULL && this != NULL)
    {
        strcpy(this->ingreso_egreso,ingreso_egreso);
        retorno = 0;
    }
    return retorno;
}
int socio_getInOut(Fichajes* this,char* ingreso_egreso)
{
    int retorno = -1;
    if(this!=NULL)
    {
        retorno = 0;
        strcpy(ingreso_egreso,this->ingreso_egreso);
    }
    return retorno;
}

int socio_alta(LinkedList* this)
{
    int retorno = -1,dni;
    char nombre[51],apellido[51],clave[21];
    if(this!=NULL)
    {
        Socios* aux;
        aux = socio_nuevo();
        if(aux!=NULL)
        {
            utn_getCadena(nombre,"Ingrese nombre: ","Error",2);
            utn_getCadena(apellido,"Ingrese apellido: ","Error",2);
            utn_getEntero(&dni,"Ingrese DNI: ","Error",0,99999999,2);
            utn_getCadena(clave,"Ingrese clave: ","Error",2);
            strcpy(aux->nombre,nombre);
            strcpy(aux->apellido,apellido);
            strcpy(aux->clave,clave);
            aux->dni = dni;
            aux->id = ll_len(this) + 1;
            if(ll_add(this,aux)==0)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}

void socio_mod(LinkedList* this)
{
    int option,id;
    void* aux;
    int enteroA;
    char cadenaA[51];
    utn_getEntero(&id,"Ingresar ID: ","Error",0,ll_len(this),2);
    aux = ll_get(this,id);
    utn_getEntero(&option,"MENU MOD\n1_Nombre\n2_Apellido\n3_DNI\n4_Clave","Error",1,4,2);
    system("cls");
    switch(option)
    {
        case 1:
            utn_getCadena(cadenaA,"Nuevo nombre: ","Error",1);
            socio_setNombre(aux,cadenaA);
            break;
        case 2:
            utn_getCadena(cadenaA,"Nuevo apellido: ","Error",1);
            socio_setApellido(aux,cadenaA);
            break;
        case 3:
            utn_getEntero(&enteroA,"Nuevo DNI: ","Error",1,99999999,1);
            socio_setDni(aux,enteroA);
            break;
        case 4:
            utn_getCadena(cadenaA,"Nueva clave: ","Error",1);
            socio_setClave(aux,cadenaA);
            break;
    }
}

void socio_baja(LinkedList* this)
{
    int id;
    utn_getEntero(&id,"Ingresar ID: ","Error",0,ll_len(this),2);
    ll_remove(this,id);
}

void socio_listar(LinkedList* this)
{
    int index;
    Socios* aux;
    for(index=0;index<ll_len(this);index++)
    {
         aux=(Socios*)ll_get(this,index);
         printf("ID: %d\tNombre: %s\tApellido: %s\tDni: %d\n",aux->id,aux->nombre,aux->apellido,aux->dni);
    }
}

void socio_fichaje(LinkedList* this)
{
    int numero_unico,idEmp,hora,min,dia,mes,anio;
    Fichajes* aux;
    aux = (Fichajes*)ll_get(this,ll_len(this));
    numero_unico = aux->id_fichaje + 1;
    aux = fichaje_nuevo();
    if(aux!=NULL)
    {
        utn_getEntero(&idEmp,"Ingrese el id del empleado: ","Error",0,999999,1);

    }
}
