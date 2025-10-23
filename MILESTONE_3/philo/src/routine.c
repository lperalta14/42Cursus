/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-16 17:00:57 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-16 17:00:57 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	liveornot(t_data	*table)
{
	pthread_mutex_lock(&table->stop_mutex);
	if (table->not_dead_yet == 0)
	{
		pthread_mutex_unlock(&table->stop_mutex);
		return (1);
	}
	pthread_mutex_unlock(&table->stop_mutex);
	return (0);
}

int	take_forks(t_philo *philo)
{
	int	left;
	int	right;

	left = philo->fork_index;
	right = (philo->fork_index + 1) % philo->table->num_philos;
	if (pthread_mutex_lock(&philo->table->forks[left]))
		return (1);
	print_status(philo, "has taken a fork", GREEN);
	if (left == right || pthread_mutex_lock(&philo->table->forks[right]))
	{
		ft_usleep(philo->table->time_to_die);
		pthread_mutex_unlock(&philo->table->forks[left]);
		return (1);
	}
	print_status(philo, "has taken a fork", GREEN);
	return (0);
}

int	lunching(t_philo *philo)
{
	if (take_forks(philo))
		return (1);
	print_status(philo, "is eating", GREEN);
	if (pthread_mutex_lock(&philo->table->meal_mutex))
	{
		pthread_mutex_unlock(&philo->table->forks[(philo->fork_index + 1)
			% philo->table->num_philos]);
		pthread_mutex_unlock(&philo->table->forks[philo->fork_index]);
		return (1);
	}
	philo->lunched += 1;
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->table->meal_mutex);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[(philo->fork_index + 1)
		% philo->table->num_philos]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_index]);
	return (0);
}

void	snaps_think(t_philo *philo)
{
	if (liveornot(philo->table))
		return ;
	print_status(philo, "is sleeping", PINK);
	ft_usleep(philo->table->time_to_snap);
	if (liveornot(philo->table))
		return ;
	print_status(philo, "is thinking", YELLOW);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		maxlunch;

	if (!arg)
		return (NULL);
	philo = (t_philo *) arg;
	maxlunch = philo->table->must_eat_count;
	if (philo->dni % 2 == 0)
		usleep(100);
	while (philo->lunched < maxlunch || maxlunch == -1)
	{
		if (liveornot(philo->table))
			break ;
		if ((liveornot(philo->table))
			|| (philo->lunched >= maxlunch && maxlunch != -1))
			break ;
		if (liveornot(philo->table) || lunching(philo))
			break ;
		if (liveornot(philo->table)
			|| (philo->lunched >= maxlunch && maxlunch != -1))
			break ;
		snaps_think(philo);
	}
	return (NULL);
}
