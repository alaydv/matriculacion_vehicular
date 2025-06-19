
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

float verificarMultas(){
    int opcion;
    float multa = 0.0;
    int tieneMultas;
    do
    {
        printf("\n¿Tiene multas de tránsito? (1 = Sí, 0 = No): ");
	    scanf("%d", &tieneMultas);
        if (tieneMultas == 0)
        {
            return multa;
        }else
        {
            do {
                printf("\nSeleccione la infracción cometida:\n");
                printf("1. Exceso de velocidad - $120.00\n");
                printf("2. No uso de cinturón - $80.00\n");
                printf("3. Mal parqueo - $60.00\n");
                printf("4. Conducir ebrio - $40.00\n");
                printf("5. Finalizar\n");
                printf("Opción: ");
                scanf("%d", &opcion);
                
                switch (opcion) {
                case 1:
                    multa += 120.00f;
                    break;
                case 2:
                    multa += 80.00f;
                    break;
                case 3:
                    multa += 60.00f;
                    break;
                case 4:
                    multa += 40.00f;
                    break;
                case 5:
                    break;
                default:
                    printf("? Opción no válida.\n");
                }
            } while (opcion != 5);
            return multa;
        }
    } while (tieneMultas != 0 || tieneMultas !=1);
    
}

void generarComprobante(){
    printf("Proximamente..\n");
}

void buscarVehiculoPorPlaca(const char *placaBuscar){
    printf("Proximamente..\n");
}

// Función auxiliar para validar respuestas tipo 's' o 'n'
int leerRespuestaSN(const char *pregunta) {
    char respuesta[10];
    while (1) {
        printf("%s (s/n): ", pregunta);
        fgets(respuesta, sizeof(respuesta), stdin);
        respuesta[strcspn(respuesta, "\n")] = '\0';

        if (strcmp(respuesta, "s") == 0 || strcmp(respuesta, "S") == 0) {
            return 1; // Aprobado
        } else if (strcmp(respuesta, "n") == 0 || strcmp(respuesta, "N") == 0) {
            return 0; // No aprobado
        } else {
            printf("Entrada inválida. Por favor, ingrese solo 's' o 'n'.\n");
        }
    }
}

int revision() {
    printf("\n\t-- REVISIÓN TÉCNICA DEL VEHÍCULO --\n");

    int frenos = leerRespuestaSN("¿Los frenos están operables?");
    int luces  = leerRespuestaSN("¿Las luces funcionan correctamente?");
    int gases  = leerRespuestaSN("¿Los gases están dentro de los límites permitidos?");
    int llantas = leerRespuestaSN("¿Las llantas están en buen estado?");

    if (frenos && luces && gases && llantas) {
        printf("✔ Revisión técnica aprobada.\n");
        return 1;
    } else {
        printf("✘ Revisión técnica fallida.\n");
        return 0;
    }
}

void procesoMatriculacion(Vehiculo vehiculos[], int totalVehiculos){

    float multa;
    int aprovacionRevision;
    for (int i = 0; i < totalVehiculos; i++)
    {
    multa = verificarMultas();

    if (multa != 0.0)
    {
        vehiculos[i].multas = multa;
        printf("No puedes proceder con la revisión tienes una multa de: %.2f\n", multa);
        printf("Presiona enter para continuar....\n");
        getchar();
    }else{
        vehiculos[i].multas = multa;
        aprovacionRevision = revision();
        if (aprovacionRevision == 1){
            vehiculos[i].estaMatriculado = aprovacionRevision;
            printf("Operación concluida, su vehículo ha sido matriculado\n");
            getchar();
            printf("presione enter para continuar...\n");
        }else{
            vehiculos[i].estaMatriculado = aprovacionRevision;
            printf("Operación concluida, su vehículo no ha sido matriculado\n");
            getchar();
            printf("presione enter para continuar...\n");
        }
        
    }
    }
}

void listarVehiculosMatriculados(){
    printf("Prosimamente ...");
}

Vehiculo registroVehiculo() {
    /**
 * Función que registra un vehículo solicitando los datos por teclado.
 * Incluye validaciones para cada campo.
 * Retorna una estructura Vehiculo con los datos ingresados.
 */
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
