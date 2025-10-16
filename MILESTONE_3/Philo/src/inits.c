/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-16 15:16:10 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-16 15:16:10 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

int	ft_init_philos(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].dni = i + 1;
		table->philos[i].lunched = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].fork_index = i + 1;
		table->philos[i].table = table;
		i++;
	}
	return (0);
}
