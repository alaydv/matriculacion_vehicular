
#include "matriculaVehicular.h"
#include <string.h>
#include <stdio.h>

//Función para vehiculos
void listarVehiculos(){
    printf("Prosimamente...\n");
}
void generarComprobante(){
    printf("Proximamente..\n");
}

void buscarVehiculoPorPlaca(const char *placaBuscar){
    printf("Proximamente..\n");
}
/**
 * Función que registra un vehículo solicitando los datos por teclado.
 * Incluye validaciones para cada campo.
 * Retorna una estructura Vehiculo con los datos ingresados.
 */
Vehiculo registroVehiculo() {
    Vehiculo v;

    // Leer placa
    printf("Ingrese la placa del vehículo:\n");
    fgets(v.placa, sizeof(v.placa), stdin);
    v.placa[strcspn(v.placa, "\n")] = '\0';

    // Leer cédula
    printf("Ingrese el número de cédula del propietario:\n");
    fgets(v.cedula, sizeof(v.cedula), stdin);
    v.cedula[strcspn(v.cedula, "\n")] = '\0';

    // Seleccionar tipo de vehículo con validación
    int tipoOpcion = 0;
    do {
        printf("Seleccione el tipo de vehículo:\n");
        printf("1. Liviano\n");
        printf("2. Pesado\n");
        printf("Opción: ");
        if (scanf("%d", &tipoOpcion) != 1) {
            while (getchar() != '\n'); // limpiar buffer
            tipoOpcion = 0; // opción inválida
        }

        switch (tipoOpcion) {
            case 1:
                strcpy(v.tipo, "Liviano");
                break;
            case 2:
                strcpy(v.tipo, "Pesado");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (tipoOpcion != 1 && tipoOpcion != 2);
    getchar(); // Limpiar salto de línea pendiente

    // Leer año del vehículo con validación mínima
    do {
        printf("Ingrese el año del vehículo (mayor a 1900):\n");
        if (scanf("%d", &v.anio) != 1) {
            while (getchar() != '\n');
            v.anio = 0;
        }
    } while (v.anio < 1900);
    getchar();

    // Leer avalúo con validación positiva
    do {
        printf("Ingrese el avalúo del vehículo (positivo):\n");
        if (scanf("%f", &v.avaluo) != 1) {
            while (getchar() != '\n');
            v.avaluo = -1;
        }
    } while (v.avaluo <= 0);
    getchar();

    return v;
}
