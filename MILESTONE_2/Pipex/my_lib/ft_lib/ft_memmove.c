/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:22:27 by lperalta          #+#    #+#             */
/*   Updated: 2025/04/23 11:22:34 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *) src;
	d = (char *) dest;
	if (src < dest)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*int main()
{
	char dest[15];
	char src[] = "hola paco";
	
	printf("%s\n", memmove(&dest[0], src, 4));(src + 2, src, 4));
	printf("%s\n", ft_memmove(&dest[0], src, 4));(src + 2, src, 4));
}*/
