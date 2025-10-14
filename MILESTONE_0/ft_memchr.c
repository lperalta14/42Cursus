/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:13:13 by lperalta          #+#    #+#             */
/*   Updated: 2025/05/02 13:15:11 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Busca un byte específico dentro de un bloque de memoria.
 *
 * Examina los primeros `n` bytes del área de memoria apuntada por `s`
 * en busca de la primera aparición del valor `c` (interpretado como un
 * unsigned char). Si se encuentra, devuelve un puntero al byte correspondiente.
 *
 * @param s Puntero al bloque de memoria donde realizar la búsqueda.
 * @param c Valor del byte a buscar (se interpreta como unsigned char).
 * @param n Número máximo de bytes a examinar.
 *
 * @return Un puntero al primer byte coincidente si se encuentra,
 *         o `NULL` si el valor no aparece en los primeros `n` bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	x;
	unsigned char	*str;

	str = (unsigned char *) s;
	x = (unsigned char) c;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		if (*str == x)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
