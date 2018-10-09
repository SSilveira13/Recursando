#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
int dia;
int mes;
int anio;
}fecha;

typedef struct{
int codigoDeJuego;
char descripcion[51];
float importe;
int isEmpty;
}juegos;

typedef struct{
int codigoDeCliente;
char apellido[51];
char nombre[51];
char domicilio[51];
char telefono[21];
int isEmpty;
}cliente;

typedef struct{
int codigoDeAlquiler;
int codigoDeJuego;
int codigoDeCliente;
fecha eFecha;
int isEmpty;
}alquileres;

/** \brief  Imprime el menu de opciones principales en pantalla
 *
 * \return void
 *
 */
void abm_Menu();

/** \brief Imprime el menu de opciones de juegos en pantalla
 *
 * \return void
 *
 */
void abm_Menu_Juegos();

/** \brief Imprime el menu de opciones de clientes en pantalla
 *
 * \return void
 *
 */
void abm_Menu_Clientes();

/** \brief Imprime el menu de opciones de alquileres en pantalla
 *
 * \return void
 *
 */
void abm_Menu_Alquileres();

/** \brief Imprime el menu de opciones de informacion extra en pantalla
 *
 * \return void
 *
 */
void abm_Menu_Informes();

/** \brief  Inicializa todas las listas
 *
 * \param eCliente cliente* Array de clientes
 * \param cantidadC int Cantidad de clientes
 * \param eJuego juegos*    Array de juegos
 * \param cantidadJ int Cantiadad de juegos
 * \param eAlquiler alquileres* Array de alquileres
 * \param cantidadA int Cantidad de alquileres
 * \return void
 *
 */
void abm_Inicializar(cliente* eCliente,int cantidadC,juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA);

/** \brief  Busca un espacio vacio del array de clientes
 *
 * \param eJuego juegos*    Array de juegos
 * \param cantidadJ int Cantidad de juegos
 * \return int  Retorna el indice del espacio vacio y en caso de error retorna -1
 *
 */
int abm_Juego_espacioVacio(juegos* eJuego,int cantidadJ);

/** \brief  Busca un espacio vacio del array de clientes
 *
 * \param eCliente cliente* Array de clientes
 * \param cantidadC int Cantidad de clientes
 * \return int  Retorna el indice del espacio vacio y en caso de error retorna -1
 *
 */
int abm_Cliente_espacioVacio(cliente* eCliente,int cantidadC);

/** \brief  Da de alta un juego en la lista
 *
 * \param eJuego juegos*    Array de juegos
 * \param cantidad int  Cantidad de juegos
 * \return int  Retorna -1 en caso de error y 0 en caso exitoso
 *
 */
int abm_Juego_Alta(juegos* eJuego,int cantidad);

/** \brief  Da de alta un cliente en la lista
 *
 * \param eCliente cliente* Array de clientes
 * \param cantidad int  Cantidad de clientes
 * \return int  Retorna -1 en caso de error y 0 en caso exitoso
 *
 */
int abm_Cliente_Alta(cliente* eCliente,int cantidad);

/** \brief  Da las instrucciones para llenar el formulario de un juego
 *
 * \param eJuego juegos*    Array de juegos
 * \param vacio int Espacio vacio necesario para llenar el formulario
 * \param cantidadJ int Cantidad de juegos
 * \return int  Retorna -1 en caso de error y 0 en caso exitoso
 *
 */
int abm_ingresaJuego(juegos* eJuego,int vacio,int cantidadJ);

/** \brief  Da las instrucciones para llenar el formulario de un cliente
 *
 * \param eCliente cliente* Array de clientes
 * \param vacio int Espacio vacio necesario para llenar el formulario
 * \param cantidadC int Cantidad de clientes
 * \return int  Retorna -1 en caso de error y 0 en caso exitoso
 *
 */
int abm_ingresaCliente(cliente* eCliente,int vacio,int cantidadC);

int abm_Juego_Modificar(juegos* eJuego,int cantidadJ);

int abm_Cliente_Modificar(cliente* eCliente,int cantidadC);

void abm_imprimirJuegos(juegos* eJuego,int cantidadJ);

void abm_imprimirClientes(cliente* eCliente,int cantidadC);

int juego_buscarPorCodigo(juegos* eJuego,int cantidadJ,int codigo);

int cliente_buscarPorCodigo(cliente* eCliente,int cantidadC,int codigo);

int abm_Juego_Baja(juegos* eJuego,int cantidadJ);

int abm_Cliente_Baja(cliente* eCliente,int cantidadC);

void juego_ordenar(juegos* eJuego,int cantidadJ);

void cliente_ordenar(cliente* eCliente,int cantidadC);

void juego_intercambio(juegos* eJuego,int indice1,int indice2);

void cliente_intercambio(cliente* eCliente,int indice1,int indice2);

int abm_juego_Listar(juegos* eJuego,int cantidadJ);

int abm_cliente_Listar(cliente* eCliente,int cantidadC);

int abm_Alquiler_espacioVacio(alquileres* eAlquiler,int cantidadA);

int abm_Alquiler_Alta(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC);

int abm_ingresaAlquiler(alquileres* eAlquiler,int vacio,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC);

void abm_Alquiler_Listar(alquileres* eAlquiler,int cantidadA);


void abm_Informe_ImportePyT(juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA);

void abm_Informe_PromedioYtotal(juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA,float* total,float* promedio);

void abm_Informe_JuegosDebajoDelPromedio(juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA);

void abm_Informe_BuscarClientePorJuego(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC);

void abm_Informe_BuscarJuegoPorCliente(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ,cliente* eCliente,int cantidadC);

void abm_Informe_JuegosMenosAlquilados(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ);

void abm_Informe_ClientesConMasAlquileres(alquileres* eAlquiler,int cantidadA,cliente* eCliente,int cantidadC);

void abm_Informe_BuscarJuegoPorFecha(alquileres* eAlquiler,int cantidadA,juegos* eJuego,int cantidadJ);

void abm_Informe_BuscarClientePorFecha(alquileres* eAlquiler,int cantidadA,cliente* eCliente,int cantidadC);

void abm_Informe_BurbujeoImporteJuegos(juegos* eJuego,int cantidadJ);

#endif
