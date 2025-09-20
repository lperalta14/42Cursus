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
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int y;
}t_point;

typedef struct s_textures
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
	mlx_texture_t	*collectible;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
}	t_images;

typedef struct s_long
{
	void	*mlx;
	char	**map;
	int		line_size;
	int		map_lines;
	int		ccount;
	int		cindex;
	int		pcount;
	int		ecount;
	t_textures	*textures;
	t_images	*images;
	t_point	pos_p;
	t_point	pos_e;
	t_point *col;
} t_long ;

/*typedef struct mlx_key_data
{
	keys_t		key;
	action_t	action;
	int32_t		os_key;
	modifier_key_t	modifier;
}	mlx_key_data_t;*/

// Parseo
void	ft_check_extension(char *file);
void	ft_validchars(char buffer, t_long *game);
void	ft_validmaps(t_long *game, int y);
void	ft_check_walls(t_long *game);

// Map
void	ft_readmapsone(t_long *game, int fd);
void	ft_get_pos1(t_long *game, int x, int y, char c);
void	ft_mapscreate(t_long *game, int fd);
void	ft_check_path(t_long *game);

// Win
void	ft_init_win(t_long *game);
void	ft_texture_init(t_long *game);
void	ft_images_init(t_long *game);

// Errors
void	ft_errors(t_long *map, char *msg, int mod);

// Free
void	ft_freemem(t_long *game);
void	ft_freemap(char **map);
void	ft_free_textures(t_textures *textures);
void	ft_free_images(t_long *game);

#endif