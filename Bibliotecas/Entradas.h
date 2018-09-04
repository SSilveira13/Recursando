#ifndef ENTRADAS_H_INCLUDED
#define ENTRADAS_H_INCLUDED

/** \brief  Pide un numero entero y lo valida
 *
 * \param entrada int*  Numero entero a validar
 * \param mensaje[] char    Mensaje mostrado
 * \param mendajeError[] char   Mensaje mostrado en caso de error
 * \param limiteBajo int    Limite inferior a validar
 * \param limiteAlto int    Limete superior a validar
 * \return int  Devuelve [0] en caso de validar y [-1] en caso de error
 *
 */
int obtenerEntero(int* entrada,char mensaje[],char mensajeError[], int limiteBajo, int limiteAlto);

/** \brief  Pide un numero flotante y lo valida
 *
 * \param entrada float*    Numero flotante a validar
 * \param mensaje[] char    Mensaje mostrado
 * \param mendajeError[] char   Mensaje mostrado en caso de error
 * \param limiteBajo float  Limite inferior a validar
 * \param limiteAlto float  Limete superior a validar
 * \return int  Devuelve [0] en caso de validar y [-1] en caso de error
 *
 */
int obtenerFlotante(float* entrada,char mensaje[],char mensajeError[], float limiteBajo, float limiteAlto);

/** \brief  Pide un caracter y lo valida
 *
 * \param entrada char* Caracter a validar
 * \param mensaje[] char    Mensaje mostrado
 * \param mendajeError[] char   Mensaje mostrado en caso de error
 * \param limiteBajo char   Limite inferior a validar
 * \param limiteAlto char   Limete superior a validar
 * \return int  Devuelve [0] en caso de validar y [-1] en caso de error
 *
 */
int obtenerCaracter(char* entrada,char mensaje[],char mensajeError[], char limiteBajo, char limiteAlto);

/** \brief  Pide una cadena de caracteres y lo valida
 *
 * \param entrada char* Cadena de caracteres a validar
 * \param mensaje[] char    Mensaje mostrado
 * \param mendajeError[] char   Mensaje mostrado en caso de error
 * \param limiteBajo int    Limite inferior a validar
 * \param limiteAlto int    Limete superior a validar
 * \return int  Devuelve [0] en caso de validar y [-1] en caso de error
 *
 */
int obtenerCadena(char* entrada,char mensaje[],char mendajeError[], int limiteBajo, int limiteAlto);

#endif
