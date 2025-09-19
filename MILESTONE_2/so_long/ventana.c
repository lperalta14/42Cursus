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