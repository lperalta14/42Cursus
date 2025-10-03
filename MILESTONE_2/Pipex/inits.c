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
	pipex->fdinfile = open(argv[1], O_RDONLY);
	if (pipex->fdinfile < 0)
	pipex->fdoutfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fdoutfile < 0)
		ft_errors(pipex, "Outfile failed");
	pipex->fdpipe[0] = -1;
	pipex->envp = envp;
	pipex->path = NULL;
	pipex->paths = NULL;
}