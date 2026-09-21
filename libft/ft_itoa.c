/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 05:03:48 by lasoubai          #+#    #+#             */
/*   Updated: 2024/10/31 18:35:25 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenth(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_invcpy(unsigned int u_n, int len, int sign)
{
	char	*ptr;
	int		l;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '0';
	ptr[len] = '\0';
	l = len - 1;
	while (u_n)
	{
		ptr[l] = u_n % 10 + 48;
		u_n /= 10;
		l--;
	}
	if (sign < 0)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	u_n;
	char			*ptr;
	int				sign;

	sign = 1;
	len = 0;
	if (n < 0)
	{
		u_n = -n;
		sign = -sign;
		len = lenth(u_n) + 1;
	}
	else
	{
		u_n = n;
		len = lenth(u_n);
	}
	ptr = ft_invcpy(u_n, len, sign);
	return (ptr);
}
