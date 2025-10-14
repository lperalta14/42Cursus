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
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int		numer;
	int		lunch;
	int		nap;
	int		think;
	int		alive;
	t_data	*table
}	t_philo;

typedef struct s_data
{
	t_philo		*philo;
	
}	t_data;


/************************************************/
/*					UTILS						*/
/************************************************/
int		ft_isspace(int c);
int		ft_isdigit(int c);
long	ft_atolints(const char *nptr);


#endif
