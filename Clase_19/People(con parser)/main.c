#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "parser.h"


int main()
{
    Persona* personaArray[50];
    int arrayOcupadas=0,i;
    parseData("datos.csv",personaArray,&arrayOcupadas);
    for(i=0;i<arrayOcupadas;i++)
    {
        printf("Nombre: %s\n",personaArray[i]->nombre);
    }
    return 0;
}

