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
		ft_errors(NULL, "invalid maps. char invalid");
	if (buffer == '\n')
		game->map_lines ++;
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
			ft_errors(NULL, "invalid maps. read error");
		ft_validchars(buffer, game);
		//game->maps_size ++;
	}
}
void	ft_posac(t_long *game, int x, int y, char c)
{
	if (c == 'P')
	{
		if (game->pcount >= 1)
			ft_errors(game, "too many characters.");
		else
		{
			game->pcount ++;
			game->pos_p.x = x;
			game->pos_p.y = y;
		}
	}
	else
	{
		if (game->ecount >= 1)
			ft_errors(game, "too many exits.");
		else
		{
			game->ecount ++;
			game->pos_e.x = x;
			game->pos_e.y = y;
		}
	}
}
void	ft_validmaps(char *line, t_long *game, int y)
{
	int	x;

	x = 0;
	while(line[x])
	{
		if (line[x] == 'P')
			ft_posac(game, x, y, 'P');
		if (line[x] == 'E')
			ft_posac(game, x, y, 'E');
		if (line[x] == 'C')
			game->ccount ++;
		x ++;
	}
	printf("%d\n, lineas tamaño  %zu\n, linea actual", game->line_size, ft_strlen(line));
	if (game->line_size != ft_strlen(line))
		ft_errors(game, "invalid map. diferent size of line.");
}

void	ft_readmaps(t_long *game, int fd, char *file)
{
	int		y;
	char	*line;

	ft_readmapsone(game, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	//bytes_read = read(fd, totalmap, game->maps_size);
	y = 0;
	game->map = malloc(sizeof(char *) * (game->map_lines + 1));
	if (!game->map)
		ft_errors(game, "alloc memory map failed.");
	line = get_next_line(fd);
	game->line_size = ft_strlen(line);
	printf("%d\n, lineas tamaño", game->line_size);
	while (line && (y < game->map_lines))
	{
		game->map[y] = line;
		ft_validmaps(line, game, y);
		line = get_next_line(fd);
		y++;
	}
	printf("%d\n, lineas", game->map_lines);
	game->map[game->map_lines] = NULL;
}
