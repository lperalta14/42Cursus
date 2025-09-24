/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 17:45:30 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-22 17:45:30 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int32_t	ft_findid(t_long *game, int x, int y)
{
	int		i;

	i = 0;
	ft_printf("beforewhile , x = %d, y = %d\n", x, y);
	while (i < game->cindex)
	{

		if (game->collec[i].x == x && game->collec[i].y == y 
			&& game->collec[i].iscol == 0)
		{
			game->collec[i].iscol = 1;
			ft_printf("c = %d , x = %d, y = %d\n", i, x, y);
			return (game->collec[i].instance_id);
		}
		i++;
	}
	return(-1);
}

void	ft_move_player(t_long *game, int dx, int dy)
{
	int		new_x; 
	int		new_y;
	int32_t	id;

	new_x = game->pos_p.x + dx;
	new_y = game->pos_p.y + dy;
	id = ft_findid(game, new_x, new_y);
	if (game->map[new_y][new_x] == '1')
		return;
	if (game->map[new_y][new_x] == 'C' && id >= 0)
	{
		game->ccount--;
		mlx_set_instance_depth(&game->images.col->instances[id], -1000);
		game->map[new_y][new_x] = '0';
	}
	game->map[game->pos_p.y][game->pos_p.y] = '0';
	game->map[new_y][new_x] = 'P';
	game->images.player->instances->x = new_x * 64;
	game->images.player->instances->y = new_y * 64;
	game->pos_p.x = new_x;
	game->pos_p.y = new_y;
	game->move++;
}
