# Avance del Proyecto: Sistema Integral de Matriculación Vehicular

## SEMANAS 2 a 3

### Introducción

Durante las semanas 2 y 3 se han logrado importantes avances en el desarrollo del sistema de matriculación vehicular, aplicando metodología ágil **Scrum** y una planificación basada en objetivos SMART. A continuación, se detallan los entregables alcanzados, los roles del equipo, y cómo se alinearon las tareas con la **matriz RACI**.

---

## Roles Asignados

| Nombre           | Rol           | Función principal |
|------------------|----------------|--------------------|
| **Alay Erick**   | Líder / Scrum Master | Coordinación general, facilitación de reuniones, seguimiento de entregables |
| **Amanta David** | Tester         | Validación de funcionalidades, pruebas manuales |
| **Delgado Claris** | Programador 1 | Desarrollo de funciones clave del sistema |
| **Duran John**   | Programador 2 | Apoyo en codificación y estructuración del sistema |

---

## Objetivos SMART Relacionados

- **Específico**: Desarrollar funciones para registro vehicular, lectura de datos y persistencia.
- **Medible**: Implementar funcionalidades con archivos ".txt", registrar vehículos con datos válidos.
- **Alcanzable**: Distribución clara de tareas por rol, uso de GitHub y README básico.
- **Relevante**: Aplicación directa de estructuras, archivos y buenas prácticas de código.
- **Temporal**: Sprint con duración de 2 semanas, desde la planificación hasta la revisión.

---

## Entregables por Semana

### Semana 2 - Sprint 1

- Registro de vehículos (datos: placa, cédula, año, tipo, avalúo)
- Guardado en archivo ".txt"
- Lectura de datos al iniciar el programa
- Repositorio en GitHub con ramas y commits iniciales
- Estructura básica del archivo "README.md"

### Semana 3 - Avance de Sprint 2 (parcial)

- Implementación inicial de la función para cálculo de matrícula
- Diseño preliminar de las reglas de negocio (multas, recargos, descuentos)
- Avances en validaciones de entrada
- Inicio de desarrollo de búsqueda por placa
- Mejora de documentación técnica en el "README.md"

---

## Matriz RACI Aplicada

| Actividad                       | Responsable (R)     | Aprobador (A)      | Consultado (C)       | Informado (I)        |
|--------------------------------|----------------------|---------------------|------------------------|-----------------------|
| Registro de vehículos          | Claris, John         | Erick               | David (pruebas)        | Todos                 |
| Guardado en archivo            | John                 | Erick               | Claris (estructura)    | Todos                 |
| Lectura desde archivo          | Claris               | Erick               | David (validación)     | Todos                 |
| Validaciones y entrada         | David                | Erick               | Claris, John           | Todos                 |
| Revisión de repositorio GitHub | Erick                | Erick               | Todos                  | Todos                 |
| README inicial y mejoras       | Erick, Claris        | Erick               | Todos                  | Todos                 |

---
## SEMANAS 3 a 4

Durante las semanas 3 y 4 se implementaron mejoras clave en el sistema de matriculación vehicular, enfocadas en ampliar la funcionalidad, fortalecer la validación de datos y optimizar la experiencia del usuario. Nuestro equipo trabajó aplicando metodología **Scrum** y siguiendo los objetivos semanales establecidos.
## Roles Asignados

| Nombre         | Rol                | Función principal                                         |
|----------------|--------------------|-----------------------------------------------------------|
| Alay Erick     | Líder / Scrum Master | Coordinación general, validaciones adicionales            |
| Amanta David   | Tester             | Pruebas de robustez en el registro y matriculación, realización del README       |
| Delgado Claris | Programador 1      | Función de listado con parámetros y detalles ampliados     |
| Duran John     | Programador 2      | Desarrollo de revisión técnica y proceso de matriculación  |
---

## Actualizaciones y Funcionalidades Implementadas

**Estructura 'Vehiculo' ampliada**  
- Se añadieron los campos "float multas" para registrar el monto de infracciones y "int estaMatriculado" para indicar si el vehículo ya completó el proceso de matriculación.

**Nuevas funciones declaradas en "matriculaVehicular.h"**  
- "verificarMultas()"  
- "listarVehiculosMatriculados()"  
- "procesoMatriculacion()"  
- La función "listarVehiculos()" ahora recibe parámetros para mayor flexibilidad.

**Expansión del menú principal (main.c)**  
- Se ampliaron las opciones de 5 a 7, incorporando:  
  - Opción 4: Listado de vehículos matriculados  
  - Opción 6: Proceso de matriculación completo  

