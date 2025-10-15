/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:44:54 by lperalta          #+#    #+#             */
/*   Updated: 2025/04/22 12:46:16 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>


# include "ft_list.h"
# include "ft_printsft.h"
# include "GNL.h"
# include "ft_utils.h"

/****************************************/
/*				ft_libft				*/
/****************************************/

/**
 * @brief Comprueba si un carácter es un espacio en blanco.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter es un espacio en blanco, 0 en caso contrario.
 */
int		ft_isspace(int c);

/**
 * @brief Comprueba si un carácter es una letra mayúscula.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter es una letra mayúscula ('A'–'Z'), 0 en caso contrario.
 */
int		ft_isupper(int c);

/**
 * @brief Comprueba si un carácter es una letra minúscula.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter es una letra minúscula ('a'–'z'), 0 en caso contrario.
 */
int		ft_islower(int c);

/**
 * @brief Comprueba si un carácter es alfabético.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter es una letra (mayúscula o minúscula), 0 en caso contrario.
 */
int		ft_isalpha(int c);

/**
 * @brief Comprueba si un carácter es un dígito decimal.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter está entre '0' y '9', 0 en caso contrario.
 */
int		ft_isdigit(int c);


/**
 * @brief Comprueba si un carácter es alfanumérico.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter es una letra o un dígito, 0 en caso contrario.
 */
int		ft_isalnum(int c);

/**
 * @brief Comprueba si un carácter pertenece al conjunto ASCII.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter está dentro del rango ASCII (0–127), 0 en caso contrario.
 */
int		ft_isascii(int c);

/**
 * @brief Comprueba si un carácter es imprimible.
 *
 * @param c Carácter a evaluar (representado como un entero).
 * @return 1 si el carácter tiene una representación visible, 0 en caso contrario.
 */
int		ft_isprint(int c);

/**
 * @brief Convierte un carácter minúsculo en mayúsculo.
 *
 * @param c Carácter a convertir.
 * @return El carácter convertido a mayúscula si era minúscula,
 *         o el mismo carácter si no aplica.
 */
int		ft_toupper(int c);

/**
 * @brief Convierte un carácter mayúsculo en minúsculo.
 *
 * @param c Carácter a convertir.
 * @return El carácter convertido a minúscula si era mayúscula,
 *         o el mismo carácter si no aplica.
 */
int		ft_tolower(int c);

/**
 * @brief Calcula la longitud de una cadena de caracteres.
 *
 * Esta función cuenta el número de caracteres en la cadena 's' 
 * hasta encontrar el carácter nulo '\0'.
 *
 * @param s Puntero a la cadena de caracteres terminada en nulo.
 * @return El número de caracteres en la cadena (sin contar el '\0').
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Rellena un bloque de memoria con un valor específico.
 *
 * Esta función establece los primeros 'n' bytes del bloque de memoria 
 * apuntado por 's' al valor 'c' (convertido a unsigned char).
 *
 * @param s Puntero al bloque de memoria a rellenar.
 * @param c Valor a establecer (interpretado como unsigned char).
 * @param n Número de bytes a escribir.
 * @return Un puntero al bloque de memoria 's'.
 */
