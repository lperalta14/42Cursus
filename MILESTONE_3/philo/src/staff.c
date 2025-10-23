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
	printf("%s%ld %d died%s\n", RED, current, table->philos[id].dni, NC);
	pthread_mutex_unlock(&table->print_mutex);
}

int	check_death(t_data *table)
{
	int		i;
	t_philo	*philo;
	long	hungry;

	i = 0;
	philo = table->philos;
	while (i < table->num_philos)
	{
		pthread_mutex_lock(&table->meal_mutex);
		hungry = get_time() - philo[i].last_meal_time;
		pthread_mutex_unlock(&table->meal_mutex);
		if (hungry > table->time_to_die)
		{
			pthread_mutex_lock(&table->stop_mutex);
			table->not_dead_yet = 0;
			pthread_mutex_unlock(&table->stop_mutex);
			usleep(80);
			printdead(table, i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philo_buffet(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->num_philos)
	{
		if (philo->table->must_eat_count > philo[i].lunched
			&& philo->table->must_eat_count != -1)
			return (0);
		i ++;
	}
	return (1);
}

void	*staff(void *arg)
{
	t_data	*table;
	t_philo	*philo;

	table = (t_data *)arg;
	philo = table->philos;
	while (1)
	{
		if (liveornot(table))
			break ;
		if (check_death(table))
			break ;
		if (liveornot(table)
			|| (table->must_eat_count != -1 && philo_buffet(philo) == 1))
			break ;
		usleep(100);
	}
	return (NULL);
}
