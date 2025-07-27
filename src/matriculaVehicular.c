
#include "matriculaVehicular.h"
#include "validaciones.h"
#include "utilidades.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h> 
#define MAX_REVISIONES_ANUALES 3
#define ARCHIVO_COMPROBANTES "../data/comprobantes.txt"

//Función para vehiculos
void listarVehiculosArchivo() {
    FILE *file = fopen("../data/vehiculos.txt", "rb");
    if (!file) {
        printf("Error: no se pudo abrir el archivo.\n");
        return;
    }

    Vehiculo v;
    int index = 1;
    printf("\n-------------------------------------------------------------");
    printf("\n%-5s %-10s %-15s %-10s %-6s %-10s\n", 
           "N°", "Placa", "Cédula", "Tipo", "Año", "Avalúo");
    printf("-------------------------------------------------------------\n");

    while (fread(&v, sizeof(Vehiculo), 1, file)) {
        printf("%-3d %-10s %-15s %-10s %-6d $%-9.2f\n", 
               index++, v.placa, v.cedula, v.tipo, v.anio, v.avaluo);
    }
    printf("-------------------------------------------------------------\n");

    fclose(file);
    mensajeSalida();
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

// Mostrar el comprobante con formato de tabla (desde un Vehiculo)
void mostrarComprobanteVehiculo(Vehiculo *v) {
    float total = v->multas + v->recargoTipo + v->recargoRegion + v->recargoAnio + v->recargoAvaluo;

    printf("\n========== COMPROBANTE DE MATRICULACIÓN ==========\n");
    printf("Placa: %s\n", v->placa);
    printf("Cédula: %s\n", v->cedula);
    printf("Total a pagar: %.2f\n", total);
}

void generarComprobanteArchivo() {
    Vehiculo v;

    if (!buscarVehiculoPorPlacaArchivoLeer(&v)) {
        printf("Vehículo no encontrado.\n");
        mensajeSalida();
        return;
    }

    if (v.estaMatriculado != 1) {
        printf("El vehículo no está matriculado.\n");
        mensajeSalida();
        return;
    }

    // Verificar si ya existe comprobante
    if (comprobanteExisteVehiculo(v.placa, NULL) == 1) {
        printf("\nYa existe un comprobante para la placa %s. \nMostrando comprobante...\n", v.placa);
        mostrarComprobanteVehiculo(&v);
        mensajeSalida();
        return;
    }

    float total = v.multas + v.recargoTipo + v.recargoRegion + v.recargoAnio + v.recargoAvaluo;

    printf("\n========== COMPROBANTE DE MATRICULACIÓN ==========\n");
    printf("Placa: %s\nCédula: %s\nTotal a pagar: %.2f\n", v.placa, v.cedula, total);

    FILE *comp = fopen("../data/comprobantes.txt", "a");
    if (comp) {
        fprintf(comp, "Placa: %s | Cédula: %s | Total: %.2f\n", v.placa, v.cedula, total);
        fclose(comp);
        printf("\nComprobante generado correctamente.\n");
    } else {
        printf("Error creando comprobante.\n");
    }
    mensajeSalida();
}

int buscarVehiculoPorPlacaArchivoLeer(Vehiculo *encontrado) {
    char placaBuscar[40];
    printf("Ingrese la placa a buscar: ");
    fgets(placaBuscar, sizeof(placaBuscar), stdin);
    placaBuscar[strcspn(placaBuscar, "\n")] = 0;
    // Convertir primeros 3 caracteres a mayúsculas
    for (int i = 0; i < 3 && placaBuscar[i] != '\0'; i++) {
        placaBuscar[i] = toupper((unsigned char)placaBuscar[i]);
    }

    FILE *file = fopen("../data/vehiculos.txt", "rb");
    if (!file) {
        printf("Error al abrir archivo.\n");
        return 0;
    }
    Vehiculo v;
    while (fread(&v, sizeof(Vehiculo), 1, file)) {
        if (strcmp(v.placa, placaBuscar) == 0) {
            *encontrado = v;
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void buscarVehiculoPorPlacaArchivo() {
    Vehiculo v;
    if (buscarVehiculoPorPlacaArchivoLeer(&v)) {
        mostrarDatosVehiculo(&v);
    } else {
        printf("Vehículo no encontrado.\n");
        mensajeSalida();
    }
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

void procesoMatriculacionArchivo() {
    FILE *file = fopen("../data/vehiculos.txt", "rb+");
    if (!file) {
        printf("Error al abrir archivo de vehículos.\n");
        return;
    }

    Vehiculo v;
    char placaBuscar[40];
    printf("Ingrese la placa del vehículo a matricular: ");
    fgets(placaBuscar, sizeof(placaBuscar), stdin);
    placaBuscar[strcspn(placaBuscar, "\n")] = '\0';
    // Convertir primeros 3 caracteres a mayúsculas
    for (int i = 0; i < 3 && placaBuscar[i] != '\0'; i++) {
        placaBuscar[i] = toupper((unsigned char)placaBuscar[i]);
    }

    int encontrado = 0;
    long pos;

    while (fread(&v, sizeof(Vehiculo), 1, file)) {
        if (strcmp(v.placa, placaBuscar) == 0) {
            encontrado = 1;
            pos = ftell(file) - sizeof(Vehiculo);
            break;
        }
    }

    if (!encontrado) {
        printf("Vehículo no encontrado.\n");
        fclose(file);
        mensajeSalida();
        return;
    }

    v.revisionesAnuales++;
    if (v.revisionesAnuales > 3) {
        printf("Número máximo de revisiones alcanzadas.\n");
        fclose(file);
        mensajeSalida();
        return;
    }

    printf("Número de revisiones: %d\n", v.revisionesAnuales);
    v.multas = verificarMultas();

    if (v.multas > 0.0f) {
        printf("No puedes matricular, tienes multas: %.2f\n", v.multas);
        fclose(file);
        mensajeSalida();
        return;
    }

    int aprobado = revision();
    v.estaMatriculado = aprobado;

    fseek(file, pos, SEEK_SET);
    fwrite(&v, sizeof(Vehiculo), 1, file);

    printf("\nProceso de matriculación completado.\n");
    fclose(file);
    mensajeSalida();
}

void listarVehiculosMatriculadosArchivo() {
    FILE *file = fopen("../data/vehiculos.txt", "rb");
    if (!file) {
        printf("Error al abrir archivo.\n");
        return;
    }

    Vehiculo v;
    int numVehiculo = 1;
    int encontrados = 0;

    printf("\n-------------------------------------------------------------\n");
    printf(" N°  Placa      Cédula          Tipo       Año   Avalúo\n");
    printf("-------------------------------------------------------------\n");

    while (fread(&v, sizeof(Vehiculo), 1, file)) {
        if (v.estaMatriculado == 1) {
            printf("%-4d%-11s%-16s%-11s%-6d$%.2f\n", 
                numVehiculo++, v.placa, v.cedula, v.tipo, v.anio, v.avaluo);
            encontrados = 1;
        }
    }

    if (encontrados == 0) {
        printf("       No hay vehículos matriculados registrados.\n");
    }

    printf("-------------------------------------------------------------\n");

    fclose(file);
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

void registrarVehiculoArchivo() {
    Vehiculo v = registroVehiculo();

    if (placaExisteArchivo(v.placa)) {
        printf("Error: Ya existe un vehículo registrado con la placa %s.\n", v.placa);
        mensajeSalida();
        return;
    }

    FILE *file = fopen("../data/vehiculos.txt", "ab"); // modo append binario
    if (file == NULL) {
        printf("Error al abrir el archivo de vehículos.\n");
        return;
    }
    fwrite(&v, sizeof(Vehiculo), 1, file);
    fclose(file);
    printf("\nVehículo registrado exitosamente.\n");
    mensajeSalida();
}