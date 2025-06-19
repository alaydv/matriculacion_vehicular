
#include "matriculaVehicular.h"
#include <string.h>
#include <stdio.h>

//Función para vehiculos
void listarVehiculos(Vehiculo vehiculos[], int totalVehiculos){

    printf("\n\t-- Lista de todos los vehículos --\n");
    if (totalVehiculos == 0)
    {
        printf("Actualmente no hay ningún vehículo registrado \n");
    } else {
        for (int i = 0; i < totalVehiculos; i++)
        {
            printf("\nVehículo número %d \n", i + 1);
	        printf("Placa del vehículo: %s", vehiculos[i].placa);
	        printf("Cédula del propietario: %s", vehiculos[i].cedula);
	        printf("Tipo del vehículo: %s \n", vehiculos[i].tipo);
        	printf("Año del vehículo: %d \n", vehiculos[i].anio);
	        printf("Avaluo del vehículo: %.2f \n", vehiculos[i].avaluo);
    	    printf("*******************************************\n");
        }
    }
    printf("Presiona enter para continuar ...\n");
    getchar();

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
    do
    {
        printf("Ingrese la placa del vehículo:\n");
        fgets(v.placa, sizeof(v.placa), stdin);
    } while (strlen(v.placa) <= 7);
    // Leer cédula
    do
    {
        printf("Ingrese el número de cédula del propietario:\n");
        fgets(v.cedula, sizeof(v.cedula), stdin);
    } while (strlen(v.cedula) != 10);

    // Seleccionar tipo de vehículo con validación
    int opt;
    int resultado;
    do {
        opt = 0;
        printf("Seleccione el tipo de vehículo:\n");
        printf("1. Liviano\n");
        printf("2. Pesado\n");
        printf("Opción: ");
        resultado = scanf("%d", &opt);
        if (resultado != 1) {
            printf("Entrada inválida. Intente de nuevo.\n");
            // Limpiar el búfer hasta que se encuentre un salto de línea
            while (getchar() != '\n');// para forzar que el bucle se repita
            continue;
        }

        switch (opt) {
            case 1:
                strcpy(v.tipo, "Liviano");
                break;
            case 2:
                strcpy(v.tipo, "Pesado");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }

    } while (opt < 1 || opt > 2);
    //getchar(); // Limpiar salto de línea pendiente

    // Leer año del vehículo con validación mínima
    do {
        printf("Ingrese el año del vehículo:\n");
        if (scanf("%d", &v.anio) != 1 || v.anio <= 1950) {
            while (getchar() != '\n');
            v.anio = 0;
            printf("Error:Ingrese un valor correcto.\n");
        }
    } while (v.anio < 1950);
    getchar();

    // Leer avalúo con validación positiva
    do {
        printf("Ingrese el avalúo del vehículo (positivo):\n");
        if (scanf("%f", &v.avaluo) != 1) {
            while (getchar() != '\n');
            printf("Error:Ingrese un valor correcto.");
        }
    } while (v.avaluo <= 0);
    getchar();

    return v;
}
