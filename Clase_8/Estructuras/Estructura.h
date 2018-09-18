#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

struct ePersona{
int legajo;
int isEmpty;
float salario;
char nombre[31];
};

void altaEmpleado(struct ePersona*);

void informarEmpleado(struct ePersona*);


#endif
