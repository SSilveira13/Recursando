#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>


static int getInt(int* pBuffer);

static int getFloat(float* pBuffer);

static int getChar(char* pBuffer);

static int getString(char* pBuffer[]);

static int getInt(int* pBuffer)
{
    return scanf("%d",pBuffer);
}

static int getFloat(float* pBuffer)
{
    return scanf("%f",pBuffer);
}

static int getChar(char* pBuffer)
{
    return scanf("%c",pBuffer);
}

static int getString(char* pBuffer[])
{
    return scanf("%s",*pBuffer);
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


int utn_getCaracter(char* pCaracter,char* msg,char* msgErr,char min,char max,int reintentos)
{
    int retorno = -1;
    char bufferChar;
    if(pCaracter!=NULL && msg!=NULL && msgErr!=NULL && min<=max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if((getChar(&bufferChar)==1) && bufferChar>=min && bufferChar<=max)
            {
                *pCaracter = bufferChar;
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


int utn_getCadena(char* pCadena,char* msg,char* msgErr,int reintentos)
{
    int retorno = -1;
    char bufferString[201];
    if(pCadena!=NULL && msg!=NULL && msgErr!=NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getString(bufferString)>=1)
            {
                strcpy(pCadena,bufferString);
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
