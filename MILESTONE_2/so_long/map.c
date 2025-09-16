/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-16 11:29:28 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-16 11:29:28 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_readmapsone(t_long *game, int fd)
{
	char	buffer;
	int		bytes_read;

	bytes_read = 1;
	game->map_lines = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, &buffer, 1);
		if (bytes_read < 0)
			ft_errors(NULL, "invalid maps. read error", 0);
		ft_validchars(buffer, game);
	}
}
static void	ft_get_pos2(t_long *game, int x, int y, char c)
{
	if (c == 'P')
	{
		if (game->pcount == 1)
			ft_errors(game, "YOU CAN'T HANDLE ONE, WHY MORE?\n", 1);
		else
		{
			game->pcount ++;
			game->pos_p.x = x;
			game->pos_p.y = y;
		}
	}
	else if (c == 'E')
	{
		if (game->ecount >= 1)
			ft_errors(game, "ONLY ONE EXIT, DUMMY\n", 1);
		else
		{
			game->ecount ++;
			game->pos_e.x = x;
			game->pos_e.y = y;
		}
	}
}

void	ft_get_pos1(t_long *game, int x, int y, char c)
{
	if (c == 'P' || c == 'E')
	{
		ft_get_pos2(game, x, y, c);
	}
	else
	{
		{
			game->col[game->cindex].x = x;
			game->col[game->cindex].y = y;
			game->cindex ++;
		}
	}
}

void	ft_mapscreate(t_long *game, int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	game->line_size = ft_strlen(line) - 1;
	while(line && y < game->map_lines)
	{
		ft_replacechar(line, '\n', '\0');
		game->map[y] = line;
		line = get_next_line(fd);
		y++;
	}
	while (--y >= 0)
		ft_validmaps(game, y);
	if (game->ccount == 0 || game->ecount < 1 || game->pcount < 1)
		ft_errors(game, "DON'T WANNA PLAY WITH ME?\n", 1);
}