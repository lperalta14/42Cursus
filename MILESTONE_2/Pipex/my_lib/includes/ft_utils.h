#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "libft.h"

/****************************************/
/*				ft_utils				*/
/****************************************/

/**
 * @file utils_bonus.h
 * @brief Utility functions for string handling, conversion, and memory management.
 */

/**
 * @brief Converts a string to an integer in a specified base.
 *
 * @param str The string to convert.
 * @param str_base The base to use for conversion (2–16).
 * @return int The converted integer value.
 */
int		ft_atoi_base(const char *str, int str_base);

/**
 * @brief Converts a string to a long integer.
 *
 * This function parses the string `nptr` and converts it to a `long` integer.
 * It handles optional leading whitespaces, an optional '+' or '-' sign, 
 * and stops conversion if a non-digit character is found.
 * 
 * @param nptr A pointer to the null-terminated string to convert.
 * @return The converted `long` value on success.
 *         Returns the value if it overflows beyond `INT_MIN` or `INT_MAX`.
 */
long	ft_atolints(const char *nptr);

/**
 * @file utils_bonus.h
 * @brief Utility functions for string handling, conversion, and memory management.
 */

/**
 * @brief Prints an integer to the standard output.
 *
 * @param n The integer to print.
 */
void	ft_putnbr(int n);

/**
 * @brief Compares two strings lexicographically.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return int Zero if strings are equal, a positive value if s1 > s2, or a negative value if s1 < s2.
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Replaces all occurrences of a character in a string with another.
 *
 * @param s The string to modify.
 * @param a The character to replace.
 * @param b The replacement character.
 * @return char* The modified string.
 */
char	*ft_replacechar(char *s, char a, char b);

/**
 * @brief Joins two strings with a delimiter between them.
 *
 * @param s1 The first string.
 * @param delimit The delimiter string to insert.
 * @param s2 The second string.
 * @return char* A new string with s1, delimiter, and s2 concatenated. Must be freed by the caller.
 */
char	*ft_strjoindelimit(char const *s1, char *delimit, char const *s2);

/**
 * @brief Splits a string by a delimiter, respecting single quotes as grouping characters.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @param wcnt The initial word count (should usually be 0).
 * @return char** A NULL-terminated array of strings. Must be freed using ft_freematrix().
 */
char	**ft_splitq(char const *s, char c, int wcnt);

/**
 * @brief Prints a matrix (array of strings) line by line to a file descriptor.
 *
 * @param str The string matrix to print.
 * @param fd The file descriptor to write to.
 */
void	ft_putmatrix(char **str, int fd);

/**
 * @brief Frees a matrix (array of strings) and sets the pointer to NULL.
 *
 * @param str The string matrix to free.
 */
void	ft_freematrix(char **str);

#endif