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


//# COLORS
RED=\033[0;31m;
GREEN=\033[0;32m;
YELLOW=\033[1;33m;
BLUE=\033[0;34m;
PINK=\033[0;35m;
NC=\033[0m;
*/

#include "philo.h"

int	parse(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return(0);
	i = 1;
	while (argv[i])
	{
		if (ft_atolints(argv[i]) <= 0 || ft_atolints(argv[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	free_mutex_forks(t_data *table)
{
	int	i;

	if (table->forks)
		return (1);
	i = 0;
	while (i < table->count_mutext_forks)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
	table->forks = NULL;
	return (1);
}

void	free_mutex(t_data *table)
{
	int	n;

	n = table->count_mutext;
	if (n > 0)
		free_mutex_forks(table);
	if (n > 1)	
		pthread_mutex_destroy(&table->print_mutex);
	if (n > 2)
		pthread_mutex_destroy(&table->meal_mutex);
	if (n > 3)	
		pthread_mutex_destroy(&table->stop_mutex);
}

int	ft_error(char *msg)
{
	printf("\033[0;31mERROR; %s\033[0m", msg);
	return(1);	
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
			return (free_mutex_forks(table));
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
	return(perror("error"), 1);
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
	free_mutex(table);
	return(printf("\033[0;32mBIEN\033[0m\n"), 0);
	//estás muerto?; (flag para terminar todos los hilos si uno muere)
}