/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-16 13:42:35 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-16 13:42:35 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_mutex_forks(t_data *table)
{
	int	i;

	if (!table->forks)
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

void	destroy_mutex(t_data *table)
{
	int	n;

	n = table->count_mutext;
	if (n > 0)
		destroy_mutex_forks(table);
	if (n > 1)	
		pthread_mutex_destroy(&table->print_mutex);
	if (n > 2)
		pthread_mutex_destroy(&table->meal_mutex);
	if (n > 3)	
		pthread_mutex_destroy(&table->stop_mutex);
}

void	clean_up(t_data *table)
{
	if (!table)
		return ;
	if (table->forks)
		destroy_mutex(table);
	free(table);
}
