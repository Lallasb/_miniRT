/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:13:31 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/18 00:45:41 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include "get_next_line.h"

char	*ft_read_buffer(int fd, char *rest)
{
	ssize_t	n;
	char	*rd;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rd = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!rd)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, rd, BUFFER_SIZE);
		if (n < 0)
			return (free(rd), NULL);
		rd[n] = '\0';
		if (n == 0)
			break ;
		rest = ft_strjoin_g(rest, rd);
		if (rest == NULL)
			return (free(rd), NULL);
		if (ft_strch(rest, '\n'))
			break ;
	}
	free(rd);
	return (rest);
}

void	save_ptr(char *ptr, int flag)
{
	static char	*ptr1;

	if (flag)
		free(ptr1);
	else
		ptr1 = ptr;
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*tmp;
	char		*line;
	int			z;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rest = ft_read_buffer(fd, rest);
	if (rest == NULL)
		return (NULL);
	tmp = NULL;
	if (ft_strch(rest, '\n'))
		tmp = ft_strdup_g(ft_strch(rest, '\n') + 1);
	z = len(rest) - len(tmp);
	line = ft_substr_g(rest, 0, z);
	if (line == NULL)
		return (NULL);
	free(rest);
	rest = ft_strdup_g(tmp);
	save_ptr(rest, 0);
	free(tmp);
	if (*line == '\0')
		return (free(line), free(rest), NULL);
	return (line);
}
