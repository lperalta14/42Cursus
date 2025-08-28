/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:44:40 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/15 19:35:20 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == 45)
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == 43)
		nptr++;
	while ((*nptr) && ft_isdigit(*nptr))
	{
		result = result * 10;
		result = result + (*nptr - '0');
		nptr++;
	}
	result = result * sign;
	return (result);
}

/*int main(int argc, char **argv)
{
	if (argc != 2)
		printf("error");
	else
		printf("%d\n", ft_atoi(argv[1]));
		printf("%d\n", atoi(argv[1]));
	return(0);
}*/
