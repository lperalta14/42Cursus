/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-26 17:30:14 by lperalta          #+#    #+#             */
/*   Updated: 2025-08-26 17:30:14 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	ft_checkbase(int str_base)
{
	char	base;

	if (str_base < 2 || str_base > 16)
		return (0);
	if (str_base < 11)
		base = (str_base - 1) + 48;
	else
		base = str_base + 'a' -10;
	return (base);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		res;
	int		sign;
	char	base;

	res = 0;
	sign = 1;
	base = ft_checkbase(str_base);
	while (*str > 0 && *str < 33)
		str++;
	if (*str++ == '-')
		sign = -1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && *str <= base)
			res *= str_base + (*str - 48);
		else if (*str >= 'a' && *str <= 'f' && *str < base)
			res *= str_base + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F' && *str < (base - 32))
			res *= str_base + (*str - 'A' + 10);
		else
			break ;
		str ++;
	}
	res = res * sign;
	return (res);
}
