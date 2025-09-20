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

	game->mlx = mlx_init((game->line_size * 64), (game->map_lines * 64), "RUN4YOURELIFE", true);
	if (!game->mlx)
		ft_errors(game, "WINDOWS TO JUMP", 1);
	mlx_get_monitor_size(0, &size_x, &size_y);
	printf("Monitor: %d x %d\n", size_x, size_y);
	printf("Mapa: %d x %d\n", game->line_size * 64, game->map_lines * 64);
	if(size_x <= (game->line_size * 64) || size_y <= (game->map_lines * 64))
		ft_errors(game, "TOO BIG, TOO HARD", 1);
}
void	ft_texture_init(t_long *game)
{
	game->textures->wall = mlx_load_png("path/imagen.png");
	if (!game->textures->wall)
		ft_errors(game, "WALL TEXTURE IS A MESS", 1);
	game->textures->floor = mlx_load_png("path/imagen.png");
	if (!game->textures->floor)
		ft_errors(game, "FLOOR TEXTURE IS A MESS", 1);
	game->textures->collectible = mlx_load_png("path/imagen.png");
	if (!game->textures->collectible)
		ft_errors(game, "COLLECT TEXTURE IS A MESS", 1);
	game->textures->exit = mlx_load_png("path/imagen.png");
	if (!game->textures->exit)
		ft_errors(game, "EXIT TEXTURE IS A MESS", 1);
	game->textures->player = mlx_load_png("path/imagen.png");
	if (!game->textures->player)
		ft_errors(game, "PLAYER TEXTURE IS A MESS", 1);
}
/*void	ft_delete_texture(t_long *game)
{
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->floor);
	mlx_delete_texture(game->textures->exit);
	mlx_delete_texture(game->textures->player);
	mlx_delete_texture(game->textures->collectible);
}*/

void	ft_images_init(t_long *game)
{
	game->images->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	if(!game->images->wall)
		ft_errors(game, "WALL IMAGE IS A MESS", 1);
	game->images->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
	if(!game->images->floor)
		ft_errors(game, "FLOOR IMAGE IS A MESS", 1);
	game->images->exit = mlx_texture_to_image(game->mlx, game->textures->exit);
	if(!game->images->exit)
		ft_errors(game, "EXIT IMAGE IS A MESS", 1);
	game->images->player = mlx_texture_to_image(game->mlx, game->textures->player);
	if(!game->images->player)
		ft_errors(game, "PLAYER IMAGE IS A MESS", 1);
	game->images->collectible = mlx_texture_to_image(game->mlx, game->textures->collectible);
	if(!game->images->collectible)
		ft_errors(game, "COLLECT IMAGE IS A MESS", 1);
}

/*void	ft_delete_images(t_long *game)
{
	mlx_delete_image(game->mlx , game->images->wall);
	mlx_delete_image(game->mlx , game->images->floor);
	mlx_delete_image(game->mlx , game->images->exit);
	mlx_delete_image(game->mlx , game->images->player);
	mlx_delete_image(game->mlx , game->images->collectible);
}*/
