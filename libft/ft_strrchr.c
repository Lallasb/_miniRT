/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:48:35 by lasoubai          #+#    #+#             */
/*   Updated: 2024/10/25 15:32:49 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	while ((char)s[i])
	{
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	j = i - 1;
	while (j >= 0)
	{
		if (s[j] == (char)c)
			return ((char *)&s[j]);
		--j;
	}
	return (NULL);
}
