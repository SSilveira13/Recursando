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
    int retorno,len;
    char var1[50],var3[50],var2[50],var4[50];
    pFile = fopen("datos.csv","r");
    if(pFile == NULL)
    {
        return -1;
    }
    do
    {
        retorno = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(retorno==4)
        {
            pArrayListEmployee = employee_newParametros(pArrayListEmployee,var1,var2,var3,var4));
            *len = *len + 1;
        }
    }while(!feof(pFile));
    fclose(pFile);
    return *len;
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

    return 1;
}
