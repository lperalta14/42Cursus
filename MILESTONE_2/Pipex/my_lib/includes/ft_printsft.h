#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

/****************************************/
/*				ft_printf				*/
/****************************************/

/**
 * @brief Handles format specifiers and prints the corresponding argument.
 *
 * @param type The format specifier (e.g., 'c', 's', 'd', 'x', etc.).
 * @param args The list of variable arguments.
 * @return int The number of characters printed.
 */
int		ft_specifiers(char type, va_list args);

/**
 * @brief Prints a single character to the standard output.
 *
 * @param c The character to print.
 * @return int The number of characters printed (always 1).
 */
int		ft_putchar(char c);

/**
 * @brief Prints a string to the standard output.
 *
 * @param s The string to print.
 * @return int The number of characters printed.
 */
int		ft_putstr(char *s);

/**
 * @brief Prints an integer and returns the number of characters printed.
 *
 * @param n The integer to print.
 * @return int The number of characters printed.
 */
int		ft_putnbrcnt(int n);

/**
 * @brief Prints an unsigned integer and returns the number of characters printed.
 *
 * @param n The unsigned integer to print.
 * @return int The number of characters printed.
 */
int		ft_unsigput(unsigned int n);

/**
 * @brief Prints a number in hexadecimal format.
 *
 * @param n The number to print.
 * @param x The format specifier ('x' for lowercase, 'X' for uppercase).
 * @return int The number of characters printed.
 */
int		ft_puthex(unsigned long n, char x);

/**
 * @brief Prints a pointer address in hexadecimal format (prefixed with "0x").
 *
 * @param n The pointer value to print.
 * @return int The number of characters printed.
 */
int		ft_putptr(unsigned long n);

/**
 * @brief A simplified recreation of the C standard printf function.
 *
 * @param nbr The format string to parse.
 * @param ... The variable arguments to format and print.
 * @return int The total number of characters printed.
 */
int		ft_printf(const char *nbr, ...);


#endif