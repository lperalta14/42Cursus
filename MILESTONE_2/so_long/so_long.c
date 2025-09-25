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

static void	ft_so_long(t_long *game)
{
	ft_init_win(game);
	ft_drawmap(game);
	ft_init_hooks(game);
	mlx_loop(game->mlx);
	ft_freemem(game);
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
		ft_errors(game, "NO MEMORY, DUMMY", 0);
	game->map[game->map_lines] = NULL;
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
	ft_so_long(&game);
	return (0);
}
