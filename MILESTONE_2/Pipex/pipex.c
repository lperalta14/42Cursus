/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 15:37:47 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-26 15:37:47 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"
//primero abro pipe
//forks
//dup de los fd de pipes

static void ft_child2(t_pipex *pipex, char **argv)
{
	if (dup2(pipex->fdpipe[0], STDIN_FILENO) == -1)
		ft_errors(pipex, "Dup2 pipe read");
	if (dup2(pipex->fdoutfile, STDOUT_FILENO) == -1)
		ft_errors(pipex, "Dup2 outfile");

	close(pipex->fdpipe[1]); // este hijo no escribe al pipe
	close(pipex->fdpipe[0]);

	ft_validpaths(pipex, argv[3]);
}

static void ft_child1(t_pipex *pipex, char **argv)
{
	if (dup2(pipex->fdinfile, STDIN_FILENO) == -1)
		ft_errors(pipex, "Dup2 infile");
	if (dup2(pipex->fdpipe[1], STDOUT_FILENO) == -1)
		ft_errors(pipex, "Dup2 pipe write");

	close(pipex->fdpipe[0]);
	close(pipex->fdpipe[1]);

	ft_validpaths(pipex, argv[2]);
}

void	ft_pipex(t_pipex *pipex, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		ft_errors(pipex, "Fork error");
	if (pid1 == 0)
		ft_child1(pipex, argv);

	pid2 = fork();
	if (pid2 == -1)
		ft_errors(pipex, "Fork error");
	if (pid2 == 0)
		ft_child2(pipex, argv);

	close(pipex->fdpipe[0]);
	close(pipex->fdpipe[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
