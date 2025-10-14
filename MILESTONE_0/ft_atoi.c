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
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Comprueba si un carácter es un espacio en blanco.
 *
 * Determina si el carácter dado corresponde a alguno de los caracteres
 * de espacio en blanco reconocidos por la librería estándar de C:
 * espacio (' '), tabuladores, salto de línea, retorno de carro,
 * avance de página o tabulación vertical.
 *
 * @param c Carácter a evaluar (representado como un entero).
 *
 * @return 1 si el carácter es un espacio en blanco, 0 en caso contrario.
 */
int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

/**
 * @brief Convierte una cadena de caracteres numérica en un valor entero.
 *
 * La función analiza la cadena apuntada por `nptr` e interpreta su contenido
 * como un número entero decimal, manejando los posibles espacios iniciales
 * y los signos '+' o '-'.
 *
 * @param nptr Puntero a la cadena que se desea convertir a entero.
 *             Debe terminar con el carácter nulo '\0'.
 *
 * @return El valor entero resultante de la conversión. Si la cadena comienza
 *         con un signo '-', el resultado será negativo.
 *
 * @note Esta función no gestiona desbordamientos (overflow o underflow).
 */
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
