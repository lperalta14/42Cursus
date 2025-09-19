/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 15:54:52 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-09 15:54:52 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_validchars(char buffer, t_long *game)
{
	if (buffer != '1' && buffer != '0' && buffer != '\n' &&
		buffer != 'P' && buffer != 'E' && buffer != 'C')
		ft_errors(NULL, "invalid maps. char invalid\n", 1);
	if (buffer == '\n')
		game->map_lines ++;
	else if (buffer == 'C')
		game->ccount ++;
}

void	ft_validmaps(t_long *game, int y)
{
	int	x;

	x = 0;
	while(game->map[y][x])
	{
		if (game->map[y][x] == 'P')
			ft_get_pos1(game, x, y, 'P');
		if (game->map[y][x] == 'E')
			ft_get_pos1(game, x, y, 'E');
		if (game->map[y][x] == 'C')
			ft_get_pos1(game, x, y, 'C');
		x ++;
	}
	if (game->line_size != (int)ft_strlen(game->map[y]))
		ft_errors(game, "YUO DON'T KNOW HOW TO MAKE A RECTANGLE?\n", 1);
}

void	ft_check_extension(char *file)
{
	char	*ber;

	ber = ft_strrchr(file, '.');
	if (ft_strlen(ber) != 4 || ft_strncmp(ber, ".ber", 4))
		ft_errors(NULL, "WRONG EXTENSION, IDIOT\n", 1);
}

void	ft_check_walls(t_long *game)
{
	int		y;
	int		x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == 0 && (game->map[y][x] != '1'))
				ft_errors(game, "MAP IS OPEN, USELESS\n", 1);
			else if (y == game->map_lines - 1 && (game->map[y][x] != '1'))
				ft_errors(game, "MAP IS OPEN, USELESS\n", 1);
			if ((x == 0 || x == game->line_size-1) && (game->map[y][x] != '1'))
				ft_errors(game,"MAP IS OPEN, USELESS\n", 1);
			x ++;
		}
		y ++;
	}
}
