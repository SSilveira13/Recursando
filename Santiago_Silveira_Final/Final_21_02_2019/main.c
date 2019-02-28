#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Socios.h"

int main()
{
    LinkedList* this_empleados;
    this_empleados = ll_newLinkedList();
    LinkedList* this_fichajes;
    this_fichajes = ll_newLinkedList();
    FILE* archivo_empleados;
    FILE* archivo_fichajes;
    archivo_empleados = fopen("socios.csv","r");
    archivo_fichajes = fopen("fichajes.csv","r");
    if(parser_SociosFromText(archivo_empleados,this_empleados)==0)
    {
        printf("Se cargo el archivo: empleados.csv\n");
    }
    if(parser_FichajesFromText(archivo_fichajes,this_fichajes)==0)
    {
        printf("Se cargo el archivo: fichajes.csv\n");
    }
    system("pause");
    int option = 0;
    do{
        system("cls");
        main_menu();
        utn_getEntero(&option,"","Error en el menu",1,7,1);
        switch(option)
        {
            case 1://ALTA
                system("cls");
                socio_alta(this_empleados);
                break;
            case 2://MOD
                system("cls");
                socio_mod(this_empleados);
                break;
            case 3://BAJA
                system("cls");
                socio_baja(this_empleados);
                break;
            case 4://LISTAR
                system("cls");
                socio_listar(this_empleados);
                break;
            case 5://FICHAJE
                system("cls");

                break;
            case 6://INFORMAR PRESENTES
                system("cls");

                break;
            case 7://SALIR
                break;
        }
    }while(option!=7);
    return 0;
}
