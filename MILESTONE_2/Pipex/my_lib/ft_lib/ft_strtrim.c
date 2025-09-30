/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:58:50 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/07 15:11:04 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		a;
	int		z;
	int		len;

	if (!s1 || !set)
		return (NULL);
	a = 0;
	while (s1[a] && ft_strchr(set, s1[a]))
		a++;
	z = ft_strlen(s1) - 1;
	while (z > a && ft_strchr(set, s1[z]))
		z--;
	len = z - a + 1;
	str = ft_substr(s1, a, len);
	if (!str)
		return (NULL);
	return (str);
}

/*	while (s1 && *s1 != *coinc)
		*str++ = *s1++;
		coinc++;
	return (str)	
}*/
