/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:05:38 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/17 04:35:15 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup_g(char *str)
{
	int		i;
	char	*p;

	if (!str)
		return (NULL);
	i = len(str);
	p = malloc(i + 1);
	if (p == NULL)
		return (p = NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin_g(char *rest, char *rd)
{
	int		j;
	int		i;
	char	*p;

	p = malloc(len(rest) + len(rd) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	if (rest)
	{
		while (rest[i])
		{
			p[i] = rest[i];
			i++;
		}
	}
	j = 0;
	if (rd)
	{
		while (rd[j])
			p[i++] = rd[j++];
	}
	p[i] = '\0';
	free(rest);
	return (p);
}

char	*ft_strch(char *rest, char nl)
{
	int	i;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i])
	{
		if (rest[i] == nl)
			return (&rest[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr_g(char *rest, int start, int ln)
{
	char	*p;
	int		i;

	i = 0;
	if (!rest)
		return (NULL);
	if (start >= len(rest))
		return (ft_strdup_g(""));
	p = malloc(ln + 1);
	if (p == NULL)
		return (NULL);
	while (rest[start] && i < ln)
	{
		p[i] = rest[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
