/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:16:16 by lperalta          #+#    #+#             */
/*   Updated: 2025/06/21 13:27:02 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

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

int		ft_strlen(const char *s);

/**
 * @brief Searches for the first newline character in the given string.
 *
 * @param s The string to search.
 * @return char* A pointer to the newline character if found, or NULL otherwise.
 */
char	*ft_strchr(char *s);

/**
 * @brief Joins two strings, freeing the first one, and returns the concatenated result.
 *
 * @param s1 The first string (freed after concatenation).
 * @param s2 The second string to append.
 * @return char* The concatenated string, or NULL on allocation failure.
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief Creates a substring from a given string up to a specified length.
 *
 * @param s The original string.
 * @param len The length of the substring to create.
 * @return char* The allocated substring, or NULL on failure.
 */
char	*ft_substr(char *s, int len);

/**
 * @brief Duplicates a string by allocating a new one with the same content.
 *
 * @param s The string to duplicate.
 * @return char* The duplicated string, or NULL on allocation failure.
 */
char	*ft_strdup(const char *s);

#endif
