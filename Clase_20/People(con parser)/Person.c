#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Person.h"
#include "parser.h"


static void initialize(Persona* this,char* nombre,char* apellido,int id,int edad);

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Persona* person_new(char* nombre,char* apellido,int id,int edad)
{
    Persona* this = malloc(sizeof(Persona));
    if(this != NULL)
    {
        initialize(this,nombre,apellido,id,edad);
    }
    return this;
}

/** \brief  Inicializa a una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Persona* this,char* nombre,char* apellido,int id,int edad)
{
    person_setAge(this,edad);
    person_setName(this,nombre);
    person_setLastName(this,apellido);
    person_setID(this,id);
}

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Persona* this, int age)
{
    if(age > 0)
    {
        this->edad = age;
    }
}

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Persona* this)
{
    return this->edad;
}


/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Persona* this) {
    // Do any other freeing required here.
    free(this);
}

void person_setName(Persona* this,char* nombre)
{
    if(nombre != NULL && this != NULL)
    {
        strcpy(this->nombre,nombre);
    }
}

char* person_getName(Persona* this)
{
    return this->nombre;
}

void person_setLastName(Persona* this,char* apellido)
{
    if(apellido != NULL && this != NULL)
    {
        strcpy(this->apellido,apellido);
    }
}

char* person_getLastName(Persona* this)
{
    return this->nombre;
}

void person_setID(Persona* this,int id)
{
    if(id >= 0)
    {
        this->id = id;
    }
}

int person_getID(Persona* this)
{
    return this->id;
}

/*int person_validToDigit(char* digit)//TERMINAR
{
    int comparacion,iteracion = 0,numeros[20],multiplicador,numFinal=0,aux;
    while(digit[iteracion]!="\0")
    {
        numeros[iteracion] = isdigit(digit[iteracion]);
        iteracion++;
    }
    comparacion = iteracion;
    while(iteracion>0)
    {
        aux = numeros[iteracion];
        iteracion--;
        multiplicador=comparacion-iteracion;
        numFinal = numFinal + aux * multiplicador;
    }
    return numFinal;
}*/

Persona* person_newArray()
{
    Persona *puntero;
    puntero = malloc(sizeof(Persona*)*10);
    return puntero;
}

Persona* person_updateArray()
{

    return NULL;
}
