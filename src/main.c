// Declaración de bibliotecas y constantes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matriculaVehicular.h"
#include "utilidades.h"
#include "login.h"
#define MAX_USERS 100

// Menu para login o registro de usuario
int loginMenu(){
	int opcionLogin;
    int accesoPermitido = 0;

    // Menú de autenticación
    do {
        limpiarPantalla();
        printf("\n\t-- SISTEMA DE USUARIOS --\n");
        printf("1. Registrarse\n");
        printf("2. Iniciar sesión\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcionLogin);
        while (getchar() != '\n');

        switch (opcionLogin) {
            case 1:
                limpiarPantalla();
                SignUser();
                break;
            case 2:
		limpiarPantalla();
	 	int intentos=0;
		  while (intentos < 3 && !accesoPermitido) {
	        accesoPermitido = LogUser();
	        if (!accesoPermitido) {
	            intentos++;
	            if (intentos < 3) {
	                printf("Intento %d/3 fallido. Intente nuevamente.\n", intentos);
	            } else {
                printf("Ha superado el número máximo de intentos.\n");
                mensajeSalida();
                return 0;  // Simula que el usuario eligió la opcion 3 "Salir"
            }
        }
    }     
                break;
            case 3:
                printf("Saliendo del sistema de usuarios...\n");
                mensajeSalida();
                return 0;  // Termina completamente el programa
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (!accesoPermitido);

    return 1; // Acceso exitoso
}


// Se muestra al usuario el men
void mostrarMenu() {
	printf("\n\t-- MENU DE MATRICULACION VEHICULAR --\n");
	printf("1. Registrar nuevo vehículo\n");
	printf("2. Buscar vehículo por placa\n");
	printf("3. Listar todos los vehículos\n");
	printf("4. Empezar proceso de matriculación\n");
	printf("5. Listar los vehículos matriculados\n");
	printf("6. Generar comprobante\n");
	printf("7. Salir\n");
	printf("Seleccione una opción: ");
}

//Función principal
int main() {
    int opcion;

    if (!loginMenu()) {
	printf("Finalizando el programa...\n");
    return 0; // Finaliza si el usuario selecciona "Salir" o falla 3 intentos
    }

    do {
        limpiarPantalla();
        mostrarMenu();
        scanf("%d", &opcion);
        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                limpiarPantalla();
                registrarVehiculoArchivo();
                break;
            case 2:
                limpiarPantalla();
                buscarVehiculoPorPlacaArchivo();
                break;
            case 3:
                limpiarPantalla();
                listarVehiculosArchivo();
                break;
            case 4:
                limpiarPantalla();
                procesoMatriculacionArchivo();
                break;
            case 5:
                limpiarPantalla();
                listarVehiculosMatriculadosArchivo();
                break;
            case 6:
                limpiarPantalla();
                generarComprobanteArchivo();
                break;
            case 7:
                printf("Saliendo......... Gracias!\n");
                break;
            default:
                printf("Opción no válida, por favor intente de nuevo.\n");
                mensajeSalida();
        }

    } while (opcion != 7);

    return 0;
}
