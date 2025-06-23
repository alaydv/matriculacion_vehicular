#ifndef MATRICULACIONVEHICULAR_H
#define MATRICULACIONVEHICULAR_H

typedef struct {
    char placa[10];
    char cedula[12];
    char tipo[50];
    int anio;
    float avaluo;
    float multas;
    int estaMatriculado; // 0 no matriculado, 1 matriculado
} Vehiculo;

Vehiculo registroVehiculo();
void buscarVehiculoPorPlaca(const char *placaBuscar);
void listarVehiculos(Vehiculo vehiculos[], int totalVehiculos);
void generarComprobante();
void listarVehiculosMatriculados();
void procesoMatriculacion(Vehiculo vehiculos[], int totalVehiculos);

#endif
