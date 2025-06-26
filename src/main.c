// Declaración de bibliotecas y constantes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matriculaVehicular.h"
#include "utilidades.h"
#define MAX_USERS 100

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
            printf("\nVehiculo registrado exitosamente.\n");
            break;
		}
		case 2: {
			limpiarPantalla();
			buscarVehiculoPorPlaca(vehiculos, contador);
			break;
		}
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
			generarComprobante();
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
