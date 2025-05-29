
# Sistema de Parqueadero

## 1. Menú Interactivo

**¿Para qué se implementó?**  

El menú interactivo fue diseñado para proporcionar una interfaz de usuario clara y organizada que permita acceder a todas las funcionalidades del sistema de parqueadero de manera intuitiva.

**¿Por qué se consideró necesario?** 

Se consideró esencial para facilitar la operación del sistema tanto para administradores como para usuarios, evitando la necesidad de recordar comandos complejos y guiando al usuario paso a paso.

**¿Cómo se llevó a cabo su implementación?** 
 
- Se desarrolló la función `menu()` que contiene un bucle principal
- Se estructuró con seis opciones numeradas:
  1. Visualización del mapa de parqueo
  2. Registro de entrada de vehículos
  3. Proceso de salida de vehículos
  4. Consulta del historial completo
  5. Búsqueda de vehículos específicos
  6. Salida del sistema
- Cada selección ejecuta su función correspondiente
- Incluye validación básica para opciones no válidas

## 2. Historial de Vehículos

**¿Por qué se consideró necesario?** 

Se considera necesario para mantener un registro completo de todos los movimientos vehiculares para consultas posteriores y generación de reportes.

**¿Para qué se implementó?** 

Proporciona transparencia en las operaciones y permite resolver discrepancias, además de ofrecer datos para análisis de uso del parqueadero.

**¿Cómo se llevó a cabo su implementación?**
  
- Estructura de datos `historial` como lista global
- Cada registro contiene:
  - Placa del vehículo
  - Tipo de vehículo
  - Tiempo total de estancia
  - Costo generado
  - Ubicación exacta (fila, columna)
  - Horas exactas de entrada y salida
- Función `mostrar_historial()` para visualización ordenada

## 3. Sistema de Tarifas

**¿Por qué se consideró necesario?** 

Establecer costos distintos según el tipo de vehículo que va a hacer uso del parqueadero.

**¿Para qué se implementó?**   

Reconoce que vehículos ocupan los distintos espacios que hay en el parqueadero, por lo que el cobro debe reflejar estas diferencias.

**¿Cómo se llevó a cabo su implementación?** 
 
- Diccionario `tarifas` con valores por minuto para:
  - Carros (mayor tarifa)
  - Motos (tarifa media)
  - Bicicletas (menor tarifa)
- El cálculo considera:
  - El tiempo exacto en minutos
  - Aplicación de la tarifa correspondiente al tipo
  - Cálculo directo (minutos × valor/minuto)

## 4. Búsqueda de Vehículos por Placa

**¿Por qué se consideró necesario?** 

Permitir la localización rápida de cualquier vehículo actualmente estacionado en el parqueadero.

**¿Para qué se implementó?**   

Agiliza la gestión diaria y facilita la verificación de ciertos vehículos en especifico cuando es requerido por usuarios o el personal.

**¿Cómo se llevó a cabo su implementación?** 
  
- Función `buscar_vehiculo()` que:
  - Solicita la placa a buscar
  - Consulta el diccionario `vehiculos_activos`
  - Muestra resultados detallados si existe:
    - Ubicación exacta (coordenadas)
    - Tipo de vehículo
    - Hora de entrada
- Mensaje claro cuando no se encuentra el vehículo


