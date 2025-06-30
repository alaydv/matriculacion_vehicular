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
    float recargoRegion;
    int estaMatriculado; // 0 no matriculado, 1 matriculado
} Vehiculo;

Vehiculo registroVehiculo();
void buscarVehiculoPorPlaca(Vehiculo vehiculos[], int totalVehiculos);
void listarVehiculos(Vehiculo vehiculos[], int totalVehiculos);
void generarComprobante();
void listarVehiculosMatriculados(Vehiculo vehiculos[], int totalVehiculos);
void procesoMatriculacion(Vehiculo vehiculos[], int totalVehiculos);

#endif
