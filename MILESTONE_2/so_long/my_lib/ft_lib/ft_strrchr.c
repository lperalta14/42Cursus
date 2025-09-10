/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:40:06 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/02 12:40:08 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	char			*str;
	unsigned char	x;

	x = (unsigned char) c;
	str = (char *) s;
	len = ft_strlen(s);
	str += len;
	while (len >= 0)
	{
		if (*str == x)
			return (str);
		str --;
		len --;
	}
	return (NULL);
}
