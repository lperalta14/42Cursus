/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperalta <lperalta@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:15:46 by lperalta          #+#    #+#             */
/*   Updated: 2025/07/03 11:37:32 by lperalta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/GNL.h"

char	*ft_read_loop(int fd, char **res, char *buffer)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr_gnl(*res) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (*res)
			{
				free(*res);
				*res = NULL;
			}
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		*res = ft_strjoin_gnl(*res, buffer);
	}
	return (*res);
}

char	*ft_file_read(char **res, int fd)
{
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!ft_read_loop(fd, res, buffer))
	{
		free(buffer);
		return (NULL);
	}
	free (buffer);
	return (*res);
}

char	*ft_extract_line(char *res)
{
	int		i;

	if (!res || !*res)
		return (NULL);
	if (!ft_strchr_gnl(res))
		return (ft_strdup_gnl(res));
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (res[i] == '\n')
		i++;
	return (ft_substr_gnl(res, i));
}

char	*ft_clean_static(char *res)
{
	int		i;
	char	*save;

	if (!res)
		return (NULL);
	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (NULL);
	}
	save = ft_strdup_gnl(res + i + 1);
	free(res);
	if (save && save[0] == '\0')
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!ft_file_read(&res, fd))
		return (NULL);
	line = ft_extract_line(res);
	res = ft_clean_static(res);
	return (line);
}
