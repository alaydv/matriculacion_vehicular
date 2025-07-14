#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "login.h"

#define ARCHIVO_USUARIOS "../data/usuarios.txt"

void SignUser() {
    char usuario[MAX_USUARIO];
    char contrasenia[MAX_CONTRASENIA];

    printf("---- REGISTRO DE USUARIO ----\n");
    printf("Ingrese un nombre de usuario: ");
    fgets(usuario, MAX_USUARIO, stdin);
    usuario[strcspn(usuario, "\n")] = '\0'; // Eliminar '\n'

    printf("Ingrese una contraseña: ");
    fgets(contrasenia, MAX_CONTRASENIA, stdin);
    contrasenia[strcspn(contrasenia, "\n")] = '\0'; // Eliminar '\n'

    FILE *file = fopen(ARCHIVO_USUARIOS, "a");
    if (file == NULL) {
        printf("Error al abrir el archivo de usuarios\n");
        mensajeSalida();
        return ;
    }

    fprintf(file, "%s %s\n", usuario, contrasenia);
    fclose(file);

    printf("Usuario registrado exitosamente.\n");
    mensajeSalida();
}

int LogUser() {
    char usuario[MAX_USUARIO];
    char contrasenia[MAX_CONTRASENIA];
    char usuario_arch[MAX_USUARIO];
    char contrasenia_arch[MAX_CONTRASENIA];
    int encontrado = 0;

    printf("---- INICIO DE SESIÓN ----\n");
    printf("Ingrese su usuario: ");
    fgets(usuario, MAX_USUARIO, stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    printf("Ingrese su contraseña: ");
    fgets(contrasenia, MAX_CONTRASENIA, stdin);
    contrasenia[strcspn(contrasenia, "\n")] = '\0';

    FILE *file = fopen(ARCHIVO_USUARIOS, "r");
    if (file == NULL) {
        printf("No hay usuarios registrados.\n");
        return 0;
    }

    while (fscanf(file, "%s %s", usuario_arch, contrasenia_arch) != EOF) {
        if (strcmp(usuario, usuario_arch) == 0 && strcmp(contrasenia, contrasenia_arch) == 0) {
            encontrado = 1;
            break;
        }
    }

    fclose(file);

    if (encontrado) {
        printf("Inicio de sesión exitoso. Bienvenido, %s.\n", usuario);
        mensajeSalida();
        return 1;
    } else {
        printf("Usuario o contraseña incorrectos.\n");
        mensajeSalida();
        return 0;
    }
}
