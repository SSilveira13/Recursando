#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* aux;
    char var1[50],var3[50],var2[50],var4[50];
    if(pFile == NULL)
    {
        retorno = -1;
        //printf("Llega..."); system("pause");
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do
        {
            retorno = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            //printf("%s %s %s %s", var1, var2, var3, var4);
            if(retorno==4)
            {
                aux = employee_new();
                aux = employee_newParametros(aux,var1,var2,var3,var4);
                ll_add(pArrayListEmployee,aux);
                retorno = 0;
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* aux;
	int cant;
	system("cls");
	if (pFile==NULL)
	{
		printf("No se pudo abrir el archivo");
	}
	else
    {
        //fread(&aux,sizeof(aux),1,pFile);
        while(!feof(pFile))
        {
            aux = employee_new();
			cant = fread(aux,sizeof(Employee),1,pFile);
			if(cant!=1)
			{
				if(feof(pFile))
                {
                    break;
                }
				else
				{
					printf("No leyo el ultimo registro");
					break;
				}
			}
			ll_add(pArrayListEmployee,(void*)aux);
        }
        fclose(pFile);
    }
    return 1;
}
