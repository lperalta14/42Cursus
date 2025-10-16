/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 16:45:11 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-09 16:45:11 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
INICIALIZACIÓN:
┌─────────────────────────────────────┐
│ 1. parse()                          │ ← Validar argumentos
├─────────────────────────────────────┤
│ 2. ft_init_struct()                 │ ← Guardar datos básicos
│    - malloc(philos)                 │   y reservar array de philos
├─────────────────────────────────────┤
│ 3. init_mutex()                     │ ← Crear TODOS los mutex:
│    ├─ init_forks()                  │   • forks[n]
│    ├─ pthread_mutex_init(print)     │   • print_mutex
│    ├─ pthread_mutex_init(meal)      │   • meal_mutex
│    └─ pthread_mutex_init(stop)      │   • stop_mutex
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
/*¿Por qué necesitas cada mutex?

Mutex				Protege							¿Cuándo se usa?
forks[i]			Cada tenedor					Al comer (lock 2 tenedores)
print_mutex			printf()						Cada vez que imprimes status
meal_mutex			last_meal_time, lunched			Al comer y al comprobar muerte
stop_mutex			not_dead_yet					Al comprobar si seguir la simulación
*/
#include "philo.h"


int	ft_error(char *msg)
{
	printf(RED"ERROR: %s\n"NC, msg);
	return(1);	
}

int	parse(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return(ft_error("./philos 'num_philos' 'die' 'eat' 'sleep' [number_of_eat]"));
	i = 1;
	while (argv[i])
	{
		if (ft_atolints(argv[i]) <= 0 || ft_atolints(argv[i]) > INT_MAX)
			return (ft_error("invalid argument"));
		i++;
	}
	return (0);
}


int	ft_init_struct(char **argv, t_data *table)
{
	table->num_philos = ft_atolints(argv[1]);
	table->time_to_die = ft_atolints(argv[2]);
	table->time_to_eat = ft_atolints(argv[3]);
	table->time_to_sleep = ft_atolints(argv[4]);
	table->must_eat_count = -1;
	if (argv[5])
		table->must_eat_count = ft_atolints(argv[5]);
	table->not_dead_yet = 1;
	table->start_time = 0;
	table->forks = NULL;
	table->count_mutext = 1;
	table->philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!table->philos)
		return (ft_error("failed init struct"));
	return (0);
}

int	ft_init_mutex(t_data *table)
{
	int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (ft_error("failed amlloc forks"));
	i = 0;
	while (i < table->num_philos)
	{
		table->count_mutext_forks = i;
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (destroy_mutex_forks(table));
		i++;
	}
	table->count_mutext = 1;
	if (pthread_mutex_init(&(table->print_mutex), NULL))
		return (ft_error("mutex init failed"));
	table->count_mutext = 2;
	if (pthread_mutex_init(&(table->meal_mutex), NULL))
		return (ft_error("mutex init failed"));
	table->count_mutext = 3;
	if (pthread_mutex_init(&(table->stop_mutex), NULL))
		return (ft_error("mutex init failed"));
	table->count_mutext = 4;
	return (0);
}

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

// ./philos "num_philos" "die" "eat" "sleep" [number_of_eat]
int	main(int argc, char **argv)
{
	t_data	*table;

	if (parse(argc, argv))
		return(1);
	table = malloc(sizeof(t_data));
	if (!table)
		return (1);
	//init data : init data y init mutex (mutex deben existir antes de crear los hilos)
	if (ft_init_struct(argv, table) || (ft_init_mutex(table)))
		return (1);
	//init filos (crear filosofos y asignar tenedores)
	//start simulation (rutina)
	//comprobar (monitor)
	//esperar que terminen los hilos
	clean_up(table);
	return(printf(GREEN"BIEN\n"NC), 0);
	//estás muerto?; (flag para terminar todos los hilos si uno muere)
}