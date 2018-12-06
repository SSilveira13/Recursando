#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArch;
    pArch = fopen(path,"r");
    if(path!=NULL && pArrayListEmployee!=NULL && pArch!=NULL)
    {
        parser_EmployeeFromText(pArch, pArrayListEmployee);
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pArch;
    pArch = fopen(path,"rb");
    if(path!=NULL && pArrayListEmployee!=NULL && pArch!=NULL)
    {
        parser_EmployeeFromBinary(pArch,pArrayListEmployee);
    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee!=NULL)
    {
        Employee* aux;
        aux = employee_new();
        //aux = (Employee*)malloc(sizeof(Employee));
        int id,sueldo,horas;
        char nombre[25];
        utn_getEntero(&id,"Ingrese el id: ","ID invalido.",0,9999,1);
        utn_getCadena(nombre,"\nIngrese el nombre: ","Error",1);
        utn_getEntero(&sueldo,"Ingrese el sueldo: ","sueldo invalido.",1,9999,1);
        utn_getEntero(&horas,"\nIngrese las horas trabajadas: ","Horas invalidas.",1,100,1);
        employee_setId(aux,id);
        employee_setNombre(aux,nombre);
        employee_setSueldo(aux,sueldo);
        employee_setHorasTrabajadas(aux,horas);
        ll_add(pArrayListEmployee,aux);
    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxE;
    int index,option = 0,auxI;
    char auxC[25];
    if(pArrayListEmployee!=NULL)
    {
        printf("Ingrese el indice: ");
        scanf("%d",&index);
        auxE = (Employee*)ll_get(pArrayListEmployee,index);

        do{
            system("cls");
            printf("\n1.ID\n2.Nombre\n3.Horas trabajadas\n4.Sueldo\n5.Salir");
            scanf("%d",&option);
            switch(option)
            {
                case 1:
                    system("cls");
                    utn_getEntero(&auxI,"Ingrese ID nuevo: ","Error",0,9999,1);
                    employee_setId(auxE,auxI);
                    break;
                case 2:
                    system("cls");
                    utn_getCadena(auxC,"Ingrese nombre nuevo: ","Error",1);
                    employee_setNombre(auxE,auxC);
                    break;
                case 3:
                    system("cls");
                    utn_getEntero(&auxI,"Ingrese horas de trabajo: ","Error",0,300,1);
                    employee_setId(auxE,auxI);
                    break;
                case 4:
                    system("cls");
                    utn_getEntero(&auxI,"Ingrese sueldo nuevo: ","Error",0,9999,1);
                    employee_setId(auxE,auxI);
                    break;
                case 5://salir
                    break;
            }
        }while(option!=5);
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int index;
    if(pArrayListEmployee!=NULL)
    {
        printf("Ingrese el indice: ");
        scanf("%d",&index);
        ll_remove(pArrayListEmployee,index);
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee!=NULL)
    {
        int index,id,horas,sueldo;
        char nombre[51];
        Employee* aux;
        for(index=0;index<=ll_len(pArrayListEmployee);index++)
        {
            aux = (Employee*)ll_get(pArrayListEmployee,index);
            employee_getId(aux,&id);
            employee_getNombre(aux,nombre);
            employee_getHorasTrabajadas(aux,&horas);
            employee_getSueldo(aux,&sueldo);
            if(aux!=NULL)
            {
                printf("ID: %d\tNombre: %s\nHoras: %d\tSueldo: %d\tIndice: %d\n\n",id,nombre,horas,sueldo,index);
            }
        }
        system("pause");
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* this)
{
    int returnAux = -1;
    void* elementoA;
    void* elementoB;
    void* elementoAuxiliar;
    int index;
    int comp;
    if(this!=NULL)
    {
        //ll_sort(pArrayListEmployee,ordenarNombre,0);
        for(index=0;index<ll_len(this);index++)
        {
            for(comp=index+1;comp<ll_len(this);comp++)
            {
                elementoA = ll_get(this,index);
                elementoB = ll_get(this,comp);
                if(ordenarNombre(elementoA,elementoB)==1)
                {
                    elementoAuxiliar = elementoA;
                    ll_set(this,index,elementoB);
                    ll_set(this,comp,elementoAuxiliar);
                }
                if(ordenarNombre(elementoA,elementoB)==-1)
                {
                    elementoAuxiliar = elementoA;
                    ll_set(this,index,elementoB);
                    ll_set(this,comp,elementoAuxiliar);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* bin;
        Employee* aux;
        int index,id,sueldo,horas;
        char nombre[51];
        system("pause");
        printf("\nSe va a generar por primera vez el archivo\n");
        if ((bin=fopen(path,"w"))==NULL)
        {
            printf("El archivo no puede ser abierto");
        }
        else
        {
            for(index=0;index<=ll_len(pArrayListEmployee);index++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee,index);
                employee_getId(aux,&id);
                employee_getNombre(aux,nombre);
                employee_getHorasTrabajadas(aux,&horas);
                employee_getSueldo(aux,&sueldo);
                if(aux!=NULL)
                {
                    fprintf(bin,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
                }
            }
        }
        fclose(bin);
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* bin;
        Employee* aux;
        int index;
        system("pause");
        printf("\nSe va a generar por primera vez el archivo\n");
        if ((bin=fopen(path,"wb"))==NULL)
        {
            printf("El archivo no puede ser abierto");
        }
        else
        {
            for(index=0;index<=ll_len(pArrayListEmployee);index++)
            {
                aux = (Employee*)ll_get(pArrayListEmployee,index);
                if(aux!=NULL)
                {
                    fwrite(aux,sizeof(Employee),1,bin);
                }
            }
        }
        fclose(bin);
    }
    return 1;
}

