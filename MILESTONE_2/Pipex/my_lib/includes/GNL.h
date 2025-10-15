#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/****************************************/
/*					GNL					*/
/****************************************/

/**
 * @file get_next_line.h
 * @brief A function to read a line from a file descriptor, including helper utilities.
 */

/**
 * @brief Reads and returns the next line from the given file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return char* The next line read, or NULL if EOF or error occurs.
 */
char	*get_next_line(int fd);

/**
 * @brief Extracts a single line (up to and including the newline) from the buffer.
 *
 * @param res The string buffer containing the current read data.
 * @return char* The extracted line, or NULL if no line is found.
 */
char	*ft_extract_line(char *res);

/**
 * @brief Saves the remainder of the buffer after extracting a line.
 *
 * @param res The current buffer string.
 * @return char* The remaining part of the buffer, or NULL if none remains.
 */
char	*ft_save_remainder(char *res);

/**
 * @brief Searches for the first newline character in the given string.
 *
 * @param s The string to search.
 * @return char* A pointer to the newline character if found, or NULL otherwise.
 */
char	*ft_strchr_gnl(char *s);

/**
 * @brief Joins two strings, freeing the first one, and returns the concatenated result.
 *
 * @param s1 The first string (freed after concatenation).
 * @param s2 The second string to append.
 * @return char* The concatenated string, or NULL on allocation failure.
 */
char	*ft_strjoin_gnl(char *s1, char *s2);

/**
 * @brief Creates a substring from a given string up to a specified length.
 *
 * @param s The original string.
 * @param len The length of the substring to create.
 * @return char* The allocated substring, or NULL on failure.
 */
char	*ft_substr_gnl(char *s, int len);

/**
 * @brief Duplicates a string by allocating a new one with the same content.
 *
 * @param s The string to duplicate.
 * @return char* The duplicated string, or NULL on allocation failure.
 */
char	*ft_strdup_gnl(const char *s);

#endif