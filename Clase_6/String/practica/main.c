#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()//strcpy(destino,origen);
{
    /*char nombre[31],ingresado[31];
    printf("Nombre: ");
    fflush(stdin);//limpia el buffer
    scanf("%[^\n]",ingresado);//tipo de dato que detecta espacios en el string ([^\n])
    strcpy(nombre,ingresado);
    printf("%s",nombre);*/

    char nombre[31];
    char apellido[31];
    char apeNom[62];
    int cantidad;
    printf("Nombre: ");
    fflush(stdin);
    fgets(nombre,sizeof(nombre)-2,stdin);
    cantidad = strlen(nombre);
    nombre[cantidad-1] = '\0';
    printf("Apellido: ");
    fflush(stdin);
    fgets(apellido,sizeof(apellido)-2,stdin);
    cantidad = strlen(apellido);
    apellido[cantidad-1] = '\0';
    //tengo 2 maneras
    //1-
    /*strcpy(apeNom,apellido);
    strcat(apeNom," ");
    strcat(apeNom,nombre);*/
    //2-
    apeNom[0]='\0';
    strcat(apeNom,apellido);
    strcat(apeNom," ");
    strcat(apeNom,nombre);

    printf("%s",apeNom);
    return 0;
}
