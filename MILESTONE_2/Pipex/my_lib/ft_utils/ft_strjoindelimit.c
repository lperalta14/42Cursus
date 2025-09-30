/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindelimit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-30 16:11:04 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-30 16:11:04 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoindelimit(char const *s1, char delimit, char const *s2)
{
	size_t	len;
	char	*strdest;

	len = (ft_strlen(s1) + ft_strlen(s2) + 2);
	strdest = (char *) malloc (len * sizeof (char));
	if (!strdest)
		return (NULL);
	ft_strlcpy(strdest, s1, ft_strlen(s1) + 1);
	ft_strlcat(strdest, &delimit, ft_strlen(s2) + 2);
	ft_strlcat(strdest, s2, len);
	return (strdest);
}