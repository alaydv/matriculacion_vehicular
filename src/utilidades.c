#include "utilidades.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void limpiarPantalla(){
    #ifdef _WIN32
    system("cls");  // Windows
    #else
    system("clear");  // Linux / macOS
    #endif
}
void mensajeSalida(){
    printf("Presiona enter para continuar ...\n");
    getchar();
}
