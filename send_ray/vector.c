/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:45:26 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/15 14:41:05 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vect	add_vect(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vect	sub_vect(t_vect v1, t_vect v2)
{
	t_vect	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

float	magnaitude(t_vect v)
{
	float	result;

	result = v.x * v.x + v.y * v.y + v.z * v.z;
	return (sqrtf(result));
}

t_vect	scalar(t_vect v, float k)
{
	t_vect	w;

	w.x = k * v.x;
	w.y = k * v.y;
	w.z = k * v.z;
	return (w);
}
