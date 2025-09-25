/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-15 17:56:27 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-15 17:56:27 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**ft_dup_map(t_long *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map_lines + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map_lines)
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
			ft_errors(game, "FAILED DUPLICATED", 0);
		i++;
	}
	copy[game->map_lines] = NULL;
	return (copy);
}

static void	ft_floodfill(char **map, int y, int x, t_long *game)
{
	if (y < 0 || x < 0 || y >= game->map_lines || x >= game->line_size)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		game->found_c += 1;
	if (map[y][x] == 'E')
		game->found_e += 1;
	map[y][x] = 'V';
	ft_floodfill(map, y + 1, x, game);
	ft_floodfill(map, y - 1, x, game);
	ft_floodfill(map, y, x + 1, game);
	ft_floodfill(map, y, x - 1, game);
}

void	ft_check_path(t_long *game)
{
	char	**map_copy;

	map_copy = ft_dup_map(game);
	if (!map_copy)
		ft_errors(game, "FAILED TO DUP MAP\n", 0);
	game->found_c = 0;
	game->found_e = 0;
	ft_floodfill(map_copy, game->pos_p.y, game->pos_p.x, game);
	ft_freemap(map_copy);
	if (game->found_c != game->ccount)
		ft_errors(game, "NOT ALL COLLECTIBLES ARE REACHABLE! FOOL\n", 1);
	if (game->found_e == 0)
		ft_errors(game, "YOU CAN´T EXIT, TWIT!\n", 1);
}
