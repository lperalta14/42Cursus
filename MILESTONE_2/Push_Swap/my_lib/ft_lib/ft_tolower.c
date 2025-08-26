/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:09:26 by lperalta          #+#    #+#             */
/*   Updated: 2025/04/27 19:16:47 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
	printf("ERROR");
	else
	printf("%c\n", tolower(argv[1][0]));
	return (0);
}*/
