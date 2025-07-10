
#include "matriculaVehicular.h"
#include "validaciones.h"
#include "utilidades.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#define MAX_REVISIONES_ANUALES 3

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
	        printf("Placa del vehículo: %s\n", vehiculos[i].placa);
	        printf("Cédula del propietario: %s\n", vehiculos[i].cedula);
	        printf("Tipo del vehículo: %s \n", vehiculos[i].tipo);
        	printf("Año del vehículo: %d \n", vehiculos[i].anio);
	        printf("Avaluo del vehículo: %.2f \n", vehiculos[i].avaluo);
    	    printf("*******************************************\n");
        }
    }
    mensajeSalida();
}

float verificarMultas(){
    int opcion, validacion;
    float multa = 0.0;
    int tieneMultas;
    do
    {
        printf("\n¿Tiene multas de tránsito? (1 = Sí, 0 = No): ");
        validacion = scanf(" %d", &tieneMultas);
        while(getchar() != '\n');
        if (tieneMultas == 0)
        {
            return multa;
        }
        if (tieneMultas == 1) 
        {
            do {
                limpiarPantalla();
                printf("\nSeleccione la infracción cometida:\n");
                printf("1. Exceso de velocidad - $120.00\n");
                printf("2. No uso de cinturón - $80.00\n");
                printf("3. Mal parqueo - $60.00\n");
                printf("4. Conducir ebrio - $40.00\n");
                printf("5. Finalizar\n");
                printf("Opción: ");
                scanf("%d", &opcion);
                while(getchar() != '\n');
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
                    printf("Error: Opción no válida.\n");
                }
            } while (opcion != 5 && multa < 500.00f);
            return multa;
        }
    } while (tieneMultas != 0 && tieneMultas != 1);
    
}

void generarComprobante(Vehiculo vehiculos[], int totalVehiculos) {
    printf("\n\t-- GENERAR COMPROBANTE DE MATRICULACIÓN --\n");

    Vehiculo *v = buscarVehiculoPorPlaca(vehiculos, totalVehiculos);

    if (v == NULL) {
        printf("No se pudo generar el comprobante. Vehículo no encontrado.\n");
        return; // Importante: salir para evitar usar v
    }

    if (v->estaMatriculado != 1) {
        printf("El vehículo debe pasar primero por el proceso de matriculación\n");
        mensajeSalida();
        return;
    }

    // Calcular total a pagar
    float totalMatricula = v->multas + v->recargoTipo + v->recargoRegion + v->recargoAnio + v->recargoAvaluo;

    // Imprimir comprobante
    printf("\n========== COMPROBANTE DE MATRICULACIÓN ==========\n");
    printf("Cédula del propietario : %s\n", v->cedula);
    printf("Placa del vehículo     : %s\n", v->placa);
    printf("Tipo de vehículo       : %s\n", v->tipo);
    printf("Año del vehículo       : %d\n", v->anio);
    printf("Avalúo del vehículo    : %.2f\n", v->avaluo);

    printf("\n------------ VALORES A PAGAR ------------\n");
    printf("Multas pendientes      : %.2f\n", v->multas);
    printf("Impuesto al rodaje     : %.2f\n", v->recargoTipo);
    printf("Recargo por región     : %.2f\n", v->recargoRegion);
    printf("Recargo por año(> 2020): %.2f\n", v->recargoAnio);
    printf("Recargo por región     : %.2f\n", v->recargoAvaluo);
    printf("TOTAL A PAGAR          : %.2f\n", totalMatricula);
    printf("===========================================\n");

    mensajeSalida();
}

