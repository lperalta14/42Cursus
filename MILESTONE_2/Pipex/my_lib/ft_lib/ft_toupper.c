/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:54:35 by lperalta          #+#    #+#             */
/*   Updated: 2025/04/22 12:54:38 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		printf("ERROR");
	else
		printf("%c\n", toupper(argv[1][0]));
	return (0);
}*/
