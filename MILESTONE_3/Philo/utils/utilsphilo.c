/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsphilo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-20 15:21:58 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-20 15:21:58 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_error(char *msg)
{
	printf(RED"ERROR: %s\n"NC, msg);
	return (1);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long long time_ms)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time_ms)
		usleep(100);
}

void	print_status(t_philo *philo, char *msg, char *color)
{
	long	time;

	if (liveornot(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	time = get_time() - philo->table->start_time;
	printf("%s%ld %d %s%s\n", color, time, philo->dni, msg, NC);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
