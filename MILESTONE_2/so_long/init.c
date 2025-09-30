/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 11:07:41 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-25 11:07:41 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_texture_init(t_long *game)
{
	game->text.wall = mlx_load_png("./poops/walls.png");
	if (!game->text.wall)
		ft_errors(game, "WALL TEXTURE IS A MESS", 1);
	game->text.floor = mlx_load_png("./poops/floor.png");
	if (!game->text.floor)
		ft_errors(game, "FLOOR TEXTURE IS A MESS", 1);
	game->text.col = mlx_load_png("./poops/collec.png");
	if (!game->text.col)
		ft_errors(game, "COLLECT TEXTURE IS A MESS", 1);
	game->text.exit = mlx_load_png("./poops/exit.png");
	if (!game->text.exit)
		ft_errors(game, "EXIT TEXTURE IS A MESS", 1);
	game->text.player = mlx_load_png("./poops/player.png");
	if (!game->text.player)
		ft_errors(game, "PLAYER TEXTURE IS A MESS", 1);
}

void	ft_images_init(t_long *game)
{
	game->images.wall = mlx_texture_to_image(game->mlx, game->text.wall);
	if (!game->images.wall)
		ft_errors(game, "WALL IMAGE IS A MESS", 1);
	mlx_resize_image(game->images.wall, 64, 64);
	game->images.floor = mlx_texture_to_image(game->mlx, game->text.floor);
	if (!game->images.floor)
		ft_errors(game, "FLOOR IMAGE IS A MESS", 1);
	game->images.exit = mlx_texture_to_image(game->mlx, game->text.exit);
	if (!game->images.exit)
		ft_errors(game, "EXIT IMAGE IS A MESS", 1);
	game->images.player = mlx_texture_to_image(game->mlx, game->text.player);
	if (!game->images.player)
		ft_errors(game, "PLAYER IMAGE IS A MESS", 1);
	mlx_resize_image(game->images.player, 64, 64);
	game->images.col = mlx_texture_to_image(game->mlx, game->text.col);
	if (!game->images.col)
		ft_errors(game, "COLLECT IMAGE IS A MESS", 1);
}

void	ft_init_win(t_long *game)
{
	int	size_x;
	int	size_y;

	game->mlx = mlx_init((game->line_size * 64), (game->map_lines * 64),
			"RUN4YOURLIFE", true);
	if (!game->mlx)
		ft_errors(game, "WINDOWS TO JUMP", 1);
	mlx_get_monitor_size(0, &size_x, &size_y);
	if (size_x <= (game->line_size * 64) || size_y <= (game->map_lines * 64))
		ft_errors(game, "TOO BIG, TOO HARD", 1);
}
