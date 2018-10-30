#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

typedef struct{
int id;
char nombre[32];
char apellido[32];
int edad;
}Persona;

int parseData(char* fileName,Persona* arrayPersonas, int len);

#endif


