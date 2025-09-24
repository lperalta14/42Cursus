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

void	ft_init_win(t_long *game)
{
	int	size_x;
	int	size_y;

	game->mlx = mlx_init((game->line_size * 64), (game->map_lines * 64), 
				"RUN4YOURELIFE", true);
	if (!game->mlx)
		ft_errors(game, "WINDOWS TO JUMP", 1);
	mlx_get_monitor_size(0, &size_x, &size_y);
	if(size_x <= (game->line_size * 64) || size_y <= (game->map_lines * 64))
		ft_errors(game, "TOO BIG, TOO HARD", 1);
}

static void	ft_texture_init(t_long *game)
{
	game->textures.wall = mlx_load_png("/home/lperalta/42-Cursus/MILESTONE_2/so_long/textures/wallsA.png");
	if (!game->textures.wall)
		ft_errors(game, "WALL TEXTURE IS A MESS", 1);
	game->textures.floor = mlx_load_png("/home/lperalta/42-Cursus/MILESTONE_2/so_long/textures/floor.png");
	if (!game->textures.floor)
		ft_errors(game, "FLOOR TEXTURE IS A MESS", 1);
	game->textures.col = mlx_load_png("/home/lperalta/42-Cursus/MILESTONE_2/so_long/textures/collec.png");
	if (!game->textures.col)
		ft_errors(game, "COLLECT TEXTURE IS A MESS", 1);
	game->textures.exit = mlx_load_png("/home/lperalta/42-Cursus/MILESTONE_2/so_long/textures/exitB.png");
	if (!game->textures.exit)
		ft_errors(game, "EXIT TEXTURE IS A MESS", 1);
	game->textures.player = mlx_load_png("/home/lperalta/42-Cursus/MILESTONE_2/so_long/textures/player.png");
	if (!game->textures.player)
		ft_errors(game, "PLAYER TEXTURE IS A MESS", 1);
}

static void	ft_images_init(t_long *game)
{
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	if(!game->images.wall)
		ft_errors(game, "WALL IMAGE IS A MESS", 1);
	mlx_resize_image(game->images.wall, 64, 64);
	game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	if(!game->images.floor)
		ft_errors(game, "FLOOR IMAGE IS A MESS", 1);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
	if(!game->images.exit)
		ft_errors(game, "EXIT IMAGE IS A MESS", 1);
	game->images.player = mlx_texture_to_image(game->mlx, game->textures.player);
	if(!game->images.player)
		ft_errors(game, "PLAYER IMAGE IS A MESS", 1);
	mlx_resize_image(game->images.player, 64, 64);
	game->images.col = mlx_texture_to_image(game->mlx, game->textures.col);
	if(!game->images.col)
		ft_errors(game, "COLLECT IMAGE IS A MESS", 1);
}

static void	ft_render_base(t_long *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_lines)
	{
		x = 0;
		while(x < game->line_size)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->images.wall, (x * 64), (y * 64));
			else
				mlx_image_to_window(game->mlx, game->images.floor, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

static void	ft_drawplayc(t_long *game, int *c, int x , int y)
{
	if (game->map[y][x] == 'P')
	{
		mlx_image_to_window(game->mlx, game->images.player, (x * 64), (y * 64));
		game->pos_p.x = x;
		game->pos_p.y = y;
	}
	else if (game->map[y][x] == 'C')
	{
		game->collec[*c].instance_id = mlx_image_to_window(game->mlx, game->images.col, 
									(x * 64), (y * 64));
		game->collec[*c].x = x;
		game->collec[*c].y = y;
		*c = *c-1;
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
		while(x < game->line_size)
		{
			if (game->map[y][x] == 'P' || game->map[y][x] =='C')
			{
				ft_drawplayc(game, &c, x , y);
			}
			/*if (game->map[y][x] == 'P')
			{
				mlx_image_to_window(game->mlx, game->images.player, (x * 64), (y * 64));
				game->pos_p.x = x;
				game->pos_p.y = y;
			}
			else if (game->map[y][x] == 'C')
			{
				game->collec->instance_id = mlx_image_to_window(game->mlx, game->images.collectible, (x * 64), (y * 64));
				game->collec->x = x;
				game->collec->y = y;			
			}*/
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->images.exit, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

void	ft_drawmap(t_long *game)
{
	game->collec = ft_calloc(game->ccount, sizeof(t_collec));
	ft_texture_init(game);
	ft_images_init(game);
	ft_render_base(game);
	ft_render_dynamic(game);
}
