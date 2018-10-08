#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief  Obtiene un entero y lo valida
 *
 * \param pEntero int*  Puntero al entero
 * \param msg char* Mensaje al pedir el entero
 * \param msgErr char*  Mensaje al ocurrir un error
 * \param minimo int    Entero minimo
 * \param maximo int    Entero negro
 * \param reintentos int    Cantidad de reintentos
 * \return int  Devuelve -1 en caso de error y 0 en ingreso exitoso
 *
 */
int utn_getEntero(int* pEntero,char* msg,char* msgErr,int minimo,int maximo,int reintentos);

/** \brief  Obtiene un flotante y lo valida
 *
 * \param pFlotante float*  Puntero a flotante
 * \param msg char* Mensaje al pedir el flotante
 * \param msgErr char*  Mensaje al ocurrir un error
 * \param minimo float  Flotante minimo
 * \param maximo float  Flotante maximo
 * \param reintentos int    Cantidad de reintentos
 * \return int  Devuelve -1 en caso de error y 0 en ingreso exitoso
 *
 */
int utn_getFlotante(float* pFlotante,char* msg,char* msgErr,float minimo,float maximo,int reintentos);

/** \brief  Obtiene un caracter y lo valida
 *
 * \param pCaracter char*   Puntero al caracter
 * \param msg char* Mensaje al pedir el caracter
 * \param msgErr char*  Mensaje al ocurrir un error
 * \param minimo char   Caracter maximo
 * \param maximo char   Caracter minimo
 * \param reintentos int    Cantidad de reintentos
 * \return int  Devuelve -1 en caso de error y 0 en ingreso exitoso
 *
 */
int utn_getCaracter(char* pCaracter,char* msg,char* msgErr,char minimo,char maximo,int reintentos);

/** \brief  Obtiene una cadena y la valida
 *
 * \param pCadena char* Puntero a la cadena
 * \param msg char* Mensaje al pedir la cadena
 * \param msgErr char*  Mensaje al ocurrir un error
 * \param reintentos int    Cantidad de reintentos
 * \return int  Devuelve -1 en caso de error y 0 en ingreso exitoso
 *
 */
int utn_getCadena(char* pCadena,char* msg,char* msgErr,int reintentos);

#endif
