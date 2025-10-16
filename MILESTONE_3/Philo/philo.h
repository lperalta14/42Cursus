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

// COLORS
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[0;34m"
# define PINK	"\033[0;35m"
# define NC		"\033[0m"

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
	int				count_mutext;
	int				count_mutext_forks;
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
int		ft_strlen(char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_atolints(const char *nptr);
int		ft_error(char *msg);
long	get_time(void);

/************************************************/
/*					CLEAN						*/
/************************************************/
int		destroy_mutex_forks(t_data *table);
void	destroy_mutex(t_data *table);
int		clean_up(t_data *table);

/************************************************/
/*					INITS						*/
/************************************************/
int		ft_init_struct(char **argv, t_data *table);
int		ft_init_mutex(t_data *table);
int		ft_init_philos(t_data *table);

#endif