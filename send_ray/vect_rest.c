/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:53 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/15 14:58:19 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vect	normalization(t_vect v)
{
	t_vect	u;
	float	m;

	m = magnaitude(v);
	if (m == 0)
		return (v);
	u.x = v.x / m;
	u.y = v.y / m;
	u.z = v.z / m;
	return (u);
}

float	dot(t_vect v, t_vect w)
{
	float	d;

	d = v.x * w.x + v.y * w.y + v.z * w.z;
	return (d);
}

t_vect	cross(t_vect v, t_vect w)
{
	t_vect	c;

	c.x = v.y * w.z - v.z * w.y;
	c.y = v.z * w.x - v.x * w.z;
	c.z = v.x * w.y - v.y * w.x;
	return (c);
}
