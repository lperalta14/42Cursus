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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

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

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/**
 * @brief Converts a string to a long integer.
 *
 * This function parses the string `nptr` and converts it to a `long` integer.
 * It handles optional leading whitespaces, an optional '+' or '-' sign, 
 * and stops conversion if a non-digit character is found.
 * 
 * @param nptr A pointer to the null-terminated string to convert.
 * @return The converted `long` value on success.
 *         Returns -1 if the string contains a non-digit character.
 *         Returns the value if it overflows beyond `INT_MIN` or `INT_MAX`.
 */
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
	while ((*nptr))
	{
		if (!ft_isdigit(*nptr))
			return (-1);
		result *= 10;
		result += (*nptr++ - '0');
		if ((result * sign) < INT_MIN || (result * sign) > INT_MAX)
			return (result);
	}
	result *= sign;
	return (result);
}
