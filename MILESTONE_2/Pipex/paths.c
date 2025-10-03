/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-30 11:32:56 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-30 11:32:56 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

char	*ft_get_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while(pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], "PATH=", 5) == 0)
			return(pipex->envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**ft_get_paths(t_pipex *pipex)
{
	pipex->path = ft_get_path(pipex);
	pipex->paths = ft_split(pipex->path, ':');
	return(pipex->paths);
}

void	ft_validpaths(t_pipex *pipex, char *command)
{
	int		i;
	char	*binpath;
	char	**params;

	i = 0;
	params = ft_splitq(command, ' ', 0);
	ft_get_paths(pipex);
	while (pipex->paths[i])
	{
		binpath = ft_strjoindelimit(pipex->paths[i], "/", params[0]);
		if (access(binpath, X_OK) == 0)
			execve(binpath, params, pipex->envp);
		free(binpath);
		i++;
	}
	ft_freepointers(params);
}