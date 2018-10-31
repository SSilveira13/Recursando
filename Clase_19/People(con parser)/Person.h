#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

typedef struct{
int id;
char nombre[32];
char apellido[32];
int edad;
}Persona;

#endif //PEOPLE_H_INCLUDED

/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Persona* person_new(char* nombre,char* apellidos,int id,int edad);

/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Persona* this, int age) ;

/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona
 *
 */
int person_getAge(Persona* this);

/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Persona* this);

void person_setName(Persona* this,char* nombre);

char* person_getName(Persona* this);

void person_setLastName(Persona* this,char* apellido);

char* person_getLastName(Persona* this);

void person_setID(Persona* this,int id);

int person_getID(Persona* this);

//int person_validToDigit(char* digit);

Persona* person_newArray();

Persona* person_updateArray();
