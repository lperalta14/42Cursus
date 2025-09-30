/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:26:13 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/15 10:45:26 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (!s[1] || s[1] == c))
			words ++;
		s++;
	}
	return (words);
}

static char	**mok(int words)
{
	char	**split;

	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split[words] = NULL;
	return (split);
}

static char	**freemem(char **split, int x)
{
	while (x --)
		free(split[x]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		wcnt;
	int		ccnt;
	char	**split;

	split = mok(ft_wordcount(s, c));
	if (!split)
		return (NULL);
	wcnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			ccnt = 0;
			while (s[ccnt] && s[ccnt] != c)
				ccnt ++;
			split[wcnt] = ft_substr(s, 0, ccnt);
			if (!split[wcnt])
				return (freemem(split, wcnt));
			s += ccnt;
			wcnt ++;
		}
		else
			s ++;
	}
	return (split);
}

/*int	main(void)
{
	char	*str = "Hello!";
	char	**final = ft_split(str, ' ');
	int		i = 0;
	if (!final)
		return (NULL);
	while (final[i])
	{
		printf("%s\n", final[i]);
		free(final[i]);
		i++;
	}
	printf("%s\n", final[i]);
	return	(0);
}*/
