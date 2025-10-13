/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-13 15:28:42 by lperalta          #+#    #+#             */
/*   Updated: 2025-10-13 15:28:42 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

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
