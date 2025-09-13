/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 12:18:04 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-09 12:18:04 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	ft_freestruct(t_long *game)
{
	free(game);
}
static void	ft_freemap(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
static void	ft_free_point(t_point *wall, t_point *col)
{
	if (wall)
		free(wall);
	if (col)
		free(col);
}

void	ft_errors(t_long *game, char *msg, int mod)
{
	if (game && game->map)
		ft_freemap(game->map);
	if (game && (game->wall || game->col))
		ft_free_point(game->wall, game->col);
	if(mod)
		ft_putstr_fd(msg, 2);
	else
		perror(msg);
	exit(1);
}