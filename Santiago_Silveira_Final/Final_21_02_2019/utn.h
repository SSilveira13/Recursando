#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getEntero(int* pEntero,char* msg,char* msgErr,int minimo,int maximo,int reintentos);

int utn_getFlotante(float* pFlotante,char* msg,char* msgErr,float minimo,float maximo,int reintentos);

int utn_getCaracter(char* pCaracter,char* msg,char* msgErr,char minimo,char maximo,int reintentos);

int utn_getCadena(char* pCadena,char* msg,char* msgErr,int reintentos);

#endif
