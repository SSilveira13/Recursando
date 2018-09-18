#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

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

void abm_Inicializar(persona eEmpleado[],int cantidad);

void abm_Menu();

void abm_Alta(persona eEmpleado[],int cantidad);

void abm_ingresaEmpleado(persona eEmpleado[],int vacio);

int abm_espacioVacio(persona eEmpleado[],int cantidad);

void abm_imprimirEmpleados(persona eEmpleado[],int cantidad);

void abm_Baja(persona eEmpleado[],int cantidad);

void abm_Modificar(persona eEmpleado[],int cantidad);

void nombreMod(persona eEmpleado[],int indice);

void apellidoMod(persona eEmpleado[],int indice);

void dniMod(persona eEmpleado[],int indice);

void fechaDeNacimientoMod(persona eEmpleado[],int indice);



#endif