**Cambios en el flujo del programa (switch principal)**  
- Opción 3: Llama a "listarVehiculos()" con parámetros.  
- Opción 4: Visualiza solo los vehículos matriculados.  
- Opción 6: Inicia el proceso completo de matriculación.  

**Mejoras en "matriculacionVehicular.c"**  
- "listarVehiculos()" ofrece información más detallada.  
- "verificarMultas()" permite registrar múltiples infracciones.  
- Nueva función auxiliar "leerRespuestaSN()" para validar respuestas de tipo 's' o 'n'.  

**Proceso de revisión y matriculación**  
- Revisión técnica de frenos, luces, gases y llantas.  
- Solo los vehículos sin multas y que aprueben la revisión se matriculan.  
- El campo "estaMatriculado" se actualiza e informa al usuario.  

**Robustez en el registro de vehículos**  
- Validaciones estrictas en la longitud de cédula y placa.   

---

## Matriz RACI Aplicada

| Actividad                                | Responsable (R) | Aprobador (A) | Consultado (C)   | Informado (I) |
|------------------------------------------|------------------|----------------|-------------------|----------------|
| Ampliación estructura 'Vehiculo'         | John             | Erick          | Claris, David     | Todos          |
| Nuevas funciones en "matriculaVehicular.h" | Claris           | Erick          | Todos             | Todos          |
| Expansión de menú principal              | Claris, John     | Erick          | Todos             | Todos          |
| Proceso de matriculación completo        | John             | Erick          | David             | Todos          |
| Validaciones estrictas de entrada        | Erick, David     | Erick          | Todos             | Todos          |

---

## Conclusión

Las actualizaciones realizadas durante este sprint fortalecieron significativamente la estructura y funcionalidad del sistema. La gestión de datos y el proceso de matriculación es ahora más eficiente. El equipo continuará con la siguiente fase, enfocándose en cálculos adicionales y validaciones avanzadas.

---
## SEMANAS 4 a 5

Durante las semanas 4 y 5, el equipo continúa con el desarrollo del sistema de matriculación vehicular, centrando los esfuerzos en mejorar las funcionalidades y la validación de datos, de acuerdo a la planificación ágil **Scrum** y los objetivos establecidos. A continuación, se detallan las tareas asignadas, los entregables,  y cómo se alinean con la **matriz RACI**.


---

## Roles Asignados

| Nombre         | Rol                | Función principal                                         |
|----------------|--------------------|-----------------------------------------------------------|
| Alay Erick     | Líder / Scrum Master | Coordinación general, búsqueda de vehículo por placa, módulo regex |
| Amanta David   | Tester             | Validaciones, pruebas manuales, verificación de listados y elaboración del README |
| Delgado Claris | Programador 1      |Cálculo considerando peso y región del automóvil|
| Duran John     | Programador 2      | Desarrollo de la función del listado de vehículos matriculados, incluyendo validaciones.      |

---

## Tareas y Funcionalidades Planeadas para el Sprint

**Cálculo considerando el peso del vehículo y su región**  
- Si el vehículo es liviano o pesado afecta el costo.  
- La región del propietario (Sierra, Costa, Oriente, etc.) también influye en el valor final.

**Función para listar vehículos matriculados con validación**  
- Solo se listan vehículos que hayan pasado el proceso de revisión técnica.  
- Los vehículos sin revisión completa no aparecerán en el listado.

**Búsqueda de vehículo por placa**  
- Implementación de función robusta para buscar un vehículo mediante su número de placa.  
- Validación previa de la placa utilizando expresiones regulares (regex).

**Módulo de expresiones regulares (regex) para validaciones**  
- Validación de placa, cédula y otros campos mediante patrones regex.  



## Matriz RACI Aplicada

| Actividad                            | Responsable (R) | Aprobador (A) | Consultado (C)   | Informado (I) |
|-------------------------------------|------------------|----------------|-------------------|----------------|
| Cálculo efectuado el con peso y la región | Claris             | Erick          | Todos             | Todos          |
| Listado de vehículos con validación | John          | Erick          | David             | Todos          |
| Búsqueda de vehículo por placa      | Erick            | Erick          | Todos             | Todos          |
| Módulo de regex                     | Erick  | Erick         | Todos   | Todos          |

---


## Conclusión

Este sprint se enfoca en mejorar la robustez y confiabilidad del sistema, incorporando validaciones estrictas y cálculos más precisos. El trabajo continuo colaborativo nos permite alcanzar los avances semanales (sprints) del proyecto.

---
## Herramientas Utilizadas

- **Lenguaje**: C
- **Control de versiones**: Git / GitHub
- **Metodología**: Scrum
- **Documentación**: Markdown ("README.md")

---

