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
                accesoPermitido = LogUser();
                break;
            case 3:
                printf("Saliendo del sistema de usuarios...\n");
                mensajeSalida();
                return 0;  // <-- Aquí se termina completamente el programa
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
    Vehiculo vehiculos[MAX_USERS];
    int opcion, contador = 0;

    if (!loginMenu()) {
        return 0; // Finaliza si el usuario selecciona "Salir"
    }

    do {
        limpiarPantalla();
        mostrarMenu();
        scanf("%d", &opcion);
        while (getchar() != '\n');
        switch (opcion) {
            case 1: {
                limpiarPantalla();
                Vehiculo v = registroVehiculo();
                vehiculos[contador++] = v;
                printf("\nVehículo registrado exitosamente.\n");
                mensajeSalida();
                break;
            }
            case 2:
                limpiarPantalla();
                mostrarVehiculoPorPlaca(vehiculos, contador);
                break;
            case 3:
                limpiarPantalla();
                listarVehiculos(vehiculos, contador);
                break;
            case 4:
                limpiarPantalla();
                procesoMatriculacion(vehiculos, contador);
                break;
            case 5:
                limpiarPantalla();
                listarVehiculosMatriculados(vehiculos, contador);
                break;
            case 6:
                limpiarPantalla();
                generarComprobante(vehiculos, contador);
                break;
            case 7:
                printf("Saliendo......... Gracias!\n");
                break;
            default:
                printf("Opción no válida, por favor intente de nuevo.\n");
        }

    } while (opcion != 7);

    return 0;
}