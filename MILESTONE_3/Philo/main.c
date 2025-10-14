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

int	parse(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return(0);
	//printf("argc: %i\n", argc);
	i = 1;
	while (argv[i])
	{
		if (ft_atolints(argv[i]) <= 0 || ft_atolints(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	ft_init_stuct(char **argv, t_data *table)
{
	table->philo = malloc(sizeof(t_philo));
	

}

int	main(int argc, char **argv)
{
	t_data	*table;

	if (!parse(argc, argv))
	return(perror("error"), 1);
	table = malloc(sizeof(t_data));
	if (!table)
		return(1);
	//inicializar
	//crear hilos
	//comprobar
	//cerrar hilos
	//liberar
	return(printf("BIEN\n"), 0);
	//estás muerto?;
}