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

/** \brief Inicializa el array de empleados poniendolos como vacios
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Inicializar(persona eEmpleado[],int cantidad);

/** \brief Imprime el menu de opciones principales
 *
 * \return void
 *
 */
void abm_Menu();

/** \brief Da de alta empleados hasta que ocurra un error
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Alta(persona eEmpleado[],int cantidad);

/** \brief Toma los datos de un empleado para darlo de alta
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param vacio int Indice del primer espacio vacio del array
 * \param cantidad int  Cantidad de empleados del array
 * \return int  Devuelve -1 en caso de error y 0 si se logra completar
 *
 */
int abm_ingresaEmpleado(persona eEmpleado[],int vacio,int cantidad);

/** \brief Busca el primer espacio vacio en el array
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return int Devuelve el indice del espacio vacio
 *
 */
int abm_espacioVacio(persona eEmpleado[],int cantidad);

void abm_imprimirEmpleados(persona eEmpleado[],int cantidad);

void abm_Baja(persona eEmpleado[],int cantidad);

void abm_Modificar(persona eEmpleado[],int cantidad);

void nombreMod(persona eEmpleado[],int indice);

void apellidoMod(persona eEmpleado[],int indice);

void dniMod(persona eEmpleado[],int indice);

void fechaDeNacimientoMod(persona eEmpleado[],int indice);

int dniUnico(persona eEmpleado[],int indice,int cantidad);

void abm_Ordenar(persona eEmpleado[],int cantidad);

void intercambio(persona eEmpleado[],int indice1,int indice2);

#endif
