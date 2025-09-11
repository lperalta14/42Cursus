/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:10:48 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/23 20:20:45 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_replacechar(char *s, char a, char b)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == a)
			s[i] = b;
		i ++;
	}
	return(s);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		write(1, "\n", 1);
	else
		printf("%s\n", ft_search(argv[1], argv[2][0], argv[3][0]));
	return (0);
	
}
/*void	ft_replace_char(char *s, char oldc, char newc)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (s[i] == oldc)
			s[i] = newc;
		i++;
	}
}*/

