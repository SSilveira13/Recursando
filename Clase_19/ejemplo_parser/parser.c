#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int parseData(char* fileName,Persona* arrayPersonas, int len)
{
    FILE *pFile;
    int r,i=0;
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
            arrayPersonas[i].id = atoi(var1);
            strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
            strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
            arrayPersonas[i].edad = atoi(var4);
        }
        //printf("%d\n",ftell(pFile));
        i++;
    }while(!feof(pFile) && i<len);
    fclose(pFile);
    return i;
}
