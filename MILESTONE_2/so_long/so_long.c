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
