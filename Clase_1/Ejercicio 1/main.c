#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numeroUno,numeroDos,numeroTres,numeroMedio;
    printf("\nNumero uno: ");
    scanf("%d",&numeroUno);
    printf("\nNumero dos: ");
    scanf("%d",&numeroDos);
    printf("\nNumero tres: ");
    scanf("%d",&numeroTres);
    /*if(numeroUno < numeroDos)
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
    }*/
    /*if((numeroUno < numeroDos) && (numeroDos< numeroTres) || (numeroTres < numeroDos) && (numeroDos < numeroUno))
    {
        numeroMedio = numeroDos;
    }
    else if((numeroDos < numeroUno) && (numeroUno < numeroTres) || (numeroTres < numeroUno) && (numeroUno < numeroDos))
    {
        numeroMedio = numeroUno;
    }
    else if((numeroUno < numeroTres) && (numeroTres < numeroDos) || (numeroDos < numeroTres) && (numeroTres < numeroUno))
    {
        numeroMedio = numeroTres;
    }*/
    int numeroMinimo = numeroUno,numeroMaximo = numeroUno;
    if(numeroDos < numeroMinimo)
    {
        numeroMinimo = numeroDos;
    }
    if(numeroTres < numeroMinimo)
    {
        numeroMinimo = numeroTres;
    }
    if(numeroDos > numeroMaximo)
    {
        numeroMaximo = numeroDos;
    }
    if(numeroTres > numeroMaximo)
    {
        numeroMaximo = numeroTres;
    }
    if((numeroMinimo < numeroUno) && (numeroUno < numeroMaximo))
    {
        numeroMedio = numeroUno;
    }
    else if((numeroMinimo < numeroDos) && (numeroDos < numeroMaximo))
    {
        numeroMedio = numeroDos;
    }
    else if((numeroMinimo < numeroTres) && (numeroTres < numeroMaximo))
    {
        numeroMedio = numeroTres;
    }
    else
    {
        printf("\nError");
    }
    printf("\nEl numero del medio es: %d",numeroMedio);
    return 0;
}
