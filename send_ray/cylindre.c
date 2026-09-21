/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:58:28 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 18:48:17 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	cy_solve_delta(t_init *v)
{
	if (v->delta <= 0)
		return ;
	v->t1 = (-v->b - sqrtf(v->delta)) / (2 * v->a);
	v->t2 = (-v->b + sqrtf(v->delta)) / (2 * v->a);
	v->t = v->t1;
	if (v->t <= 0.001f || (v->t2 > 0.001f && v->t2 < v->t))
		v->t = v->t2;
}

static float	cy_height_check(t_cy *cy, t_ray ray, float t)
{
	t_vect	p;
	float	h;

	if (t <= 0.001f)
		return (-1);
	p = add_vect(ray.origine, scalar(ray.direct, t));
	h = dot(sub_vect(p, cy->center), cy->axis_v);
	if (h < -cy->height / 2 || h > cy->height / 2)
		return (-1);
	return (t);
}

float	cap_inters(t_cy cy, t_ray ray)
{
	float	t;
	float	d;
	t_vect	p;
	t_vect	h;
	float	dst;

	d = dot(ray.direct, cy.axis_v);
	if (fabsf(d) < 0.0001f)
		return (-1);
	p = sub_vect(cy.cap_centr, ray.origine);
	t = dot(p, cy.axis_v) / d;
	if (t <= 0.001)
		return (-1);
	h = sub_vect(ray_equation(ray.origine, ray.direct, t), cy.cap_centr);
	dst = magnaitude(sub_vect(h, scalar(cy.axis_v, dot(h, cy.axis_v))));
	if (dst <= cy.ray)
		return (t);
	return (-1);
}

static float	cy_min_t(float body, float top, float bottom)
{
	float	t;

	t = -1;
	if (body > 0.001f)
		t = body;
	if (top > 0.001f && (t < 0 || top < t))
		t = top;
	if (bottom > 0.001f && (t < 0 || bottom < t))
		t = bottom;
	return (t);
}

float	check_cy_inters(t_cy *cy, t_ray ray)
{
	t_vect	oc;
	t_init	v;
	float	t_body;
	float	t_top;
	float	t_bottom;

	int_it(&v);
	cy->axis_v = normalization(cy->axis_v);
	oc = sub_vect(ray.origine, cy->center);
	cy_quadratic(cy, ray, oc, &v);
	cy_solve_delta(&v);
	t_body = cy_height_check(cy, ray, v.t);
	cy->cap_centr = add_vect(cy->center, scalar(cy->axis_v, cy->height / 2.0f));
	t_top = cap_inters(*cy, ray);
	cy->cap_centr = add_vect(cy->center,
			scalar(cy->axis_v, -cy->height / 2.0f));
	t_bottom = cap_inters(*cy, ray);
	return (cy_min_t(t_body, t_top, t_bottom));
}
