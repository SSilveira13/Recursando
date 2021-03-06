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

void abm_Menu();

void abm_Inicializar(cliente* eCliente,int cantidadC,juegos* eJuego,int cantidadJ,alquileres* eAlquiler,int cantidadA);

int abm_Juego_espacioVacio(juegos* eJuego,int cantidadJ);

int abm_Cliente_espacioVacio(cliente* eCliente,int cantidadC);

int abm_Juego_Alta(juegos* eJuego,int cantidad);

int abm_Cliente_Alta(cliente* eCliente,int cantidad);

int abm_ingresaJuego(juegos* eJuego,int vacio,int cantidadJ);

int abm_ingresaCliente(cliente* eCliente,int vacio,int cantidadC);

int abm_Juego_Modificar(juegos* eJuego,int cantidadJ);

int abm_Cliente_Modificar(cliente* eCliente,int cantidadC);

void abm_imprimirJuegos(juegos* eJuego,int cantidadJ);

void abm_imprimirClientes(cliente* eCliente,int cantidadC);

int juego_buscarPorCodigo(juegos* eJuego,int cantidadJ,int codigo);

int cliente_buscarPorCodigo(cliente* eCliente,int cantidadC,int codigo);

int abm_Juego_Baja(juegos* eJuego,int cantidadJ);

int abm_Cliente_Baja(cliente* eCliente,int cantidadC);

#endif
