/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:35:43 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/23 00:40:12 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		f = f * 10 + nptr[i] - 48;
		if (f >= 256)
			return (-1);
		i++;
	}
	if (nptr[i])
		return (-1);
	return (f);
}
