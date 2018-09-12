#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main()
{
    char cadena[21];
    int r;
    r=utn_getCadena(cadena,"\nNombre: ","\nCasena invalida",2);
    printf("%d",r);
    return 0;
}