Vehiculo* buscarVehiculoPorPlaca(Vehiculo vehiculos[], int totalVehiculos) {
    if (totalVehiculos == 0) {
        printf("Actualmente no hay ningún vehículo registrado.\n");
        mensajeSalida();
        return NULL;
    }

    char placaBuscar[40];
    int valido = 0;

    do {
        printf("Ingrese la placa del vehículo (formato AAA-1234):\n");

        if (fgets(placaBuscar, sizeof(placaBuscar), stdin) == NULL) {
            printf("Error leyendo la entrada.\n");
            return NULL;
        }

        // Eliminar el salto de línea
        size_t len = strlen(placaBuscar);
        if (len > 0 && placaBuscar[len - 1] == '\n') {
            placaBuscar[len - 1] = '\0';
        }
 	//Convertir a mayúsculas antes de validar si el usuario ingresa en minuscula
    for (int i = 0; placaBuscar[i] != '\0'; i++) {
        placaBuscar[i] = toupper((unsigned char)placaBuscar[i]); //unsigned cahr para quitar tildes o caracteres invalidos
    }
        if (validarPlaca(placaBuscar)) {
            valido = 1;
        } else {
            printf("Placa inválida, inténtelo de nuevo.\n");
        }

    } while (!valido);

    for (int i = 0; i < totalVehiculos; i++) {
        if (strcmp(vehiculos[i].placa, placaBuscar) == 0) {
            return &vehiculos[i]; // Devuelve la dirección del vehículo encontrado
        }
    }

    printf("El vehículo con placa '%s' no fue encontrado.\n", placaBuscar);
    mensajeSalida();
    return NULL;
}


void mostrarDatosVehiculo(const Vehiculo* v) {
    if (v == NULL) {
        printf("Error: Vehículo no válido.\n");
        return;
    }

    printf("\n========== DATOS DEL VEHÍCULO ==========\n");
    printf("Cédula del propietario : %s\n", v->cedula);
    printf("Placa del vehículo     : %s\n", v->placa);
    printf("Tipo de vehículo       : %s\n", v->tipo);
    printf("Año del vehículo       : %d\n", v->anio);
    printf("Avalúo del vehículo    : %.2f\n", v->avaluo);
    printf("========================================\n");
    mensajeSalida();
}

void mostrarVehiculoPorPlaca(Vehiculo vehiculos[], int totalVehiculos){
    printf("\n\t-- BUSCADOR DE VEHICULO POR PLACA --\n");

    Vehiculo *v = buscarVehiculoPorPlaca(vehiculos, totalVehiculos);

    if (v == NULL) {
        printf("No se pudo generar el comprobante. Vehículo no encontrado.\n");
        return; // Importante: salir para evitar usar v
    }

    mostrarDatosVehiculo(v);
}

int revision() {
    printf("\n\t-- REVISIÓN TÉCNICA DEL VEHÍCULO --\n");

    int frenos = leerRespuestaSN("¿Los frenos están operables?");
    int luces  = leerRespuestaSN("¿Las luces funcionan correctamente?");
    int gases  = leerRespuestaSN("¿Los gases están dentro de los límites permitidos?");
    int llantas = leerRespuestaSN("¿Las llantas están en buen estado?");

    if (frenos && luces && gases && llantas) {
        printf("Revisión técnica aprobada.\n");
        return 1;
    } else {
        printf("Revisión técnica fallida.\n");
        return 0;
    }
}

void procesoMatriculacion(Vehiculo vehiculos[], int totalVehiculos){
    Vehiculo *v = buscarVehiculoPorPlaca(vehiculos, totalVehiculos);
    printf("\n\t-- PROCESO DE MATRICULACIÓN --\n");

    if (totalVehiculos == 0) {
        printf("No hay vehículos registrados.\n");
        mensajeSalida();
        return;
    }

    if (v == NULL){
        printf("No se pudo empezar el proceso de matriculación. Vehículo no encontrado.\n");
        mensajeSalida();
        return;
    }
    v->revisionesAnuales++;
    if (v->revisionesAnuales > MAX_REVISIONES_ANUALES)
    {
        printf("Se ha alcanzado el numero máximo de revisiones anuales\n");
        mensajeSalida();
        return;
    }
    printf("Las revisiones vehiculares son: %d\n", v->revisionesAnuales);
    // Verificar multas
    float multa = verificarMultas();
    v->multas = multa;

    if (multa > 0.0f) {
        printf("No puedes proceder con la revisión, tienes multas pendientes: %.2f\n", multa);
        mensajeSalida();
        return;
    }

    // Revisión técnica
    int aprobado = revision();
    v->estaMatriculado = aprobado;

}

