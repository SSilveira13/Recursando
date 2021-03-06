#include <stdio.h>
#include <stdlib.h>
#define MIN 1
#define MAX 100

int pedirEdad();

int validarEdad(int* edad,int edadMax,int edadMin);

int main()//el asterisco(*) se llama operador de indireccion
{
    int edadValida = 0;
    int edad = 0;
    char repetir = 's';
    do
    {
        system("cls");
        edadValida = validarEdad(&edad, MAX, MIN);
        if(edadValida)
        {
            printf("La edad del usuario es %d\n",edad);
        }
        else
        {
            printf("Error: la edad del usuario no es valida\n");
        }
        printf("Desea reingresar la edad del usuario? <s/n>\n");
        fflush(stdin);
        scanf("%c",&repetir);
    }while(repetir == 's');
    return 0;
}

int pedirEdad()
{
    int edad;
    printf("Ingrese la edad del usuario: ");
    scanf("%d",&edad);
    return edad;
}

int validarEdad(int* edad,int edadMax,int edadMin)
{
    int respuesta = 0, iteracion;
    int* pEdad = edad;
    for(iteracion = 0;iteracion < 3;iteracion++)
    {
        *pEdad = pedirEdad();
        if(*pEdad >= edadMin && *pEdad <= edadMax)
        {
            respuesta = 1;
            break;
        }
    }
    return respuesta;
}
