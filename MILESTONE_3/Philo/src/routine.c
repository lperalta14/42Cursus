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
void ft_usleep(long long time_ms)
{
	long long start;

	start = get_time();
	while (get_time() - start < time_ms)
		usleep(100);
}

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

void	print_status(t_philo *philo, char *msg, char *color)
{
	long	time;
	if (liveornot(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	time = get_time() - philo->table->start_time;
		printf("%s%lld %d %s%s\n",color, time, philo->dni, msg, NC);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork_index]);
	print_status(philo, "🔒 has taken first fucking fork", GREEN);
	pthread_mutex_lock(&philo->table->forks[(philo->fork_index+1)
		% philo->table->num_philos]);
	print_status(philo, "🔒 has taken second fucking fork", GREEN);
}
void	lunching(t_philo *philo)
{
	take_forks(philo);
	print_status(philo, "🍝 is eating", GREEN);
	pthread_mutex_lock(&philo->table->meal_mutex);
	philo->last_meal_time = get_time();
	philo->lunched += 1;
	pthread_mutex_unlock(&philo->table->meal_mutex);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[(philo->fork_index+1)
		% philo->table->num_philos]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_index]);

}

int	snaps(t_philo *philo)
{
	print_status(philo, "😴 is sleeping", PINK);
	ft_usleep(philo->table->time_to_snap);
}

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
		//thinking(philo)🤔;

	}
}
