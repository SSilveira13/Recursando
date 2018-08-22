#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numeroUno,numeroDos,numeroTres,numeroMedio = 0;
    printf("Ingrese 3 numeros:");
    printf("\n\nNumero uno: ");
    scanf("%d",&numeroUno);
    printf("\nNumero dos: ");
    scanf("%d",&numeroDos);
    printf("\nNumero tres: ");
    scanf("%d",&numeroTres);
    if(numeroUno < numeroDos)
    {
        if(numeroDos < numeroTres)
        {
            numeroMedio = numeroDos;
        }
        else
        {
            numeroMedio = numeroTres;
        }
    }
    else if(numeroDos < numeroUno)
    {
        if(numeroUno < numeroTres)
        {
            numeroMedio = numeroUno;
        }
        else
        {
            numeroMedio = numeroTres;
        }
    }
    if(numeroMedio != 0)
    {
        printf("\nEl numero del medio es: %d",numeroMedio);
    }
    else
    {
        printf("\nError");
    }
    return 0;
}
