#Versión mínima de Cmake
cmake_minimum_required(VERSION 3.10)

#Nombre con el que el proyecto será reconocido
project(matriculacion_vehicular)

# Estandar de C que se va a usar en el proyecto
set(CMAKE_C_STANDARD 11)

# Directorio donde se agregan las encabezados
include_directories(header)

# Directorio en el que se encuentran los archivos .cpp o .c
file(GLOB SOURCES "src/*.c")

# Crear el ejecutable
add_executable(matriculacion_vehicular ${SOURCES})