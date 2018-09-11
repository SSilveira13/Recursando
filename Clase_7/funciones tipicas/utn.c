#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int* pBuffer)
{
    return scanf("%d",pBuffer);
}

static int getFloat(float* pBuffer)
{
    return scanf("%f",pBuffer);
}

int utn_getEntero(int* pEntero,char* msg,char* msgErr,int min,int max,int reintentos)
{
    int retorno = -1;
    int bufferInt;
    if(pEntero!=NULL && msg!=NULL && msgErr!=NULL && min<=max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&bufferInt) == 1 && (bufferInt<=max && bufferInt>=min))
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

        }while(reintentos>0);
    }
    return retorno;
}

int utn_getFlotante(float* pFlotante,char* msg,char* msgErr,float min,float max,int reintentos)
{
    int retorno = -1;
    float bufferFloat;
    if(pFlotante!=NULL && msg!=NULL && msgErr!=NULL && min<=max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if((getFloat(&bufferFloat)==1) && bufferFloat>=min && bufferFloat<=max)
            {
                *pFlotante = bufferFloat;
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

