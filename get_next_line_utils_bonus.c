/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommy <ctommy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:45:00 by ctommy            #+#    #+#             */
/*   Updated: 2021/12/14 22:45:21 by ctommy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strcpy(char *str, ssize_t len)
{
	char	*str_new;

	str_new = str + len;
	while (*str_new)
		*(str++) = *(str_new++);
	*str = '\0';
}

char	*ft_strjoin(char *s1, char *s2, ssize_t len)
{
	char	*str_join;
	char	*str_s1;
	char	*str_f;

	if (!s2)
		return (s1);
	len++;
	str_join = malloc(sizeof(char) * len);
	if (!str_join)
		return (NULL);
	str_f = str_join;
	str_s1 = s1;
	while (*s1 && --len)
		*(str_join++) = *(s1++);
	while (*s2 && --len)
		*(str_join++) = *(s2++);
	*str_join = '\0';
	free (str_s1);
	return (str_f);
}

int	ft_strchr(char *str, ssize_t *len)
{
	*len = 0;
	while (*str && (*str != '\n') && ++*len)
		str++;
	if (*str == '\n' && ++*len)
		return (1);
	return (0);
}

void	*ft_free(void *str)
{
	free(str);
	return (NULL);
}
