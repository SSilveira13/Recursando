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

/** \brief  Toma el array de empleados y lo imprime por pantalla
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_imprimirEmpleados(persona eEmpleado[],int cantidad);

/** \brief  Muestra la lista de empleados y da de baja uno mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Baja(persona eEmpleado[],int cantidad);

/** \brief  Muestra la lista de empleados y da opcion a modificar todos los parametros excepto el indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Modificar(persona eEmpleado[],int cantidad);

/** \brief  Modifica el nombre del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void nombreMod(persona eEmpleado[],int indice);

/** \brief  Modifica el apellido del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void apellidoMod(persona eEmpleado[],int indice);

/** \brief  Modifica el dni del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void dniMod(persona eEmpleado[],int indice);

/** \brief  Modifica la fecha de nacimiento del empleado mediante su indice
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void fechaDeNacimientoMod(persona eEmpleado[],int indice);


/** \brief  Da de alta el dni del empleado con la condicion de que no se repita
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param indice int    Indice del empleado a dar de alta
 * \param cantidad int  Cantidad de empleados del array
 * \return int Retorna 0 si no hay problemas y -1 si el dni ya se encuentra en uso
 *
 */
int dniUnico(persona eEmpleado[],int indice,int cantidad);

/** \brief  Ordena alfabeticamente la lista de empleados
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param cantidad int  Cantidad de empleados del array
 * \return void
 *
 */
void abm_Ordenar(persona eEmpleado[],int cantidad);


/** \brief  Intercambia el indice de dos empleados dentro del array
 *
 * \param eEmpleado[] persona   Array de empleados
 * \param indice1 int   Indice del primer empleado
 * \param indice2 int   Indice del Segundo empleado
 * \return void
 *
 */
void intercambio(persona eEmpleado[],int indice1,int indice2);

#endif
