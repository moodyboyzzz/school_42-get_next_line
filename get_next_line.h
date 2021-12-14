/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:45:07 by ctommy            #+#    #+#             */
/*   Updated: 2021/12/14 22:45:13 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *str, ssize_t *len);
char	*ft_strjoin(char *s1, char *s2, ssize_t len);
void	ft_strcpy(char *str, ssize_t len);
void	*ft_free(void *str);

char	*ft_read_file(int fd, char *stat);
char	*get_next_line(int fd);

#endif