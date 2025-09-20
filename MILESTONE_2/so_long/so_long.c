/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-08 18:58:03 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-08 18:58:03 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
/*
	incializar ventana
	cargar texturas
	pintar mapa suelo y muros ft_base_map(game)
	pintar mapa dinamico ft_dinamic_map(game)
	hooks
	loop principal
	{
		mover jugador, comprobar colisiones.
		animaciones, actualizar score.
	}
*/
static void	so_long(t_long *game)
{
	ft_init_win(game);
	ft_texture_init(game);
	//mlx_image_t *
	//render
	//hooks(mlx_key_hook , mlx_loop_hook)
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

static void	ft_readmaps(t_long *game, int fd, char *file)
{
	ft_check_extension(file);
	ft_readmapsone(game, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->map_lines + 1));
	if (!game->map)
		ft_errors(game,"NO MEMORY, DUMMY", 0);
	game->map[game->map_lines] = NULL;
	game->col = malloc((sizeof(t_point) * game->ccount));
	if(!game->col)
		ft_errors(game,"NO MEMORY, DUMMY", 0);
	ft_mapscreate(game, fd);
	ft_check_walls(game);
	ft_check_path(game);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_long	game;

	if (argc != 2)
		ft_errors(NULL, "ARE YOU IDIOT? ONLY 2 ARGUMENTS\n", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_errors(NULL, "CAN'T OPEN THIS SHIT!", 0);
	ft_bzero(&game, (sizeof (t_long) * 1));
	ft_readmaps(&game, fd, argv[1]);
	printf("lines: %d\nline_size: %d\n Collectables: %d\n", game.map_lines, game.line_size, game.ccount);
	ft_freemem(&game);
	return(0);
}
