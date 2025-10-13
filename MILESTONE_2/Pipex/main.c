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

static void	ft_init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	pipex->fdinfile = -1;
	pipex->fdoutfile = -1;
	pipex->fdpipe[0] = -1;
	pipex->fdpipe[1] = -1;
	pipex->envp = envp;
	pipex->path = NULL;
	pipex->paths = NULL;
	pipex->fdinfile = open(argv[1], O_RDONLY);
	if (pipex->fdinfile < 0)
		perror("Invalid infile");
	pipex->fdoutfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pipex->fdoutfile < 0)
		ft_errors(pipex, "Invalid outfile");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		ft_errors(NULL, "Usage: ./pipex [file1] [command1] [command2] [file2]");
	ft_init_pipex(&pipex, argv, envp);
	if (pipe(pipex.fdpipe) == -1)
		ft_errors(&pipex, "Pipe error");
	ft_pipex(&pipex, argv);
	ft_freepointers(pipex.paths);
	return (0);
}
