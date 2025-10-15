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

#include "../includes/ft_utils.h"

char	*ft_strjoindelimit(char const *s1, char *delimit, char const *s2)
{
	char	*temp;
	char	*strdest;

	temp = ft_strjoin(s1, delimit);
	strdest = ft_strjoin(temp, s2);
	free(temp);
	return (strdest);
}
