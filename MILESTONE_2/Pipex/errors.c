/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-30 13:37:52 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-30 13:37:52 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	ft_freepointers(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_closesfd(t_pipex *pipex)
{
	if (pipex->fdinfile && pipex->fdinfile != -1)
		close(pipex->fdinfile);
	if (pipex->fdoutfile && pipex->fdoutfile != -1)
		close(pipex->fdoutfile);
	if (pipex->fdpipe[0] && pipex->fdpipe[0] >= 0)
		close(pipex->fdpipe[0]);
	if (pipex->fdpipe[1] && pipex->fdpipe[1] >= 0)
		close(pipex->fdpipe[1]);
}

void	ft_errors(t_pipex *pipex, char *context)
{
	if (pipex)
	{
		ft_closesfd(pipex);
		ft_freepointers(pipex->paths);
		if (pipex->path)
			free(pipex->path);
	}
	perror(context);
	exit(1);
}