void listarVehiculosMatriculados(Vehiculo vehiculos[], int totalVehiculos){
    printf("\n\t-- Lista de todos los vehículos Matriculados--\n");
    if (totalVehiculos == 0)
    {
        printf("Actualmente no hay ningún vehículo registrado \n");
    } else {
        for (int i = 0; i < totalVehiculos; i++)
        {
            if (vehiculos[i].estaMatriculado == 1)
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
    }
    mensajeSalida();
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
        printf("Ingrese la placa del vehículo (AAA-1234):\n");
        fgets(v.placa, sizeof(v.placa), stdin);

        // Eliminar salto de línea
        size_t len = strlen(v.placa);
        if (len > 0 && v.placa[len - 1] == '\n') {
            v.placa[len - 1] = '\0';
        }

        // Convertir primeros 3 caracteres a mayúsculas
        for (int i = 0; i < 3 && v.placa[i] != '\0'; i++) {
            v.placa[i] = toupper((unsigned char)v.placa[i]);
        }
    } while (validarPlaca(v.placa) != 1);

    // Leer cédula
    do
    {
        printf("Ingrese el número de cédula del propietario:\n");
        fgets(v.cedula, sizeof(v.cedula), stdin);
        size_t len = strlen(v.cedula);
        if (len > 0 && v.cedula[len - 1] == '\n') {
            v.cedula[len - 1] = '\0';
        }
    } while (validarCedula(v.cedula) != 1);

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
                // Asignar recargo según el tipo de vehículo
                v.recargoTipo = 5.0;
                break;
            case 2:
                strcpy(v.tipo, "Pesado");
                // Asignar recargo según el tipo de vehículo
                v.recargoTipo = 15.0;
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }

    } while (opt < 1 || opt > 2);
    //getchar(); // Limpiar salto de línea pendiente
	
    // Leer año del vehículo con validación mínima
    do {
        printf("Ingrese el año del vehículo (1950 - 2025):\n");
        if (scanf("%d", &v.anio) != 1 || v.anio <= 1950) {
            while (getchar() != '\n');
            v.anio = 0;
            printf("Error:Ingrese un valor correcto.\n");
        }
    } while (v.anio < 1950 || v.anio > 2025);
    getchar();
	if (v.anio>2020){
		v.recargoAnio= 15.0f;
	}

    // Leer avalúo con validación positiva
    do {
        printf("Ingrese el avalúo del vehículo (positivo):\n");
        if (scanf("%f", &v.avaluo) != 1) {
            while (getchar() != '\n');
            printf("Error:Ingrese un valor correcto.");
        }
    } while (v.avaluo <= 0 || v.avaluo > 10000000.0);
    getchar();
	if (v.avaluo <=10000){
		v.recargoAvaluo= 20.0f;}
	else if (v.avaluo>10000 && v.avaluo<25000){
		v.recargoAvaluo= 35.0f;}
	else if (v.avaluo>25000){
		v.recargoAvaluo= 50.0f;}
	
    // Región a la que pertenece el vehículo.
    int region;
    int resultadoRegion;
    float recargoRegion = 0.0f;
do {
	printf("Seleccione la region de la que proviene:\n");
	printf("1. Costa\n");
	printf("2. Sierra\n");
	printf("3. Oriente/Galápagos\n");
	printf("Opción: ");
	resultadoRegion = scanf("%d", &region);
	getchar();  
					
	if (resultadoRegion != 1 || (region != 1 && region!= 2 &&region!=3)) {
	printf("Entrada inválida: Intente de nuevo.\n");
	}
					
	} while (region != 1 && region != 2 &&region!=3);
// Asignar recargo según la región	
switch (region) {
        case 1:
            v.recargoRegion = 10.0f;
            break;
        case 2:
            v.recargoRegion = 0.0f;
            break;
        case 3:
            v.recargoRegion = 5.0f;
            break;
    }
    v.revisionesAnuales = 0;
    return v;
}
