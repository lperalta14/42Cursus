/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:44:55 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/07 09:45:57 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;

	if (!*little)
		return ((char *) big);
	while (*big && (0 < len))
	{
		j = 0;
		while (big[j] && little[j] == big[j])
			j ++;
		if (j == ft_strlen(little) && j <= len)
			return ((char *) big);
		big ++;
		len --;
	}
	return (NULL);
}
