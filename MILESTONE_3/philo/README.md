# 🧠 Philosophers

> Concurrencia con threads y mutex.  
> El clásico problema de los filósofos cenando: sincronización, deadlocks y race conditions.

---

## 📘 Descripción general

Este proyecto forma parte del **Cursus de 42 Málaga** y se incluye dentro del **MILESTONE_3**, enfocado en el desarrollo de competencias como:
- Programación concurrente con threads (hilos).
- Sincronización mediante mutex.
- Prevención de deadlocks y race conditions.
- Gestión precisa del tiempo.
- Debugging de programas multihilo.

El objetivo principal es **resolver el problema clásico de los filósofos cenando** de Dijkstra, donde varios filósofos comparten tenedores y deben evitar morir de hambre mientras piensan y comen, sin caer en deadlock.

**El problema:**
- N filósofos sentados en una mesa circular
- N tenedores (uno entre cada par de filósofos)
- Para comer, un filósofo necesita 2 tenedores
- Un filósofo puede: comer, pensar o dormir
- Si un filósofo no come a tiempo, muere

---

## ⚙️ Tecnologías y herramientas

| Categoría | Herramienta / Tecnología |
|------------|--------------------------|
| Lenguaje | C |
| Compilador | GCC / Clang |
| Estilo | Norminette |
| Depuración | Valgrind / Helgrind / GDB |
| Threading | pthread (POSIX threads) |
| Sincronización | mutex (pthread_mutex) |
| Control de versiones | Git + GitHub |

---

## 🧩 Estructura del proyecto

```bash
📦 philo
├── src/
│   ├── main.c                  # Punto de entrada
│   ├── init.c                  # Inicialización de estructuras
│   ├── philosopher.c           # Rutina de cada filósofo
│   ├── actions.c               # Acciones: comer, dormir, pensar
│   ├── monitor.c               # Monitoreo de muerte
│   ├── time.c                  # Gestión de tiempos
│   ├── utils.c                 # Funciones auxiliares
│   └── cleanup.c               # Liberación de recursos
├── includes/
│   └── philo.h                 # Cabeceras y estructuras
├── Makefile                    # Compilación
└── README.md                   # Esta documentación
```

---

## 🚀 Compilación y ejecución

### 🛠️ Compilar
```bash
make
```

### ▶️ Ejecutar
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Parámetros:**
- `number_of_philosophers`: Número de filósofos (y tenedores)
- `time_to_die`: Tiempo (ms) desde el inicio de comer hasta morir si no vuelve a comer
- `time_to_eat`: Tiempo (ms) que tarda un filósofo en comer
- `time_to_sleep`: Tiempo (ms) que tarda un filósofo en dormir
- `number_of_times_each_philosopher_must_eat`: [OPCIONAL] El programa termina si todos han comido al menos este número de veces

### 🧪 Ejemplos

**Ejemplo 1: Ningún filósofo debe morir**
```bash
./philo 5 800 200 200
```
**Salida esperada:**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
...
```

**Ejemplo 2: Un filósofo debe morir**
```bash
./philo 4 310 200 100
```
**Salida esperada:**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
...
510 2 died
```

**Ejemplo 3: Con límite de comidas**
```bash
./philo 5 800 200 200 7
```
Cada filósofo debe comer 7 veces, luego el programa termina.

**Ejemplo 4: Caso edge - 1 filósofo**
```bash
./philo 1 800 200 200
```
**Salida esperada:**
```
0 1 has taken a fork
800 1 died
```

**Ejemplo 5: Muchos filósofos**
```bash
./philo 200 800 200 200
```
Ninguno debe morir.

---

## 📊 Formato de salida

Cada acción debe ser logueada con el siguiente formato:
```
timestamp_in_ms X [action]
```

**Acciones posibles:**
- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

**Reglas:**
- ⏱️ El timestamp es en milisegundos desde el inicio del programa
- 📝 Los mensajes no deben mezclarse (usar mutex para printf)
- ☠️ Un mensaje de muerte debe aparecer en menos de 10ms después de la muerte real
- 🛑 Ningún mensaje debe aparecer después de la muerte de un filósofo

---

## 🔍 Tests y validaciones

- **Valgrind** para comprobar fugas de memoria:
  ```bash
  valgrind --leak-check=full ./philo 4 410 200 200
  ```

- **Helgrind** para detectar data races:
  ```bash
  valgrind --tool=helgrind ./philo 5 800 200 200
  ```

- **Norminette** para verificar estilo:
  ```bash
  norminette src/ includes/
  ```

- **Tests de no muerte**:
  ```bash
  # Ningún filósofo debe morir
  ./philo 5 800 200 200
  ./philo 4 410 200 200
  ./philo 100 800 200 200
  ./philo 200 800 200 200
  ```

- **Tests de muerte**:
  ```bash
  # Un filósofo debe morir
  ./philo 1 800 200 200
  ./philo 4 310 200 100
  ```

- **Tests de argumentos inválidos**:
  ```bash
  # Argumentos negativos
  ./philo 5 -800 200 200
  # Output: Error
  
  # 0 filósofos
  ./philo 0 800 200 200
  # Output: Error
  
  # No numérico
  ./philo abc 800 200 200
  # Output: Error
  ```

