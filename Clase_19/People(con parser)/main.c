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
        printf("Nombre: %s\tApellido: %s\n",person_getName(personaArray[i]),person_getLastName(personaArray[i]));
        printf("ID: %d\t\tEdad: %d\n",person_getID(personaArray[i]),person_getAge(personaArray[i]));
        printf("-----------------------------------------\n");
    }
    return 0;
}

