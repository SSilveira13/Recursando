#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()//strcpy(destino,origen);
{
    char nombre[31],ingresado[31];
    printf("Nombre: ");
    fflush(stdin);//limpia el buffer
    scanf("%[^\n]",ingresado);//tipo de dato que detecta espacios en el string ([^\n])
    strcpy(nombre,ingresado);
    printf("%s",nombre);
    return 0;
}
//fgets(cadena,cantidad,stdin);para leer archivos
