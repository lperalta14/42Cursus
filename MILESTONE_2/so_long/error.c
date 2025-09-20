/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 12:18:04 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-09 12:18:04 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_freemap(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while(map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	ft_free_textures(t_textures *textures)
{
	if (textures->wall)
		mlx_delete_texture(textures->wall);
	if (textures->floor)
		mlx_delete_texture(textures->floor);
	if (textures->player)
		mlx_delete_texture(textures->player);
	if (textures->exit)
		mlx_delete_texture(textures->exit);
	if (textures->collectible)
		mlx_delete_texture(textures->collectible);
}

void	ft_free_images(t_long *game)
{
	if (game->images->wall)
		mlx_delete_image(game->mlx , game->images->wall);
	if (game->images->floor)
		mlx_delete_image(game->mlx , game->images->floor);
	if (game->images->player)
		mlx_delete_image(game->mlx , game->images->player);
	if (game->images->exit)
		mlx_delete_image(game->mlx , game->images->exit);
	if (game->images->collectible)
		mlx_delete_image(game->mlx , game->images->collectible);
}

void	ft_errors(t_long *game, char *msg, int mod)
{
	if (game && game->map)
		ft_freemap(game->map);
	//if (game && game->col)
	//	free(game->col);
	if (game && game->textures)
		ft_free_textures(game->textures);
	if (game && game->images)
		ft_free_images(game);
	if(mod)
		ft_putstr_fd(msg, 2);
	else
		perror(msg);
	exit(1);
}

void	ft_freemem(t_long *game)
{
	if (game && game->map)
		ft_freemap(game->map);
	//if (game && (game->col))
	//	free(game->col);
	if (game && game->textures)
		ft_free_textures(game->textures);
	if (game && game->images)
		ft_free_images(game);
}
