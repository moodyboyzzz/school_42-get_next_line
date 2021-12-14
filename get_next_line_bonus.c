/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:44:55 by ctommy            #+#    #+#             */
/*   Updated: 2021/12/14 22:45:17 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[FD_MAX];
	char		*line;
	char		check;

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, &check, 0) == -1))
		return (NULL);
	if (!str[fd])
	{
		str[fd] = malloc(sizeof(char) * ((ssize_t)BUFFER_SIZE + 1));
		if (!str[fd])
			return (NULL);
		str[fd][0] = '\0';
	}
	line = ft_read_file(fd, str[fd]);
	if (line == NULL || *line == '\0')
	{
		str[fd] = ft_free(str[fd]);
		line = ft_free(line);
	}
	return (line);
}
