# Pokefutbol  

### 1. **Temática de Fútbol y Posiciones**  
- **¿Para qué se implementó?**  
  Para adaptar el concepto de combate Pokémon a un entorno de fútbol, reemplazando las criaturas por futbolistas y los tipos elementales por posiciones en el campo.  
- **¿Por qué se consideró necesario?**  
  Se buscó crear un juego único que combinara la estrategia de los combates por turnos con la emoción del fútbol, haciendo que los jugadores se sintieran como entrenadores de un equipo.  
- **¿Cómo se llevó a cabo su implementación?**  
  Se definieron cuatro posiciones clave: **portero, defensa, mediocampista y delantero**, cada una con habilidades y roles distintos, similar a los tipos elementales en Pokémon.  

### 2. **Selección de Jugadores con Menú Interactivo**  
- **¿Para qué se implementó?**  
  Permitir armar equipos con futbolistas reales (5 colombianos y 5 de las ligas europeas por posición) mediante una interfaz clara.  
- **¿Por qué se consideró necesario?**  
  La personalización mejora la inmersión y la estrategia, evitando equipos genéricos.  
- **¿Cómo se implementó?**  
  - Listas de jugadores por posición (ej: `porteros[10] = {"Alisson Becker", "David Ospina", ...}`).  
  - Funciones `mostrarListaJugadores()` y `elegirJugador()` para selección numérica con validación de entrada.  

### 3. **Ataques Únicos por Posición**  
- **¿Para qué se implementó?**  
  Para diferenciar las habilidades de cada posición y reflejar su rol en el campo, como en Pokémon cada tipo tiene movimientos característicos.  
- **¿Por qué se consideró necesario?**  
  Sin ataques específicos, todas las posiciones se sentirían iguales, reduciendo la profundidad estratégica del juego.  
- **¿Cómo se llevó a cabo su implementación?**  
  Se diseñaron conjuntos de ataques temáticos para cada posición (ej: "Atajada Rápida" para porteros, "Disparo Fuerte" para delanteros) y se asignaron aleatoriamente cuatro ataques por jugador.  

### 4. **Sistema de Curación Limitada**  
- **¿Para qué se implementó?**  
  Para añadir un recurso estratégico que los jugadores deban gestionar durante el combate.  
- **¿Por qué se consideró necesario?**  
  Limitar las curaciones evita que el juego se vuelva repetitivo y fomenta decisiones tácticas.  
- **¿Cómo se llevó a cabo su implementación?**  
  Cada jugador tiene un contador de curaciones (`curacionesUsadas`) que permite solo dos usos por jugador, recuperando 30 puntos de vida cada vez.  

### 5. **Cambio de Jugador**  
- **¿Para qué se implementó?**  
  Para simular la dinámica de un partido de fútbol, donde los jugadores pueden ser sustituidos o recibir asistencia médica.  
- **¿Por qué se consideró necesario?**  
  Se considero necesario ya que nos permite adaptar la estrategia en tiempo real y gestionar el estado de los jugadores durante el combate.  
- **¿Cómo se llevó a cabo su implementación?**  
  Se implementó un sistema de turnos alternados donde los jugadores pueden elegir entre atacar, curarse o cambiar al futbolista activo, con validaciones para evitar acciones inválidas como el cambio por un futbolista que ya fue derrotado.  