void	*ft_memset(void *s, int c, size_t n);

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
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copia un bloque de memoria de una ubicación a otra.
 *
 * Copia exactamente 'n' bytes desde el área de memoria 'src' a 'dest'.
 * El comportamiento es indefinido si las áreas de memoria se solapan.
 *
 * @param dest Puntero al destino donde se copiarán los bytes.
 * @param src Puntero al origen desde donde se copiarán los bytes.
 * @param n Número de bytes a copiar.
 * @return Un puntero al bloque de memoria 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copia un bloque de memoria incluso si las áreas se solapan.
 *
 * Similar a ft_memcpy, pero segura en caso de solapamiento entre
 * 'src' y 'dest'. Los bytes se copian de manera que se evita la corrupción
 * de datos.
 *
 * @param dest Puntero al destino donde se copiarán los bytes.
 * @param src Puntero al origen desde donde se copiarán los bytes.
 * @param n Número de bytes a copiar.
 * @return Un puntero al bloque de memoria 'dest'.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

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
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compara dos bloques de memoria byte a byte.
 *
 * Examina los primeros 'n' bytes de los bloques de memoria 's1' y 's2'.
 * Devuelve un valor que indica la relación entre los bloques:
 *   - < 0 si s1 es menor que s2,
 *   - 0 si son iguales,
 *   - > 0 si s1 es mayor que s2.
 *
 * @param s1 Puntero al primer bloque de memoria.
 * @param s2 Puntero al segundo bloque de memoria.
 * @param n Número de bytes a comparar.
 * @return Entero que indica la relación entre los bloques comparados.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copia una cadena de caracteres de forma segura.
 *
 * Copia hasta `size - 1` caracteres desde la cadena `src` hacia `dst`,
 * asegurando que `dst` esté siempre terminada en nulo (`\0`) si `size > 0`.
 *
 * @param dst Puntero al buffer de destino donde se copiará la cadena.
 * @param src Puntero a la cadena de origen.
 * @param size Tamaño total del buffer de destino.
 * @return La longitud total de la cadena que se intentó copiar (longitud de `src`).
 *         Esto permite detectar truncamientos si el valor devuelto >= size.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Concatena cadenas de forma segura.
 *
 * Añade la cadena `src` al final de `dst`, asegurando que el resultado
 * esté terminado en nulo y sin sobrepasar `size` bytes.
 *
 * @param dst Puntero al buffer de destino.
 * @param src Puntero a la cadena de origen.
 * @param size Tamaño total del buffer de destino.
 * @return La longitud total de la cadena que se intentó crear
 *         (longitud inicial de dst + longitud de src).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Busca la primera aparición de un carácter en una cadena.
 *
 * @param s Puntero a la cadena a examinar.
 * @param c Carácter a buscar (interpretado como unsigned char).
 * @return Puntero al primer byte coincidente o NULL si no se encuentra.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Busca la última aparición de un carácter en una cadena.
 *
 * @param s Puntero a la cadena a examinar.
 * @param c Carácter a buscar (interpretado como unsigned char).
 * @return Puntero al último byte coincidente o NULL si no se encuentra.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compara dos cadenas hasta n caracteres.
 *
 * @param s1 Puntero a la primera cadena.
 * @param s2 Puntero a la segunda cadena.
 * @param n Número máximo de caracteres a comparar.
 * @return Entero <0, 0 o >0 según s1 sea menor, igual o mayor que s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Reserva memoria inicializada a cero.
 *
 * Reserva espacio suficiente para un array de `nmemb` elementos de `size` bytes
 * y lo inicializa a cero.
 *
 * @param nmemb Número de elementos.
 * @param size Tamaño de cada elemento en bytes.
 * @return Puntero a la memoria reservada, o NULL si falla la asignación.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Duplica una cadena de caracteres.
 *
 * Reserva memoria para una copia exacta de `s` y devuelve un puntero a ella.
 *
 * @param s Puntero a la cadena original.
 * @return Puntero a la copia recién creada en memoria dinámica.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Une dos cadenas en una nueva.
 *
 * Reserva memoria para una cadena que concatene `s1` y `s2` y devuelve el puntero.
 *
 * @param s1 Puntero a la primera cadena.
 * @param s2 Puntero a la segunda cadena.
 * @return Puntero a la nueva cadena concatenada.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Escribe un carácter en un descriptor de archivo.
 *
 * @param c Carácter a escribir.
 * @param fd Descriptor de archivo (por ejemplo, 1 = stdout).
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Escribe una cadena en un descriptor de archivo.
 *
 * @param s Puntero a la cadena a escribir.
 * @param fd Descriptor de archivo.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Escribe una cadena seguida de un salto de línea en un descriptor de archivo.
 *
 * @param s Puntero a la cadena a escribir.
 * @param fd Descriptor de archivo.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Escribe un número entero en un descriptor de archivo.
 *
 * @param n Número entero a escribir.
 * @param fd Descriptor de archivo.
 */
void	ft_putnbr_fd(int n, int fd);

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
int		ft_atoi(const char *nptr);

/**
 * @brief Calcula el número de dígitos de un número entero.
 *
 * @param n Número entero a evaluar.
 * @return Número de dígitos del entero.
 */
int		ft_lendigit(int n);

/**
 * @brief Convierte un entero en una cadena de caracteres.
 *
 * Reserva memoria para una cadena que represente el número entero `n`
 * y devuelve un puntero a ella.
 *
 * @param n Número entero a convertir.
 * @return Puntero a la cadena resultante.
 */
char	*ft_itoa(int n);

/**
 * @brief Aplica una función a cada carácter de una cadena y devuelve una nueva cadena.
 *
 * @param s Puntero a la cadena original.
 * @param f Función que recibe el índice y el carácter, y devuelve el nuevo carácter.
 * @return Puntero a la nueva cadena modificada.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Aplica una función a cada carácter de una cadena (modifica in-place).
 *
 * @param s Puntero a la cadena a modificar.
 * @param f Función que recibe el índice y un puntero al carácter.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Busca la primera aparición de la cadena 'little' dentro de 'big'.
 *
 * Examina solo los primeros 'len' caracteres de 'big'.
 *
 * @param big Puntero a la cadena donde buscar.
 * @param little Puntero a la cadena a buscar.
 * @param len Número máximo de caracteres a examinar en 'big'.
 * @return Puntero a la primera aparición de 'little', o NULL si no se encuentra.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Elimina los caracteres especificados al inicio y al final de una cadena.
 *
 * @param s1 Cadena original.
 * @param set Conjunto de caracteres a eliminar.
 * @return Nueva cadena con los caracteres eliminados, memoria dinámica.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Extrae una subcadena de la cadena original.
 *
 * @param s Cadena original.
 * @param start Índice desde donde comenzar la subcadena.
 * @param len Longitud de la subcadena.
 * @return Nueva cadena con la subcadena, memoria dinámica.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Divide una cadena en un array de cadenas usando un delimitador.
 *
 * @param s Cadena original.
 * @param c Carácter delimitador.
 * @return Array de cadenas resultante, terminado en NULL. Memoria dinámica.
 */
char	**ft_split(char const *s, char c);

#endif
