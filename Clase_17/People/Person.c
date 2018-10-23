#include <stdlib.h>
#include "Person.h"
#include <string.h>


static void initialize(Person* this, int age);

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Person* person_new (int age)
{
    Person* this = malloc(sizeof(Person));
    if(this != NULL)
        initialize(this,age);

    return this;
}

/** \brief  Inicializa a una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Person* this, int age)
{
    this->age = age;
    strcpy(this->name,"\0");
}

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age)
{
    if(age > 0)
        this->age = age;
}

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Person* this)
{
    return this->age;
}


/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this) {
    // Do any other freeing required here.
    free(this);
}

void person_setName(Person * this,char name[25])
{
    if(strlen(name)>0 && strlen(name)<24 && this != NULL)
    {
        printf("Name: ");
        scanf("%s",name);
        strcpy(this->name,name);
    }
}

void person_getName(Person *this,char *name)
{
    if(this != NULL)
    {
        strcpy(*name,this->name);
    }
}
