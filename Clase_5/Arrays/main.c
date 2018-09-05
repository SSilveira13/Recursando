#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5
int retornoTotal(int listado[],int tamanio);
int retornoPromedio(int listado[],int tamanio);
void cargarListado(int listado[],int tamanio);
void mostrarListado(int listado[],int tamanio);
void mostrarInformacionDelArray(int listado[],int tamanio);
int main()
{
    int listaDeNotas[CANTIDAD];

    cargarListado(listaDeNotas,CANTIDAD);
    mostrarListado(listaDeNotas,CANTIDAD);
    mostrarInformacionDelArray(listaDeNotas,CANTIDAD);

    return 0;
}

int retornoTotal(int listado[],int tamanio)
{
    int total = 0,i;
    for(i=0;i<tamanio;i++)
    {
        total += listado[i];
    }
    return total;
}

int retornoPromedio(int listado[],int tamanio)
{
    int suma;
    int promedio;
    suma = retornoTotal(listado,tamanio);
    promedio = suma / tamanio;
    return promedio;
}

void cargarListado(int listado[],int tamanio)
{
    int i;
    int numeroIngresado;
    for(i=0;i<tamanio;i++)
    {
        printf("\nIngrese nota n %d: ",i+1);
        scanf("%d",&numeroIngresado);
        listado[i]=numeroIngresado;
        system("cls");
    }
}

void mostrarListado(int listado[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("\nLa nota n %d es: %d",i+1,listado[i]);
    }
}

void mostrarInformacionDelArray(int listado[],int tamanio)
{
    int i;
    int mayor;
    int menor;
    int cantidadDePares = 0;
    int total;
    int promedio;
    for(i=0;i<tamanio;i++)
    {
       if(listado[i]>mayor || i==0)
       {
           mayor = listado[i];
       }
    }
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]<menor || i==0)
       {
           menor = listado[i];
       }
    }
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]%2==0)
        {
            cantidadDePares++;
        }
    }
    total = retornoTotal(listado,tamanio);
    promedio = retornoPromedio(listado,tamanio);

    printf("\n\nLa mayor nota es: %d",mayor);
    printf("\n\nLa menor nota es: %d",menor);
    printf("\n\nLa cantidad de pares es: %d",cantidadDePares);
    printf("\n\nLa suma total de las notas es: %d",total);
    printf("\n\nEl promedio de las notas es: %d\n",promedio);
}
