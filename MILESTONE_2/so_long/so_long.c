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
#include "my_lib/libft.h"
int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	t_long	game; // quitar * y no reservar memoria

	if (argc != 2)
		ft_errors(NULL, "too many arguments.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_errors(&game, "open function failed.");
	ft_bzero(&game, (sizeof (t_long) * 1));
	ft_readmaps(&game, fd, argv[1]);
	printf("lines: %d\nline_size: %d\n Collectables: %d\n", game.map_lines, game.line_size, game.ccount);
	//line = get_next_line(fd);
}
