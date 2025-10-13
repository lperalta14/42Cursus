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
	int j;

	if (argc < 5 || argc > 6)
		return(0);
	//printf("argc: %i\n", argc);
	i = 1;
	while (argv[i])
	{
		j = 0;
		/*while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j])))
				return (0);
			j++;
		}*/
		if (ft_atolints(argv[i]) <= 0 || ft_atolints(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!parse(argc, argv))
		return(perror("error"), 1);
	//inicializar
	//crear hilos
	//comprobar
	//cerrar hilos
	//liberar
	return(printf("BIEN\n"), 0);
	//estás muerto?;
}