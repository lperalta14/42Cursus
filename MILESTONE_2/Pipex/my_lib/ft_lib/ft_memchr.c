/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:13:13 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/02 13:15:11 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	x;
	unsigned char	*str;

	str = (unsigned char *) s;
	x = (unsigned char) c;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (*str == x)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
