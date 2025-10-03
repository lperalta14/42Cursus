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
		ft_errors(NULL, "Usage: ./pipex [file1] [command1] [command2] [file2]");
	ft_init_pipex(&pipex, argv, envp);
	if (pipe(pipex.fdpipe) == -1)
		ft_errors(&pipex, "Pipe error");
	ft_pipex(&pipex, argv); // funcion donde mandar la pipe, crear los forks y ver si se ejecutan

	//ft_validpaths(&pipex, argv[2]); // meter esta llamada a funcion en el fork 1
	//ft_validpaths(&pipex, argv[4]); // meter esta llamada a funcion en el fork 2
	ft_freepointers(pipex.paths);
	return (0);
}
