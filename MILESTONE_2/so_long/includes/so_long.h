/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-08 10:59:36 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-08 10:59:36 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../my_lib/libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int y;
}t_point;

typedef struct s_long
{
	void	*mlx;
	char	**map;
	int		line_size;
	int		map_lines;
	int		ccount;
	int		pcount;
	int		ecount;
	t_point	pos_p;
	t_point	pos_e;
	t_point *col;
	t_point	*wall;
} t_long ;

// Parseo
void	ft_readmaps(t_long *map, int fd, char *file);

// Errors
void	ft_errors(t_long *map, char *msg, int mod);
#endif