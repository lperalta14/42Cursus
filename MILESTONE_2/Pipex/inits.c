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

void	ft_init_pipex(t_pipex *pipex, char **envp)
{
	pipex->fddad[1] = -1;
	pipex->fddad[0] = -1;
	pipex->fdchild1[0] = -1;
	pipex->fdchild2[0] = -1;
	pipex->envp = envp;
	pipex->path = NULL;
	pipex->paths = NULL;
}