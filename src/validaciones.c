#include "validaciones.h"
#include "matriculaVehicular.h" 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ARCHIVO_COMPROBANTES "../data/comprobantes.txt"

// Valida una placa: Formato AAA-1234
int validarPlaca(const char *placa) {
    
    int len = strlen(placa);

    // Rechazar longitudes inválidas
    if (len != 8) {
        return 0;
    }

    // Verificar que el cuarto carácter sea un guion
    if (placa[3] != '-') {
        return 0;
    }

    // Verificar que los primeros 3 caracteres sean letras mayúsculas
    for (int i = 0; i < 3; i++) {
        if (!isalpha(placa[i]) || !isupper(placa[i])) {
            return 0;
        }
    }

    // Verificar que los últimos 4 caracteres sean números
    for (int i = 4; i < 8; i++) {
        if (!isdigit(placa[i])) {
            return 0;
        }
    }

    return 1;
}

// Validar cédula ecuatoriana
int validarCedula(const char *cedula) {
    int len = strlen(cedula);

    // Verifica longitud exacta de 10 caracteres
    if (len != 10) {
        return 0;
    }

    // Verifica que todos los caracteres sean dígitos
    for (int i = 0; i < 10; i++) {
        if (!isdigit(cedula[i])) {
            return 0;
        }
    }

    // Verifica que el código de provincia esté entre 01 y 24
    int provincia = (cedula[0] - '0') * 10 + (cedula[1] - '0');
    if (provincia < 1 || provincia > 24) {
        return 0;
    }

    return 1;
}

// Lee una respuesta S/N
int leerRespuestaSN(const char *pregunta) {
    int respuesta;
    int resultado;

    do {
        printf("%s (1 = sí / 0 = no): ", pregunta);
        resultado = scanf("%d", &respuesta);

        // Limpiar el buffer de entrada en caso de error o caracteres adicionales
        while (getchar() != '\n');

        if (resultado == 1 && (respuesta == 0 || respuesta == 1)) {
            return respuesta;
        } else {
            printf("Error: Ingrese 1 para sí o 0 para no.\n");
        }

    } while (1);
}

//Funciones para evitar registrar vehículos con la misma placa
int placaExisteArchivo(const char *placaBuscar) {
    FILE *file = fopen("../data/vehiculos.txt", "rb");
    if (!file) return 0;  // Si no existe el archivo, no hay duplicados

    Vehiculo v;
    while (fread(&v, sizeof(Vehiculo), 1, file)) {
        if (strcmp(v.placa, placaBuscar) == 0) {
            fclose(file);
            return 1;  // Placa encontrada
        }
    }
    fclose(file);
    return 0;  // Placa no encontrada
}

int comprobanteExisteVehiculo(const char *placa, Vehiculo *resultado) {
    FILE *file = fopen("../data/comprobantes.txt", "r");
    if (!file) return 0;

    char linea[256];
    while (fgets(linea, sizeof(linea), file)) {
        // Busca si la línea contiene la placa
        if (strstr(linea, placa)) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}