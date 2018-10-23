#include <stdio.h>
#include <stdlib.h>
#include "Person.h"


int main()
{
    Person* personArray[3];
    int i;
    char name;
    for(i = 0; i < 10; i++)
    {
        personArray[i] = person_new(i);
    }
    for(i = 0; i < 10; i++)
    {
        person_setAge(personArray[i],i-4);
    }
    for(i = 0; i < 10; i++)
    {
        printf("\nAge: %2d",person_getAge(personArray[i]));
        person_getName(personArray[i],name);
        printf("\nName: %s",name);
    }
    scanf(" ");
    return 0;
}

