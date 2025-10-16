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
	return (1);
}

/*int	prints(t_data table)
{
	printf()
}*/

static int	parse(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (ft_error("./philos 'philos' 'die' 'eat' 'sleep' [n_of_eat]"));
	i = 1;
	while (argv[i])
	{
		if (ft_atolints(argv[i]) <= 0 || ft_atolints(argv[i]) > INT_MAX)
			return (ft_error("invalid argument"));
		i++;
	}
	return (0);
}

// ./philos "num_philos" "die" "eat" "sleep" [number_of_eat]
int	main(int argc, char **argv)
{
	t_data	*table;

	if (parse(argc, argv))
		return (1);
	table = malloc(sizeof(t_data));
	if (!table)
		return (1);
	if (ft_init_struct(argv, table) || ft_init_mutex(table)
		|| ft_init_philos(table))
		return (clean_up(table));
	//init filos (crear filosofos ✓ y asignar tenedores✓)
	//start simulation (rutina)
	//comprobar (monitor)
	//esperar que terminen los hilos
	clean_up(table);
	return (printf(GREEN"BIEN\n"NC), 0);
	//estás muerto?; (flag para terminar todos los hilos si uno muere)
}
