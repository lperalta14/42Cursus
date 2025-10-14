/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:44:07 by lperalta          #+#    #+#             */
/*   Updated: 2025/04/22 17:44:12 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

/**
 * @brief Establece a cero un bloque de memoria.
 *
 * La función escribe '\0' (cero) en los primeros `n` bytes del área de
 * memoria apuntada por `s`. Es equivalente a usar `memset` con valor cero
 * y se utiliza para inicializar estructuras o buffers a cero.
 *
 * @param s Puntero al área de memoria que se desea poner a cero.
 * @param n Número de bytes que se establecerán a cero.
 *
 * @return No devuelve ningún valor.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
