/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:41:45 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/22 12:39:20 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbrcnt(int n)
{
	int		count;
	char	result;

	count = 0;
	result = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count ++;
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbrcnt(n / 10);
	result = (n % 10) + '0';
	count += ft_putchar(result);
	return (count);
}

int	ft_unsigput(unsigned int n)
{
	char	result;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbrcnt(n / 10);
	result = (n % 10) + '0';
	count += ft_putchar(result);
	return (count);
}

int	ft_puthex(unsigned long n, char x)
{
	int		count;
	char	*set;

	if (x == 'x')
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
		count += ft_puthex(n / 16, x);
	count += ft_putchar(set[n % 16]);
	return (count);
}

int	ft_putptr(unsigned long n)
{
	int		count;

	if (!n)
	{
		ft_putstr("(nil)");
		return (5);
	}
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(n, 'x');
	return (count);
}
