#include "validaciones.h"
#include <stdio.h>
#include <regex.h>

regex_t regex;
char validacionPlaca[20] = "^[A-Z]{3}-[0-9]{4}$";
char validacionCedula[20] = "^[01-24]{2}[0-9]{8}$";

int leerRespuestaSN(const char *pregunta){
    return 0;
}