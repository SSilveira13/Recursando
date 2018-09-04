#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

/** \brief  Pide dos numeros al usuario y los suma
 *
 * \param numero_1 int  El primer numero de la suma
 * \param numero_2 int  El segundo numero de la suma
 * \return int  Devuelve la suma de los numeros
 *
 */
int sumar(int numero_1, int numero_2);

/** \brief  Pide dos numeros al usuario y los resta
 *
 * \param numero_1 int  El minuendo
 * \param numero_2 int  El sustraendo
 * \return int  Devuelve la diferencia entre los numeros
 *
 */
int restar(int numero_1, int numero_2);

/** \brief  Pide dos numeros y divide el primer numero por el segundo
 *
 * \param numero_1 int  El dividendo
 * \param numero_2 int  El divisor
 * \return int  Devuelve el cociente
 *
 */
float dividir(int numero_1, int numero_2);

/** \brief  Pide dos numeros y los multiplica
 *
 * \param numero_1 int  El multiplicando
 * \param numero_2 int  El multiplicador
 * \return int  Devuelve el producto
 *
 */
int multiplicar(int numero_1, int numero_2);

/** \brief  Pide un numeros y realiza el producto de todos los numeros enteros positivos hasta el numero ingresado
 *
 * \param numero_1 int  El numero factorial
 * \return int  Devuelve el factorial del numero
 *
 */
int factorial(int numero_1);

#endif
