#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

static int getInt(int* pBuffer)
{
    return scanf("%d",pBuffer);
}

int utn_getEntero(  int* pEntero, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) &&
                (bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                __fpurge(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}


static float getfloat(float* pBuffer)
{
    return scanf("%f",pBuffer);
}

float utn_getFlotante(  float* pEntero, char* msg,
                    char msgErr[],float min, float max,
                    float reintentos)

{
    int retorno=-1;
    float bufferFloat;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferFloat) == 1) &&
                (bufferFloat >= min && bufferFloat <= max))
            {
                *pEntero = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                __fpurge(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}
















