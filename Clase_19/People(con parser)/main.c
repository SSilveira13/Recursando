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
        printf("ID: %d\tNombre: %s\tApellido: %s\t\tEdad: %d\n",personaArray[i]->id,personaArray[i]->nombre,personaArray[i]->apellido,personaArray[i]->edad);
    }
    return 0;
}

