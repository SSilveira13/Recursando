#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5
int retornoTotal(int listado[],int tamanio);
int retornoPromedio(int listado[],int tamanio);
void cargarListado(int listado[],int tamanio);
int main()
{
    int listaDeNotas[CANTIDAD];
    int i;
    int mayor,menor;
    int total = 0;
    int promedio;
    /*printf("Tamaño: %d\n",sizeof(numeroIngresado));
    printf("Tamaño: %d\n",sizeof(listaDeNotas));
    printf("Direccion: %d\n",&numeroIngresado);
    printf("Direccion: %d\n",listaDeNotas);*/
    cargarListado(listaDeNotas,CANTIDAD);
    for(i=0;i<CANTIDAD;i++)
    {
        printf("\nLa nota es: %d",listaDeNotas[i]);
    }
    for(i=0;i<CANTIDAD;i++)
    {
        if(listaDeNotas[i]>mayor || i==0)
        {
            mayor=listaDeNotas[i];
        }
    }
    for(i=0;i<CANTIDAD;i++)
    {
        if(listaDeNotas[i]<menor || i==0)
        {
            menor=listaDeNotas[i];
        }
    }
    total = retornoTotal(listaDeNotas,CANTIDAD);
    promedio = retornoPromedio(listaDeNotas,CANTIDAD);
    printf("\nPromedio: %d",promedio);
    printf("\nEl total es: %d",total);
    printf("\nEl mayor es: %d",mayor);
    printf("\nEl menor es: %d",menor);
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
    }
}