- **Test de precisión temporal**:
  ```bash
  # La muerte debe detectarse rápido (< 10ms de delay)
  ./philo 4 310 200 100
  # Verificar que el timestamp de muerte es preciso
  ```

---

## 🧠 Conceptos clave del proyecto

- [x] Threading con pthread_create() y pthread_join()
- [x] Sincronización con mutex (pthread_mutex)
- [x] Prevención de deadlocks
- [x] Prevención de data races
- [x] Gestión precisa de tiempos (usleep, gettimeofday)
- [x] Monitoreo de estado de threads
- [x] Cleanup correcto de recursos
- [x] Programación concurrente segura

---

## 📈 Retos y aprendizajes

**Lo más difícil:**
- Evitar deadlocks cuando todos los filósofos intentan tomar el tenedor izquierdo al mismo tiempo
- Detectar la muerte de un filósofo con precisión de milisegundos
- Sincronizar correctamente el acceso a variables compartidas
- Gestionar el cleanup de threads y mutex sin leaks

**Lo que aprendí:**
- Fundamentos de programación concurrente
- Cómo usar mutex correctamente para proteger recursos compartidos
- Técnicas para prevenir deadlocks (orden de adquisición de locks, pares/impares)
- La importancia de la precisión temporal en sistemas concurrentes
- Debugging de programas multihilo con Helgrind

**Estrategia anti-deadlock implementada:**
- Filósofos con ID par toman primero el tenedor izquierdo
- Filósofos con ID impar toman primero el tenedor derecho
- Esto rompe la condición circular de espera

**Optimizaciones:**
- Uso de usleep inteligente para evitar busy waiting
- Monitoreo centralizado de muerte en thread separado (opcional)
- Logs protegidos con un solo mutex global

---

## 🧵 Arquitectura de threads

```
Main Thread
  ├── Crea estructura de datos
  ├── Inicializa N mutex (tenedores)
  ├── Crea N threads (filósofos)
  │     ├── Philosopher 1 (thread)
  │     ├── Philosopher 2 (thread)
  │     ├── ...
  │     └── Philosopher N (thread)
  ├── [Opcional] Monitor thread (para detectar muerte)
  └── pthread_join() - espera a que terminen
```

**Cada filósofo (thread):**
1. Intenta tomar 2 tenedores (mutex)
2. Come (sleep)
3. Suelta los tenedores (unlock mutex)
4. Duerme (sleep)
5. Piensa
6. Repite hasta morir o completar comidas requeridas

---

## 🍴 Estados del filósofo

```
     ┌─────────┐
     │ THINKING│
     └────┬────┘
          │
          v
   ┌──────────────┐
   │ TAKING FORKS │
   └──────┬───────┘
          │
          v
     ┌─────────┐
     │ EATING  │
     └────┬────┘
          │
          v
     ┌─────────┐
     │ SLEEPING│
     └────┬────┘
          │
          └──> (vuelve a THINKING)

     [En cualquier momento]
          │
          v
     ┌─────────┐
     │  DIED   │
     └─────────┘
```

---

## 🔒 Recursos protegidos por mutex

| Recurso | Tipo de mutex | Propósito |
|---------|---------------|-----------|
| Tenedores | Individual por tenedor | Evitar que 2 filósofos usen el mismo tenedor |
| Printf | Mutex global | Evitar mensajes mezclados |
| last_meal_time | Mutex por filósofo | Actualizar tiempo de última comida |
| is_dead flag | Mutex global | Detener todos cuando alguien muere |

---

## ⚠️ Errores comunes a evitar

❌ **Data race en printf** → Usar mutex para proteger todos los prints  
❌ **Deadlock circular** → Implementar orden de adquisición de tenedores  
❌ **Busy waiting excesivo** → Usar usleep inteligente  
❌ **Detección tardía de muerte** → Chequear frecuentemente last_meal_time  
❌ **Memory leaks de threads** → Hacer pthread_join() de todos los threads  
❌ **Destruir mutex mientras están locked** → Asegurar unlock antes de destroy  

---

## 🧩 Funciones del sistema utilizadas

| Función | Uso |
|---------|-----|
| `pthread_create()` | Crear threads |
| `pthread_join()` | Esperar a que un thread termine uniendolo al flujo principal |
| `pthread_detach()` | [Opcional] Detach de threads |
| `pthread_mutex_init()` | Inicializar mutex |
| `pthread_mutex_destroy()` | Destruir mutex |
| `pthread_mutex_lock()` | Adquirir lock |
| `pthread_mutex_unlock()` | Liberar lock |
| `gettimeofday()` | Obtener timestamp preciso |
| `usleep()` | Sleep en microsegundos |

---

## 👤 Autor

**Luis Peralta (lperalta14)**  
📍 42 Málaga  
💼 [LinkedIn](https://www.linkedin.com/in/lperaltamuñoz/)  
💻 [GitHub](https://github.com/lperalta14)  
📧 luisperaltamunoz@gmail.com

---

💡 *"En la mesa de los filósofos, no hay espacio para el ego, solo para la sincronización."*  
🍝 *Nadie dijo que comer espagueti con threads sería fácil.*
