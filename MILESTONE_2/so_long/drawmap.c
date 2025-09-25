/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ventana.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-16 18:06:33 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-16 18:06:33 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

static void	ft_render_base(t_long *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_lines)
	{
		x = 0;
		while (x < game->line_size)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->images.wall,
					(x * 64), (y * 64));
			else
				mlx_image_to_window(game->mlx, game->images.floor,
					(x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

static void	ft_drawplayc(t_long *game, int *c, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		mlx_image_to_window(game->mlx, game->images.player,
			(x * 64), (y * 64));
		game->pos_p.x = x;
		game->pos_p.y = y;
	}
	else if (game->map[y][x] == 'C')
	{
		game->collec[*c].inst_id = mlx_image_to_window(game->mlx,
				game->images.col, (x * 64), (y * 64));
		game->collec[*c].x = x;
		game->collec[*c].y = y;
		*c = *c - 1;
	}
}

static void	ft_render_dynamic(t_long *game)
{
	int	y;
	int	x;
	int	c;

	c = (game->ccount - 1);
	y = 0;
	while (y < game->map_lines)
	{
		x = 0;
		while (x < game->line_size)
		{
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->images.exit,
					(x * 64), (y * 64));
				game->images.exit->enabled = 0;
			}
			else if (game->map[y][x] == 'P' || game->map[y][x] == 'C')
			{
				ft_drawplayc(game, &c, x, y);
			}
			x++;
		}
		y++;
	}
}

void	ft_drawmap(t_long *game)
{
	game->collec = ft_calloc(game->ccount, sizeof(t_collec));
	if (!game->collec)
		ft_errors(game, "HAVE MEMORY OF MY GRANDMA", 0);
	ft_texture_init(game);
	ft_images_init(game);
	ft_render_base(game);
	ft_render_dynamic(game);
}
