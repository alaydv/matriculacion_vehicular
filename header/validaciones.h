// validaciones.h
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#define ARCHIVO_COMPROBANTES "../data/comprobantes.txt"
#include "matriculaVehicular.h"
// Retorna 1 si la placa es válida, 0 si no
int validarPlaca(const char *placa);

// Retorna 1 si la cédula es válida, 0 si no
int validarCedula(const char *cedula);

// Retorna 1 si la respuesta es sí, 0 si no
int leerRespuestaSN(const char *pregunta);

// Valida que las placas no esten ya registradas
int placaExisteArchivo(const char *placaBuscar);

int comprobanteExisteVehiculo(const char *placa, Vehiculo *resultado);
#endif