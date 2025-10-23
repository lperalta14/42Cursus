/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 16:45:11 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-09 16:45:11 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (ft_error("./philos 'philos' 'die' 'eat' 'sleep' [n_of_eat]"));
	i = 1;
	while (argv[i])
	{
		if (ft_atolints(argv[i]) <= 0 || ft_atolints(argv[i]) > INT_MAX)
			return (ft_error("invalid argument"));
		i++;
	}
	return (0);
}

int	philos_join(t_data *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i ++;
	}
	return (0);
}

/*./philos "num_philos" "die" "eat" "sleep" [number_of_eat]*/
int	main(int argc, char **argv)
{
	t_data	*table;

	if (parse(argc, argv))
		return (1);
	table = malloc(sizeof(t_data));
	if (!table)
		return (1);
	if (ft_init_struct(argv, table) || ft_init_mutex(table)
		|| ft_init_philos(table))
		return (clean_up(table));
	if (ft_init_threads(table))
		return (clean_up(table));
	staff(table);
	philos_join(table);
	clean_up(table);
	return (0);
}
