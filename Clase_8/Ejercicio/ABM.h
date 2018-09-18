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

int abm_espacioVacio(persona eEmpleado[],int cantidad);

#endif
