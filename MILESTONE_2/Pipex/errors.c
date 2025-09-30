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
	if (pipex->fdchild2[1] != -1)
		close(pipex->fdchild2[1]);
	if (pipex->fdchild2[0] != -1)
		close(pipex->fdchild2[0]);
	if (pipex->fdchild1[1] != -1)
		close(pipex->fdchild2[1]);
	if (pipex->fdchild1[0] != -1)
		close(pipex->fdchild2[0]);
	if (pipex->fddad[1] != -1)
		close(pipex->fddad[1]);
	if (pipex->fddad[0] != -1)
		close(pipex->fddad[0]);
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