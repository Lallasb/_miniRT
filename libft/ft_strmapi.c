/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:29:52 by lasoubai          #+#    #+#             */
/*   Updated: 2024/11/01 22:23:12 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			l;
	char			*p;

	if (!s)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (l + 1));
	if (p == NULL)
		return (NULL);
	while ((char)s[i])
	{
		p[i] = (*f)(i, (char)s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
