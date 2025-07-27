#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "login.h"

#define ARCHIVO_USUARIOS "../data/usuarios.txt"  // Ruta del archivo donde se almacenan los usuarios
#define MAX_LINEA 256

/**
 * @brief Registra un nuevo usuario en el sistema
 * 
 * Esta función solicita al usuario un nombre de usuario y contraseña,
 * y los almacena en el archivo de usuarios.
 * 
 * @return void
 */

// Verifica si un nombre de usuario ya está registrado
int usuarioExiste(const char *usuario) {
    FILE *file = fopen(ARCHIVO_USUARIOS, "r");
    if (file == NULL) {
    return 0; // Archivo no existe, por lo tanto el usuario no existe
    }

    char linea[MAX_LINEA];
    while (fgets(linea, sizeof(linea), file)) {
        char nombreUsuario[MAX_USUARIO];
        sscanf(linea, "%[^|]", nombreUsuario); // Extrae hasta el '|'

        if (strcmp(nombreUsuario, usuario) == 0) {
            fclose(file);
            return 1; // Usuario encontrado
        }
    }

    fclose(file);
    return 0; // Usuario no encontrado
}

void SignUser() {
    char usuario[MAX_USUARIO];
    char contrasenia[MAX_CONTRASENIA];

    printf("---- REGISTRO DE USUARIO ----\n");
    printf("Ingrese un nombre de usuario: ");
    fgets(usuario, MAX_USUARIO, stdin);
    usuario[strcspn(usuario, "\n")] = '\0';  // Elimina el salto de línea

    if (usuarioExiste(usuario)) {
        printf("El nombre de usuario ya está registrado. Intente con otro.\n");
        mensajeSalida();
        return;
    }

    printf("Ingrese una contraseña: ");
    fgets(contrasenia, MAX_CONTRASENIA, stdin);
    contrasenia[strcspn(contrasenia, "\n")] = '\0';

    FILE *file = fopen(ARCHIVO_USUARIOS, "a");
    if (file == NULL) {
        printf("Error al abrir el archivo de usuarios.\n");
        mensajeSalida();
        return;
    }

    fprintf(file, "%s|%s\n", usuario, contrasenia);
    fclose(file);

    printf("Usuario registrado exitosamente.\n");
    mensajeSalida();
}

/**
 * @brief Permite a un usuario iniciar sesión en el sistema
 * 
 * Esta función verifica las credenciales del usuario comparándolas
 * con las almacenadas en el archivo de usuarios.
 * 
 * @return int Retorna 1 si el inicio de sesión es exitoso, 0 en caso contrario
 */
int LogUser() {
    char usuario[MAX_USUARIO];            // Buffer para el nombre de usuario ingresado
    char contrasenia[MAX_CONTRASENIA];    // Buffer para la contraseña ingresada
    char usuario_arch[MAX_USUARIO];       // Buffer para leer usuarios del archivo
    char contrasenia_arch[MAX_CONTRASENIA]; // Buffer para leer contraseñas del archivo
    char linea[100];                      // Nueva línea a leer del archivo
    int encontrado = 0;                   // Bandera para indicar si se encontró el usuario

    // Interfaz para el inicio de sesión
    printf("---- INICIO DE SESIÓN ----\n");
    printf("Ingrese su usuario: ");
    fgets(usuario, MAX_USUARIO, stdin);
    usuario[strcspn(usuario, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    printf("Ingrese su contraseña: ");
    fgets(contrasenia, MAX_CONTRASENIA, stdin);
    contrasenia[strcspn(contrasenia, "\n")] = '\0'; // Eliminar el carácter de nueva línea

    // Abrir el archivo en modo lectura
    FILE *file = fopen(ARCHIVO_USUARIOS, "r");
    if (file == NULL) {
        printf("No hay usuarios registrados.\n");
        return 0;
    }

    // Leer el archivo línea por línea buscando coincidencias
     while (fgets(linea, sizeof(linea), file) != NULL) {
        sscanf(linea, "%[^|]|%s", usuario_arch, contrasenia_arch);
        if (strcmp(usuario, usuario_arch) == 0 && strcmp(contrasenia, contrasenia_arch) == 0) {
            encontrado = 1;  // Usuario y contraseña coinciden
            break;
        }
    }

    fclose(file);

    // Mostrar el resultado del inicio de sesión
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
