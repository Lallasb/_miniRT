/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:31:44 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/19 13:31:45 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	int_it(t_init *v)
{
	v->a = 0.0;
	v->b = 0.0;
	v->c = 0.0;
	v->delta = 0.0;
	v->t1 = 0.0;
	v->t2 = 0.0;
	v->t = -1.0;
	v->h = 0.0;
}

void	cy_quadratic(t_cy *cy, t_ray ray, t_vect oc, t_init *v)
{
	float	d_dot_a;

	d_dot_a = dot(ray.direct, cy->axis_v);
	v->a = 1.0f - d_dot_a * d_dot_a;
	v->b = 2.0f * (dot(ray.direct, oc) - d_dot_a * dot(oc, cy->axis_v));
	v->c = dot(oc, oc) - powf(dot(oc, cy->axis_v), 2.0f) - powf(cy->ray, 2.0f);
	v->delta = v->b * v->b - 4 * v->a * v->c;
}
