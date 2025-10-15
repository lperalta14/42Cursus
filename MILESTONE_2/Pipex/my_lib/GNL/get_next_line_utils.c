/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:16:05 by lperalta          #+#    #+#             */
/*   Updated: 2025/06/23 12:41:41 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GNL.h"

char	*ft_strchr_gnl(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len;
	char	*dest;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup_gnl(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *) malloc ((len +1) * sizeof (char));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[len] = 0;
	free(s1);
	return (dest);
}

char	*ft_substr_gnl(char *s, int len)
{
	char	*dest;

	dest = malloc (len + 1 * (sizeof (char)));
	if (!dest)
		return (NULL);
	dest[len] = 0;
	while (len && s[len - 1])
	{
		len --;
		dest[len] = s[len];
	}
	return (dest);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s);
	str = (char *) malloc (len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len--)
		str[len] = s[len];
	return (str);
}
