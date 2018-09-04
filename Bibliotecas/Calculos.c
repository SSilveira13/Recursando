#include <stdio.h>
#include "Calculos.h"

int sumar(int numero_1, int numero_2)
{
    int resultado = numero_1 + numero_2;
    return resultado;
}

int restar(int numero_1, int numero_2)
{
    int resultado = numero_1 - numero_2;
    return resultado;
}

float dividir(int numero_1, int numero_2)
{
    float resultado = 0;
    if(numero_2 > 0)
    {
        resultado = numero_1 / numero_2;
    }
    return resultado;
}

int multiplicar(int numero_1, int numero_2)
{
    int resultado = numero_1 * numero_2;
    return resultado;
}

int factorial(int numero_1)
{
    int resultado=1, iteracion;
    for(iteracion=numero_1;iteracion>0;iteracion--)
    {
        resultado=resultado*iteracion;
    }
    return resultado;
}
