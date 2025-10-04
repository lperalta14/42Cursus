/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-30 11:35:19 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-30 11:35:19 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	ft_init_pipex(t_pipex *pipex, char **argv, char **envp)
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
	{
		perror("Invalid infile:");
		
	}
		//ft_errors(pipex, "Invalid infile");
	pipex->fdoutfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (pipex->fdoutfile < 0)
		ft_errors(pipex, "Invalid outfile");
}
