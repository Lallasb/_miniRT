/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 08:58:47 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/22 23:15:13 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	ft_sig(char *nbr, int *i)
{
	int	s;

	s = 1;
	if (nbr[*i] == '-' || nbr[*i] == '+')
	{
		if (nbr[*i] == '-')
			s = -1;
		(*i)++;
	}
	return (s);
}

int	ft_valid(char *nbr, int *s)
{
	int	i;

	i = 0;
	while (nbr[i] && nbr[i] <= 32)
		i++;
	*s = ft_sig(nbr, &i);
	if (nbr[i] && !ft_isdigit(nbr[i]))
		return (1);
	while (nbr[i] && ft_isdigit(nbr[i]))
		i++;
	if (nbr[i] && nbr[i] == '.')
	{
		i++;
		if (nbr[i] == '\0')
			return (1);
		while (nbr[i] && ft_isdigit(nbr[i]))
			i++;
	}
	if (nbr[i])
		return (1);
	return (0);
}

long	ft_atoi_m(const char *nptr)
{
	int				i;
	int				sign;
	unsigned long	f;

	f = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && nptr[i] <= 32)
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		f = f * 10 + nptr[i] - 48;
		if (INT_MAX < f)
			return (f);
		i++;
	}
	return (f * sign);
}

float	ft_atof(char *nbr)
{
	long int	r;
	long int	r1;
	int			p;
	int			s;

	p = 1;
	s = 1;
	if (ft_valid(nbr, &s))
		return (UN);
	r = ft_atoi_m(nbr);
	nbr = ft_strchr(nbr, '.') + 1;
	r1 = 0;
	if (nbr[0] != 'b')
		r1 = ft_atoi_m(nbr);
	if (INT_MAX < r || INT_MAX < r1)
		return (UN);
	while (*nbr <= '9' && *nbr >= '0')
	{
		p *= 10;
		nbr++;
	}
	if (s == -1)
		return (((float)r - (float)r1 / (float)p));
	return (((float)r + (float)r1 / (float)p));
}
