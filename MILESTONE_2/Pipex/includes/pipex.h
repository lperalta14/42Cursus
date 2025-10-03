/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-26 15:39:20 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-26 15:39:20 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../my_lib/libft.h"
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		fdinfile;
	int		fdoutfile;
	int		fdpipe[2];
	char	**envp;
	char	*path;
	char	**paths;
}	t_pipex ;

void	ft_init_pipex(t_pipex *pipex, char **argv, char **envp);
char	**ft_get_paths(t_pipex *pipex);
void	ft_validpaths(t_pipex *pipex, char *command);
void    ft_pipex(t_pipex *pipex, char **argv);

//Errors
void	ft_freepointers(char **str);
void	ft_closesfd(t_pipex *pipex);
void	ft_errors(t_pipex *pipex, char *context);

#endif
