#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "parser.h"

int parseData(char* fileName, Persona* arrayPersonas[],int *len)
{
    FILE *pFile;
    int r;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen("datos.csv","r");
    if(pFile == NULL)
    {
        return -1;
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            arrayPersonas[*len] = person_new(var2,var3,atoi(var1),atoi(var4));
            *len = *len + 1;
        }
    }while(!feof(pFile));
    fclose(pFile);
    return *len;
}
