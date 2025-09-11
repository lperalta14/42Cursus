/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacechar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 09:33:19 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-11 09:33:19 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_replacechar(char *s, char a, char b)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			s[i] = b;
		i ++;
	}
	return(s);
}