/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 15:22:21 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-13 15:22:21 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				dni;
	int				lunched;
	long long		last_meal_time;
	pthread_t		thread;
	//pthread_mutex_t	*left_fork;
	int				fork_index;
	t_data			*table;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				not_dead_yet;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	stop_mutex;
	t_philo			*philos;
}	t_data;

/************************************************/
/*					UTILS						*/
/************************************************/
int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_atolints(const char *nptr);


#endif
