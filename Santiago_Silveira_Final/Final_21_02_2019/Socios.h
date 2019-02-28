#ifndef __SOCIOS
#define __SOCIOS

struct Socios{
int id;
char nombre[51];
char apellido[51];
int dni;
char clave[21];
}typedef Socios;

typedef struct{
int id_fichaje;
int id_empleado;
int horas;
int minutos;
int dia;
int mes;
int anio;
char ingreso_egreso[5];
}Fichajes;

void main_menu();

Socios* socio_nuevo();
Fichajes* fichaje_nuevo();

int socio_parametros(Socios *aux,char *var1,char *var2,char *var3,char *var4,char *var5);
int fichaje_parametros(Fichajes *aux,char *var1,char *var2,char *var3,char *var4,char *var5,char *var6,char *var7,char *var8);

int socio_setId(Socios* this,int id);
int socio_getId(Socios* this,int* id);
int socio_setNombre(Socios* this,char* nombre);
int socio_getNombre(Socios* this,char* nombre);
int socio_setApellido(Socios* this,char* apellido);
int socio_getApellido(Socios* this,char* apellido);
int socio_setDni(Socios* this,int dni);
int socio_getDni(Socios* this,int* dni);
int socio_setClave(Socios* this,char* clave);
int socio_getClave(Socios* this,char* clave);

int fichaje_setIdFichaje(Fichajes* this,int idFichaje);
int fichaje_getIdFichaje(Fichajes* this,int* idFichaje);
int fichaje_setIdEmpleado(Fichajes* this,int idEmpleado);
int fichaje_getIdEmpleado(Fichajes* this,int* idEmpleado);
int fichaje_setHoras(Fichajes* this,int horas);
int fichaje_getHoras(Fichajes* this,int* horas);
int fichaje_setMinutos(Fichajes* this,int minutos);
int fichaje_getMinutos(Fichajes* this,int* minutos);
int fichaje_setDia(Fichajes* this,int dia);
int fichaje_getDia(Fichajes* this,int* dia);
int fichaje_setMes(Fichajes* this,int mes);
int fichaje_getMes(Fichajes* this,int* mes);
int fichaje_setAnio(Fichajes* this,int anio);
int fichaje_getAnio(Fichajes* this,int* anio);
int fichaje_setInOut(Fichajes* this,char* inOut);
int socio_getInOut(Fichajes* this,char* inOut);

int socio_alta(LinkedList* this);

void socio_mod(LinkedList* this);

void socio_baja(LinkedList* this);

void socio_listar(LinkedList* this);

#endif
