#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    this->edad = edad;
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
        this->edad = age;
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

void person_getName(Persona* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
    }
}

void person_setLastName(Persona* this,char* apellido)
{
    if(apellido != NULL && this != NULL)
    {
        strcpy(this->apellido,apellido);
    }
}

void person_getLastName(Persona* this,char* apellido)
{
    if(this != NULL)
    {
        strcpy(apellido,this->apellido);
    }
}
