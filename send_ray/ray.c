/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:38 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/15 14:52:13 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vect	ray_equation(t_vect origin, t_vect dir, float t)
{
	t_vect	p;

	p = add_vect(origin, scalar(dir, t));
	return (p);
}

float	sphere(t_sp s, t_ray ray)
{
	float	t;
	float	delta;
	float	a;
	float	b;
	float	ce;

	a = dot(ray.direct, ray.direct);
	b = 2 * dot(sub_vect(ray.origine, s.center), ray.direct);
	ce = dot(sub_vect(ray.origine, s.center), sub_vect(ray.origine, s.center))
		- (s.ray * s.ray);
	delta = (b * b) - (4 * a * ce);
	if (delta >= 0)
	{
		t = (-b - sqrtf(delta)) / (2 * a);
		if (t > ((-b + sqrtf(delta)) / (2 * a)) || t < 0)
			t = (-b + sqrtf(delta)) / (2 * a);
		if (t < 0.001)
			return (-1);
		return (t);
	}
	return (-1);
}

float	plan(t_pl pl, t_ray ray)
{
	float	t;

	t = 0;
	pl.normal_v = normalization(pl.normal_v);
	if (dot(ray.direct, pl.normal_v) == 0.001)
		return (-1);
	t = dot(sub_vect(pl.posit, ray.origine), pl.normal_v) / dot(ray.direct,
			pl.normal_v);
	if (t < 0.001)
		return (-1);
	return (t);
}
