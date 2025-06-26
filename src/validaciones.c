#include "validaciones.h"
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Valida una placa: Formato AAA-1234
int validarPlaca(const char *placa) {
    regex_t regex;
    const char *validacionPlaca = "^[A-Z]{3}-[0-9]{4}$";
    int reti;

    reti = regcomp(&regex, validacionPlaca, REG_EXTENDED);
    if (reti) {
        printf("Error: No se pudo compilar la expresión regular para validar la placa.\n");
        return 0;
    }

    reti = regexec(&regex, placa, 0, NULL, 0);
    regfree(&regex);
    return !reti;
}

// Validar cédula ecuatoriana
int validarCedula(const char *cedula) {
    regex_t regex;
    const char *pattern = "^(0[1-9]|1[0-9]|2[0-4])[0-9]{8}$";
    int reti;

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Error: No se pudo compilar la expresión regular para la cédula.\n");
        return 0;
    }

    reti = regexec(&regex, cedula, 0, NULL, 0);
    regfree(&regex);

    return !reti; // 1 si coincide, 0 si no
}

// Lee una respuesta S/N
int leerRespuestaSN(const char *pregunta) {
    int respuesta;
    int resultado;

    do {
        printf("%s (si, es 1 / no, es 0): ", pregunta);
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