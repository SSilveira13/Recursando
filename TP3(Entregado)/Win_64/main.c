#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int flag = 0;
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        printf("MENU \n1.Cargar archivo de texto \n2.Cargar archivo binario");
        printf("\n3.Alta \n4.Editar empleado \n5.Baja \n6.Listar \n7.Ordenar");
        printf("\n8.Guardar en archivo de texto \n9.Guardar en archivo binario \n10.Salir\n");
        utn_getEntero(&option,"","Opcion incorrecta",1,10,9);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                flag = 1;
                break;
            case 2:
                controller_loadFromBinary("data.csv",listaEmpleados);
                flag = 1;
                break;
            case 3:
                if(flag)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 4:
                if(flag)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 5:
                if(flag)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 6:
                if(flag)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 7:
                if(flag)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 8:
                if(flag)
                {
                    controller_saveAsText("info.csv",listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 9:
                if(flag)
                {
                    controller_saveAsBinary("info.bin",listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
                break;
            case 10:
                //salir
                break;
        }
    }while(option != 10);
    return 0;
}
