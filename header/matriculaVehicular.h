#ifndef MATRICULACIONVEHICULAR_H
#define MATRICULACIONVEHICULAR_H

typedef struct {
    char placa[40];
    char cedula[40];
    char tipo[20];
    int anio;
    float avaluo;
    float multas;
    float recargoAvaluo;
    float recargoTipo;
    float recargoAnio;
    float recargoRegion;
    int estaMatriculado; // 0 no matriculado, 1 matriculado
    int revisionesAnuales;
} Vehiculo;

Vehiculo registroVehiculo();
// Vehiculo* buscarVehiculoPorPlaca(Vehiculo vehiculos[], int totalVehiculos);
// void mostrarVehiculoPorPlaca(Vehiculo vehiculos[], int totalVehiculos);
// void listarPorPlaca(Vehiculo vehiculos[], int totalVehiculos);
// void listarVehiculos(Vehiculo vehiculos[], int totalVehiculos);
// void generarComprobante(Vehiculo vehiculos[], int totalVehiculos);
// void listarVehiculosMatriculados(Vehiculo vehiculos[], int totalVehiculos);
// void procesoMatriculacion(Vehiculo vehiculos[], int totalVehiculos);
void mostrarDatosVehiculo(const Vehiculo* v);
int buscarVehiculoPorPlacaArchivoLeer(Vehiculo *encontrado);
// Funciones para la persistencia de datos
void registrarVehiculoArchivo();
void buscarVehiculoPorPlacaArchivo();
void listarVehiculosArchivo();
void procesoMatriculacionArchivo();
void listarVehiculosMatriculadosArchivo();
void generarComprobanteArchivo();

#endif
