/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-01 13:33:40 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-01 13:33:40 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

static int	ft_wordcount(char const *s, char c)
{
	int	words;
	int	quote;

	quote = 0;
	words = 0;
	while (*s)
	{
		if (quote && *s == '\'')
			quote = 0;
		else if (!quote && *s == '\'')
			quote = 1;
		if (*s != c && ((!s[1] || s[1] == c) && !quote))
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

static int	countquote(int *quote, int ccnt, char const *s)
{
	if (!*quote && s[ccnt] == '\'')
		*quote = s[ccnt];
	else if (*quote && (s[ccnt] == '\''))
		*quote = 0;
	ccnt ++;
	return (ccnt);
}

char	**ft_splitq(char const *s, char c, int wcnt)
{
	int		ccnt;
	char	**split;
	int		quote;

	split = mok(ft_wordcount(s, c));
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			ccnt = 0;
			quote = 0;
			while (s[ccnt] && (quote || s[ccnt] != c))
				ccnt = countquote(&quote, ccnt, s);
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
