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

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
void	ft_errors(t_long *game, char *msg)
{
	ft_freemap(game->map);
	perror(msg);
	exit(2);
}