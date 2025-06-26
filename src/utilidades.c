#include "utilidades.h"
#include <stdio.h>
#include <string.h>
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

// Función para quitar el salto de línea final de fgets
void limpiarSaltoLinea(char *cadena) {
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}