/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-14 14:43:39 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-14 14:43:39 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	ft_putmatrix(char **str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i], fd);
		write(fd, "\n", 1);
		i++;
	}
}
