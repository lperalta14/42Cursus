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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ft_lib
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_atoi(const char *nptr);
int		ft_toupper(int c);
int		ft_tolower(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isspace(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_len(int n);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
//ft_list
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
// ft_printf
int		ft_specifiers(char type, va_list args);
int		ft_slen(char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbrcnt(int n);
int		ft_unsigput(unsigned int n);
int		ft_puthex(unsigned long n, char x);
int		ft_putptr(unsigned long n);
int		ft_printf(const char *nbr, ...);

// GNL
char	*get_next_line(int fd);
char	*ft_extract_line(char *res);
char	*ft_save_remainder(char *res);

int		ft_strlen_gnl(const char *s);
char	*ft_strchr_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, int len);
char	*ft_strdup_gnl(const char *s);

// ft_utils
int		ft_atoi_base(const char *str, int str_base);
long	ft_atolints(const char *nptr);
void	ft_putnbr(int n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_replacechar(char *s, char a, char b);
char	*ft_strjoindelimit(char const *s1, char *delimit, char const *s2);
char	**ft_splitq(char const *s, char c, int wcnt);
void	ft_putmatrix(char **str, int fd);
void	ft_freematrix(char **str);

#endif
