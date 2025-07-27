#include "utilidades.h"
#include <stdio.h>
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
    while (getchar() != '\n'); // Limpia el buffer hasta que se presione ENTE
}
