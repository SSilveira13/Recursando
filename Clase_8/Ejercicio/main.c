#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int dia;
int mes;
int anio;
}fecha;

typedef struct{
long int dni;
int isEmpty;
char nombre[31];
char apellido[31];
fecha fechaNacimiento;
}persona;

void inicializar(persona eEmpleado[]);

int main()
{
    persona eEmpleado[200];
    inicializar(eEmpleado);
    int opcion,modificar;
    int i,vacio,indice;
    char auxiliar[31];
    char salida = 's';
    char alta = 's';
    do
    {
        system("clear");
        printf("1_Alta.\n");
        printf("2_Baja.\n");
        printf("3_Modificacion.\n");
        printf("4_Lista.\n");
        printf("5_Salir.\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                do{
                    system("clear");
                    for(i=0;i<200;i++)
                    {
                        if(eEmpleado[i].isEmpty == 1)
                        {
                            vacio = i;
                            break;
                        }
                    }
                    printf("Nombre: ");
                    fflush(stdin);
                    scanf("%s",eEmpleado[vacio].nombre);
                    printf("\nApellido: ");
                    fflush(stdin);
                    scanf("%s",eEmpleado[vacio].apellido);
                    printf("\nDNI: ");
                    fflush(stdin);
                    scanf("%ld",&eEmpleado[vacio].dni);
                    printf("\nFecha de nacimiento(dd/mm/aaaa): ");
                    fflush(stdin);
                    scanf("%d/%d/%d",&eEmpleado[vacio].fechaNacimiento.dia,&eEmpleado[vacio].fechaNacimiento.mes,&eEmpleado[vacio].fechaNacimiento.anio);
                    eEmpleado[vacio].isEmpty = 0;
                    printf("\n\nQuiere seguir ingresando?(s/n) ");
                    fflush(stdin);
                    scanf("%c",&alta);

                }while(alta == 's');
                break;
            case 2:
                system("clear");
                for(i=0;i<200;i++)
                {
                    if(eEmpleado[i].isEmpty == 0)
                    {
                        printf("-------------------------------------------------------------------------------\n");
                        printf("Indice: %d\t",i);
                        printf("Nombre: %s\t",eEmpleado[i].nombre);
                        printf("Apellido: %s\n",eEmpleado[i].apellido);
                        printf("DNI: %ld\t",eEmpleado[i].dni);
                        printf("Fecha de nacimiento: %d/%d/%d\n",eEmpleado[i].fechaNacimiento.dia,eEmpleado[i].fechaNacimiento.mes,eEmpleado[i].fechaNacimiento.anio);
                    }
                }
                printf("\n\nIngrese el indice a dar de baja: ");
                fflush(stdin);
                scanf("%d",&indice);
                eEmpleado[indice].isEmpty = 1;
                break;
            case 3:
                system("clear");
                for(i=0;i<200;i++)
                {
                    if(eEmpleado[i].isEmpty == 0)
                    {
                        printf("-------------------------------------------------------------------------------\n");
                        printf("Indice: %d\t",i);
                        printf("Nombre: %s\t",eEmpleado[i].nombre);
                        printf("Apellido: %s\n",eEmpleado[i].apellido);
                        printf("DNI: %ld\t",eEmpleado[i].dni);
                        printf("Fecha de nacimiento: %d/%d/%d\n",eEmpleado[i].fechaNacimiento.dia,eEmpleado[i].fechaNacimiento.mes,eEmpleado[i].fechaNacimiento.anio);
                    }
                }
                printf("\n\nIngrese el indice a dar modificar: ");
                fflush(stdin);
                scanf("%d",&indice);
                printf("1_Nombre: %s\n",eEmpleado[indice].nombre);
                printf("2_Apellido: %s\n",eEmpleado[indice].apellido);
                printf("3_DNI: %ld\n",eEmpleado[indice].dni);
                printf("4_Fecha de nacimiento: %d/%d/%d\n",eEmpleado[indice].fechaNacimiento.dia,eEmpleado[indice].fechaNacimiento.mes,eEmpleado[indice].fechaNacimiento.anio);
                fflush(stdin);
                scanf("%d",&modificar);
                system("clear");
                switch(modificar)
                {
                    case 1:
                        printf("Nombre nuevo: ");
                        fflush(stdin);
                        scanf("%s",auxiliar);
                        strcpy(eEmpleado[indice].nombre,auxiliar);
                        break;
                    case 2:
                        printf("Apelldio nuevo: ");
                        fflush(stdin);
                        scanf("%s",auxiliar);
                        strcpy(eEmpleado[indice].apellido,auxiliar);
                        break;
                    case 3:
                        printf("DNI nuevo: ");
                        fflush(stdin);
                        scanf("%ld",&eEmpleado[indice].dni);
                        break;
                    case 4:
                        printf("Fecha de nacimiento nueva(dd/mm/aaaa): ");
                        fflush(stdin);
                        scanf("%d/%d/%d",&eEmpleado[indice].fechaNacimiento.dia,&eEmpleado[indice].fechaNacimiento.mes,&eEmpleado[indice].fechaNacimiento.anio);
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                system("clear");
                for(i=0;i<200;i++)
                {
                    if(eEmpleado[i].isEmpty == 0)
                    {
                        printf("-------------------------------------------------------------------------------\n");
                        printf("Indice: %d\t",i);
                        printf("Nombre: %s\t",eEmpleado[i].nombre);
                        printf("Apellido: %s\n",eEmpleado[i].apellido);
                        printf("DNI: %ld\t",eEmpleado[i].dni);
                        printf("Fecha de nacimiento: %d/%d/%d\n",eEmpleado[i].fechaNacimiento.dia,eEmpleado[i].fechaNacimiento.mes,eEmpleado[i].fechaNacimiento.anio);
                    }
                }
                system("pause");
                break;
            case 5:
                salida = 'n';
                break;
            default:
                break;
        }

    }while(salida == 's');

    return 0;
}

void inicializar(persona eEmpleado[])
{
    int i;
    for(i=0;i<200;i++)
    {
        eEmpleado[i].isEmpty = 1;
    }
}
