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

#include "../libft.h"

static int	counterquote(char const *s, char d)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (s[i])
	{
		if (s[i] == d)
			quote++;
		i++;
	}
	return (quote);
}

char	**ft_splitq(char const *s, char c, char d)
{
	int	quote;

	quote = counterquote(s, d);
	if (quote > 0 && quote % 2 == 0)
		return (ft_split(s, d));
	else
		return (ft_split(s, c));
}