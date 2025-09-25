/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-24 10:17:20 by lperalta          #+#    #+#             */
/*   Updated: 2025-09-24 10:17:20 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_isspace(char c)
{
	if(c > 0 && c <= 32)
		return (1);
	return (0);
}
int ft_islower(char c)
{
	if (c > 96 && c < 123)
		return(1);
	return(0);
}
int ft_isupper(char c)
{
	if (c >  64 && c < 91)
		return(1);
	return(0);
}
int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return(1);
}

int ft_isalnum(char c)
{
	return(ft_isupper(c) || ft_islower(c) || ft_isdigit(0));
}

void	ft_clean(char *str, char *srtclean)
{
	int	i = 0;
	int	j = 0;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
		{
			srtclean[j] = str[i];
			j++;
		}
		i++ ;
	}

}
int	ft_countalum(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (str[i])
			count++;
		i++;
	}
	return(count);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}
void	ft_putstr(char *str)
{
	int	i;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**mat;
	int	
	if (argc != 3)
		return (write(2, "Error\n", 6));
	str = malloc(sizeof (char) * (ft_countalnum(argv[1]) + 1));
	ft_clean(argv[1], str);
	mat = malloc(sizeof (char *) * (ft_atoi(argv[2]) + 1));
	while(str)
	{

	}
	return(0);
}