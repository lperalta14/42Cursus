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

#include "includes/so_long.h"
#include "my_lib/libft.h"

static void	ft_validchars(char buffer, t_long *game)
{
	if (buffer != '1' && buffer != '0' && buffer != '\n' &&
		buffer != 'P' && buffer != 'E' && buffer != 'C')
		ft_errors(NULL, "invalid maps. char invalid\n", 1);
	if (buffer == '\n')
		game->map_lines ++;
	else if (buffer == 'C')
		game->ccount ++;
}
static void	ft_readmapsone(t_long *game, int fd)
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
void	ft_get_pos2(t_long *game, int x, int y, char c)
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

void	ft_readmaps(t_long *game, int fd, char *file)
{
	ft_check_extension(file);
	ft_readmapsone(game, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->map_lines + 1));
	if (!game->map)
		ft_errors(game,"NO MEMORY, DUMMY", 0);
	game->map[game->map_lines] = NULL;
	game->col = malloc((sizeof(t_point) * (game->ccount)));
	if(!game->col)
		ft_errors(game,"NO MEMORY, DUMMY", 0);
	ft_mapscreate(game, fd);
	ft_check_walls(game);
}
