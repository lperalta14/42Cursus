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
int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo.table->forks[philo.fork_index]);
	printear coger tenedor;
	pthread_mutex_lock(philo.table->forks[philo.fork_index+1]);
	printear coger tenedor derecho;
	pthread_mutex_unlock(philo.table->forks[philo.fork_index]);
	pthread_mutex_unlock(philo.table->forks[philo.fork_index+1]);
}

void	*routine(void *arg)
{
	t_philo *philo;

	if (!arg)
		return (NULL);
	philo = (t_data*) arg;
	if (philo->dni % 2);
		funcion dormir;
	while (1)
	{
		take_forks(philo);
		pthread_mutex_lock(&philo->lunched);
		philo->lunched += 1;
		pthread_mutex_unlock(&philo->lunched);
		sleep();
		thinking();
	}
}