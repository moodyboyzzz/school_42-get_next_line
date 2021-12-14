/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:45:05 by ctommy            #+#    #+#             */
/*   Updated: 2021/12/14 22:45:24 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *stat)
{
	char	*line;
	ssize_t	line_len;
	ssize_t	stat_len;
	ssize_t	full_len;

	line = malloc(sizeof(char));
	*line = '\0';
	full_len = 0;
	if (!ft_strchr(stat, &line_len))
	{
		stat_len = 1;
		while (stat_len > 0 && !ft_strchr(stat, &line_len))
		{
			full_len += line_len;
			line = ft_strjoin(line, stat, full_len);
			stat_len = read(fd, stat, BUFFER_SIZE);
			if (!line || stat_len == -1)
				return (NULL);
			*(stat + stat_len) = '\0';
		}
	}
	line = ft_strjoin(line, stat, full_len + line_len);
	ft_strcpy(stat, line_len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		check;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, &check, 0) == -1))
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * ((ssize_t)BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		*str = '\0';
	}
	line = ft_read_file(fd, str);
	if (line == NULL || *line == '\0')
	{
		str = ft_free(str);
		line = ft_free(line);
	}
	return (line);
}
