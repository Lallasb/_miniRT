/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:34:16 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 21:22:33 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '.' || str[0] == '-')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_color(float r, float g, float b)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		return (1);
	return (0);
}

int	check_coord(float x, float y, float z)
{
	if (x == 0 && y == 0 && z == 0)
		return (1);
	if (x < -1.0 || x > 1.0 || y < -1.0 || y > 1.0 || z < -1.0 || z > 1.0)
		return (1);
	return (0);
}
