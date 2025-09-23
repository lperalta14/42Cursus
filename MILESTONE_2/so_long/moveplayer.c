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

void	ft_move_player(t_long *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->ccount--;
		
	}
}
