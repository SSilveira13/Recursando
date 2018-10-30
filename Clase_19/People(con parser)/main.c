#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "parser.h"


int main()
{
    Persona* personaArray[50];
    char nombre[50],apellido[50];
    int arrayOcupadas=0,i;
    parseData("datos.csv",personaArray,&arrayOcupadas);
    for(i=0;i<arrayOcupadas;i++)
    {
        person_getName(personaArray[i],nombre);
        person_getLastName(personaArray[i],apellido);
        printf("Nombre: %s\tApellido: %s\n",nombre,apellido);
        printf("ID: %d\t\tEdad: %d\n",person_getID(personaArray[i]),person_getAge(personaArray[i]));
        printf("-----------------------------------------\n");
    }
    return 0;
}

