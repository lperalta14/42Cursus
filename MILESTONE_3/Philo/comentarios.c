
/*
INICIALIZACIÓN:
┌─────────────────────────────────────┐
│ 1. parse()                          │ ← Validar argumentos ✓
├─────────────────────────────────────┤
│ 2. ft_init_struct()                 │ ← Guardar datos básicos ✓
│    - malloc(philos)                 │   y reservar array de philos ✓
├─────────────────────────────────────┤
│ 3. init_mutex()                     │ ← Crear TODOS los mutex: ✓
│    ├─ init_forks()                  │   • forks[n] ✓
│    ├─ pthread_mutex_init(print)     │   • print_mutex ✓
│    ├─ pthread_mutex_init(meal)      │   • meal_mutex ✓
│    └─ pthread_mutex_init(stop)      │   • stop_mutex ✓
├─────────────────────────────────────┤
│ 4. init_philos()                    │ ← Llenar datos de cada philo
├─────────────────────────────────────┤
│ 5. start_simulation()               │ ← Crear threads (pthread_create)
│    └─ monitor thread                │   y lanzar monitor
└─────────────────────────────────────┘

EJECUCIÓN:
┌─────────────────────────────────────┐
│ Los threads ejecutan su rutina      │
│ El monitor vigila muertes           │
└─────────────────────────────────────┘

LIMPIEZA:
┌─────────────────────────────────────┐
│ 6. wait_threads()                   │ ← pthread_join() para cada uno
├─────────────────────────────────────┤
│ 7. cleanup()                        │ ← Destruir y liberar:
│    ├─ destroy_mutex()               │   • pthread_mutex_destroy()
│    │  ├─ stop_mutex                 │     para cada mutex
│    │  ├─ meal_mutex                 │   • free(forks)
│    │  ├─ print_mutex                │   • free(philos)
│    │  └─ destroy_forks()            │
│    └─ free(philos)                  │
└─────────────────────────────────────┘
*/

/*******************************************************************
*pthread_mutex_t mutex;
*
*  // INICIALIZAR (al principio del programa)
*pthread_mutex_init(&mutex, NULL);
*
*  // BLOQUEAR (pedir la llave)
*pthread_mutex_lock(&mutex);      // Si está ocupado, ESPERA aquí
*
*  // DESBLOQUEAR (devolver la llave)
*pthread_mutex_unlock(&mutex);
*
*  // DESTRUIR (al final del programa)
*pthread_mutex_destroy(&mutex);

Siempre init antes de create: Los mutex deben existir antes de que los threads intenten usarlos.
Join antes de destroy: Espera a que los threads terminen antes de destruir los mutex.
Libera en orden inverso: Lo último que creaste, primero que destruyes.
Comprueba errores: pthread_create, pthread_mutex_init, etc. devuelven 0 si todo OK.
*******************************************************************/


/*¿Por qué cada mutex?

Mutex				Protege							¿Cuándo se usa?
forks[i]			Cada tenedor					Al comer (lock 2 tenedores, n y n+1)
print_mutex			printf()						Cada vez que imprimes status
meal_mutex			last_meal_time, lunched			Al comer y al comprobar muerte
stop_mutex			not_dead_yet					Al comprobar si seguir la simulación
*/

/*
1. ¿Qué hace cada filósofo en su rutina?
Un filósofo tiene un ciclo infinito (hasta que muera o termine la simulación):
1. PENSAR (thinking)
2. COGER TENEDORES (take forks)
3. COMER (eating)
4. SOLTAR TENEDORES (release forks)
5. DORMIR (sleeping)
6. Volver al paso 1

## Estructura rutina

función routine(argumento):
    1. Convertir el argumento a t_philo*
    2. Si el filósofo es PAR, esperar un poquito (evitar deadlock)
    3. Bucle infinito:
        a. Comprobar si la simulación sigue activa (not_dead_yet)
        b. PENSAR (opcional, o directamente ir a comer)
        c. COMER (coger tenedores → comer → soltar tenedores)
        d. DORMIR
*/