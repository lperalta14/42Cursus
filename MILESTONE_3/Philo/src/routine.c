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

void	print_status(t_philo *philo, char *msg)
{
	long	time;
	if (liveornot(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	time = get_time() - philo->table->start_time;
		printf(GREEN"%lld %d %s\n"NC, time, philo->dni, msg);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork_index]);
	print_status(philo, "🔒 has taken first fucking fork");
	pthread_mutex_lock(&philo->table->forks[(philo->fork_index+1)
		% philo->table->num_philos]);
	print_status(philo, "🔒 has taken second fucking fork");
	return (1);
}
int	lunching(t_philo *philo)
{
	take_forks(philo);
	print_status(philo, "🍝 is eating");
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_time = get_time();
	philo->lunched += 1;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	//funcionusleep(esperar tiempo de comer);
	pthread_mutex_unlock(&philo->table->forks[(philo->fork_index+1)
		% philo->table->num_philos]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_index]);
	return (1);
}

int	snaps(t_philo *philo)
{}
void	*routine(void *arg)
{
	t_philo *philo;

	if (!arg)
		return (NULL);
	philo = (t_philo*) arg;
	if (philo->dni % 2 == 0)
		usleep(100);
	while (1)
	{
		if (liveornot(philo->table))
			break ;
		lunching(philo);
		//snaps(philo);
		//thinking(philo);
	}
}