/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:19:08 by lperalta          #+#    #+#             */
/*   Updated: 2025/04/28 11:26:49 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (size + srclen);
	if (src[i] == '\0')
		return (dstlen);
	while (dst[i])
		i++;
	while (src[j] && (--size - dstlen))
		dst[i++] = src[j++];
	dst[i] = 0;
	return (dstlen + srclen);
}
/*int main(void)
{
	char dest1[7] = "Hola, ";
	char src1[] = "mundo";
	
	printf("%d\n", strlcat(dest1,src1, 3));
	return (0);
}*/
