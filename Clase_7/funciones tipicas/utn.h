#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getEntero(int* pEntero,char* msg,char* msgErr,int min,int max,int reintentos);

int utn_getFlotante(float* pFlotante,char* msg,char* msgErr,float min,float max,int reintentos);

int utn_getCaracter(char* pCaracter,char* msg,char* msgErr,char min,char max,int reintentos);

int utn_getCadena(char* pCadena,char* msg,char* msgErr,int reintentos);

#endif
