/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:02:58 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/06 16:31:19 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	ft_substitute(unsigned int i, char *s)
{
	*s = i + '0';
}

int	main(void)
{
	char	str[] = "hola0cara0cola";
	ft_striteri(str, ft_substitute);
	printf("%s\n", str);
	return (0);	
}*/
