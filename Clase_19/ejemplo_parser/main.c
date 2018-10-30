#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main(void)
{
    Persona personas[8];
    int r,i;
    r = parseData("data.csv",personas,8);
    for(i=0; i<r; i++)
    printf("id:%d nombre:%s apellido:%s edad:%d\n",personas[i].id,personas[i].nombre,personas[i].apellido,personas[i].edad);
    exit(EXIT_SUCCESS);
}

