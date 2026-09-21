/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:17:07 by lasoubai          #+#    #+#             */
/*   Updated: 2024/10/25 05:48:01 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	j;
	size_t	l;

	ls = ft_strlen(src);
	if (size == 0 || !dst)
		return (ls);
	ld = ft_strlen(dst);
	if (size <= ld)
		return (ls + size);
	j = 0;
	l = ld;
	while (src[j] && j < size - ld - 1)
	{
		dst[l] = src[j];
		j++;
		l++;
	}
	dst[l] = '\0';
	return (ls + ld);
}
