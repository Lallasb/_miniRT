/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:45:33 by lasoubai          #+#    #+#             */
/*   Updated: 2024/11/18 01:02:54 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strd(char const *ptr, int lp, int k)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * lp + 1);
	if (p == NULL)
		return (NULL);
	while (i < lp)
	{
		p[i] = ptr[k];
		i++;
		k++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		lstar;
	int		lend;
	char	*p;

	if (!s1)
		return (NULL);
	lstar = 0;
	lend = ft_strlen(s1);
	while (s1[lstar] && ft_chr(set, s1[lstar]) == 1)
	{
		lstar++;
	}
	while (lend > lstar && ft_chr(set, s1[lend - 1]) == 1)
	{
		lend--;
	}
	i = lend - lstar;
	p = ft_strd(s1, i, lstar);
	return (p);
}
