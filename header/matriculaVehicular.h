#ifndef MATRICULACIONVEHICULAR_H
#define MATRICULACIONVEHICULAR_H

typedef struct {
    char placa[50];
    char cedula[40];
    char tipo[50];
    int anio;
    float avaluo;
} Vehiculo;

Vehiculo registroVehiculo();
void buscarVehiculoPorPlaca(const char *placaBuscar);
void listarVehiculos();
void generarComprobante();

#endif
