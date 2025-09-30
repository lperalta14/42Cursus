/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 15:55:44 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-26 15:55:44 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_errors(&pipex, "Usage: ./pipex [file1] [command1] [command2] [file2]");
		return (1);
	}
	// parsear
	ft_init_pipex(&pipex, envp);
	ft_validpaths(&pipex, argv[2]);
	// hacer pipex
	ft_freepointers(pipex.paths);
	return (0);
}