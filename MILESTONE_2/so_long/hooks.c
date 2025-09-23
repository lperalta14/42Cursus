/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-22 16:42:12 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-22 16:42:12 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_long	*game;

	game = (t_long *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_move_player(game, 0, -1);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_move_player(game, 0, 1);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_move_player(game, -1, 0);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			ft_move_player(game, 1, 0);
	}
}
void	ft_close_hook(void *param)
{
	t_long	*game;

	game = (t_long *)param;
	//ft_freemem(game);
	mlx_close_window(game->mlx);
}

/*void	ft_loop_hook(void *param)
{
	t_long *game = (t_long *)param;

	// ejemplo: actualizar contador de pasos en pantalla
	// ft_update_score(game);
}*/

void	ft_init_hooks(t_long *game)
{
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	//mlx_loop_hook(game->mlx, &ft_loop_hook, game);
	mlx_close_hook(game->mlx, &ft_close_hook, game);
}