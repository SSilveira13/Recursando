#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"


static int getInt(int* pBuffer);

static int getFloat(float* pBuffer);

static int getChar(char* pBuffer);

static int getString(char pBuffer[]);

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

static int getString(char pBuffer[])
{
    return scanf("%s",pBuffer);
}

int utn_getEntero(int* pEntero,char* msg,char* msgErr,int minimo,int maximo,int reintentos)
{
    int retorno = -1;
    int bufferInt;
    if(pEntero!=NULL && msg!=NULL && msgErr!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&bufferInt) == 1 && (bufferInt<=maximo && bufferInt>=minimo))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }

        }while(reintentos>0);
    }
    return retorno;
}

int utn_getFlotante(float* pFlotante,char* msg,char* msgErr,float minimo,float maximo,int reintentos)
{
    int retorno = -1;
    float bufferFloat;
    if(pFlotante!=NULL && msg!=NULL && msgErr!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if((getFloat(&bufferFloat)==1) && bufferFloat>=minimo && bufferFloat<=maximo)
            {
                *pFlotante = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }

        }while(reintentos>=0);
    }
    return retorno;
}


int utn_getCaracter(char* pCaracter,char* msg,char* msgErr,char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char bufferChar;
    if(pCaracter!=NULL && msg!=NULL && msgErr!=NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if((getChar(&bufferChar)==1) && bufferChar>=minimo && bufferChar<=maximo)
            {
                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
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
                fflush(stdin);
                printf("%s",msgErr);
            }

        }while(reintentos>=0);
    }
    return retorno;
}
