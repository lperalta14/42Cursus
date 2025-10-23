/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-21 16:59:54 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-21 16:59:54 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	printdead(t_data *table, int id)
{
	long	current;

	pthread_mutex_lock(&table->print_mutex);
	current = get_time() - table->start_time;
	printf("%s%ld %d 💀died%s\n", RED, current, table->philos[id].dni, NC);
	pthread_mutex_unlock(&table->print_mutex);
}

int	check_death(t_data *table)
{
	int		i;
	t_philo	*philo;
	long	hungry;

	i = 0;
	philo = table->philos;
	if (liveornot(table))
		return (1);
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->meal_mutex);
		hungry = get_time() - philo[i].last_meal_time;
		pthread_mutex_unlock(&table->meal_mutex);
		if (hungry > table->time_to_die && (table->must_eat_count 
			> philo[i].lunched || table->must_eat_count == -1))
		{
			printdead(table, i);
			pthread_mutex_lock(&table->stop_mutex);
			table->not_dead_yet = 0;
			pthread_mutex_unlock(&table->stop_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}
/*
void	*staff(void *arg)
{
	t_data	*table;
	t_philo	*philo;
	int		i;

	table = (t_data *)arg;
	philo = table->philos;
	i = 0;
	while (table->must_eat_count > philo[i].lunched
		|| table->must_eat_count == -1)
	{
		if (check_death(table))
			return (NULL);
		usleep(10000);
	}
	return (NULL);
}*/

void	*staff(void *arg)
{
	t_data	*table;

	table = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&table->stop_mutex);
		if (!table->not_dead_yet)
		{
			pthread_mutex_unlock(&table->stop_mutex);
			break;
		}
		pthread_mutex_unlock(&table->stop_mutex);
		
		if (check_death(table))
			break;
		usleep(10);
	}
	return (NULL);
}
