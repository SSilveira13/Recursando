#include <stdio.h>
#include <stdlib.h>
#include "Estructura.h"

int main()
{
    struct ePersona Empleado;
    struct ePersona *pEmpleado;
    pEmpleado = &Empleado;
    altaEmpleado(pEmpleado);
    informarEmpleado(pEmpleado);
    return 0;
}
