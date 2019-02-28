#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Socios.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_SociosFromText(FILE* pFile , LinkedList* this)
{
    int retorno = -1;
    Socios *aux;
    char var1[50],var3[50],var2[50],var4[50],var5[50];
    if(pFile == NULL)
    {
        retorno = -1;
        //printf("Llega..."); system("pause");
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do
        {
            retorno = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
            //printf("%s %s %s %s", var1, var2, var3, var4);
            if(retorno==5)
            {
                aux = socio_nuevo();
                if(socio_parametros(aux,var1,var2,var3,var4,var5)==0)
                {
                    ll_add(this,aux);
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    return retorno;
}


int parser_FichajesFromText(FILE* pFile , LinkedList* this)
{
    int retorno = -1;
    Fichajes* aux;
    char var1[50],var3[50],var2[50],var4[50],var5[50],var6[50],var7[50],var8[50];
    if(pFile == NULL)
    {
        retorno = -1;
        //printf("Llega..."); system("pause");
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
        do
        {
            retorno = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
            //printf("%s %s %s %s", var1, var2, var3, var4);
            if(retorno==8)
            {
                aux = fichaje_nuevo();
                if(fichaje_parametros(aux,var1,var2,var3,var4,var5,var6,var7,var8)==0)
                {
                    ll_add(this,aux);
                    retorno = 0;
                }
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    return retorno;
}
