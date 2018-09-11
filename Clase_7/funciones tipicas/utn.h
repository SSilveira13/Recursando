#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

static int getInt(int* pBuffer);

static int getFloat(float* pBuffer);

int utn_getEntero(int* pEntero,char* msg,char* msgErr,int min,int max,int reintentos);

int utn_getFlotante(float* pFlotante,char* msg,char* msgErr,float min,float max,int reintentos);

#endif
