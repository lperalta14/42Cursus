/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:25:38 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/05 11:00:32 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*strdest;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	strdest = (char *) malloc (len * sizeof (char));
	if (!strdest)
		return (NULL);
	ft_strlcpy(strdest, s1, len);
	ft_strlcat(strdest, s2, len);
	return (strdest);
}
