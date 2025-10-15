/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-05 15:35:27 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-05 15:35:27 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

long	ft_atolints(const char *nptr)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr ++;
	if (*nptr == 45)
	{
		sign = -1;
		nptr ++;
	}
	else if (*nptr == 43)
		nptr ++;
	while ((*nptr) && ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr++ - '0');
		if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
			return (result);
	}
	result *= sign;
	return (result);
}
