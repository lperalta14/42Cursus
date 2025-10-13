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

#include "../includes/pipex.h"

static void	ft_child2(t_pipex *pipex, char **argv)
{
	if (dup2(pipex->fdpipe[0], STDIN_FILENO) == -1)
		ft_errors(pipex, "Dup2 pipe read");
	if (dup2(pipex->fdoutfile, STDOUT_FILENO) == -1)
		ft_errors(pipex, "Dup2 outfile");
	ft_closesfd(pipex);
	ft_validpaths(pipex, argv[3]);
}

static void	ft_child1(t_pipex *pipex, char **argv)
{
	if (pipex->fdinfile < 0)
		exit(1);
	if (dup2(pipex->fdinfile, STDIN_FILENO) == -1)
		ft_errors(pipex, "Dup2 infile");
	if (dup2(pipex->fdpipe[1], STDOUT_FILENO) == -1)
		ft_errors(pipex, "Dup2 pipe write");
	ft_closesfd(pipex);
	ft_validpaths(pipex, argv[2]);
}

void	ft_pipex(t_pipex *pipex, char **argv)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

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
	ft_closesfd(pipex);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		exit(WEXITSTATUS(status2));
	else
		exit(1);
}
