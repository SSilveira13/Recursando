#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char buffer[64];
    int cantidad;

    fgets(buffer,sizeof(buffer)-2,stdin);

    cantidad = strlen(buffer);

    buffer[cantidad-1] = '\0';

    printf("%s", buffer);

    return 0;
}
//fgets(cadena,cantidad,stdin); para leer archivos
