// validaciones.h
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

// Retorna 1 si la placa es válida, 0 si no
int validarPlaca(const char *placa);

// Retorna 1 si la cédula es válida, 0 si no
int validarCedula(const char *cedula);

// Retorna 1 si la respuesta es sí, 0 si no
int leerRespuestaSN(const char *pregunta);

#endif