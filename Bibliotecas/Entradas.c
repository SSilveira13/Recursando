#include <stdio.h>
#include "Entradas.h"

int obtenerEntero(int* entrada,char mensaje[],char mensajeError[], int limiteBajo, int limiteAlto)
{
    int retorno;
    printf("%s",mensaje);
    retorno = scanf("%d",entrada);
    if(retorno == 0 || (*entrada >= limiteBajo && *entrada <= limiteAlto))
    {
        printf("%s",mensajeError);
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int obtenerFlotante(float* entrada,char mensaje[],char mensajeError[], float limiteBajo, float limiteAlto)
{
    int retorno;
    printf("%s",mensaje);
    retorno = scanf("%f",entrada);
    if(retorno == 0 || (*entrada >= limiteBajo && *entrada <= limiteAlto))
    {
        printf("%s",mensajeError);
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int obtenerCaracter(char* entrada,char mensaje[],char mensajeError[], char limiteBajo, char limiteAlto)
{
    int retorno;
    printf("%s",mensaje);
    retorno = scanf("%c",entrada);
    if(retorno == 0 || (*entrada >= limiteBajo && *entrada <= limiteAlto))
    {
        printf("%s",mensajeError);
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

int obtenerCadena(char* entrada,char mensaje[],char mensajeError[], int limiteBajo, int limiteAlto)
{
    int retorno;
    printf("%s",mensaje);
    retorno = scanf("%s",entrada);
    if(retorno == 0 || (*entrada >= limiteBajo && *entrada <= limiteAlto))
    {
        printf("%s",mensajeError);
        retorno = -1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}
