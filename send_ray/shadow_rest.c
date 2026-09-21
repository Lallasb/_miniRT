/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_rest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:46 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/15 14:56:58 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vect	negate_vect(t_vect v)
{
	t_vect	result;

	result.x = -v.x;
	result.y = -v.y;
	result.z = -v.z;
	return (result);
}

t_vect	get_cylinder_normal(t_cy cylinder, t_vect hit_point)
{
	float	dot_proj;
	t_vect	oc;
	t_vect	projection;
	t_vect	normal;

	oc = sub_vect(hit_point, cylinder.center);
	dot_proj = dot(oc, cylinder.axis_v);
	projection = scalar(cylinder.axis_v, dot_proj);
	normal = sub_vect(oc, projection);
	normal = normalization(normal);
	return (normal);
}

t_vect	get_plane_normal(t_pl plane)
{
	return (normalization(plane.normal_v));
}

t_vect	get_sphere_normal(t_sp sphere, t_vect hit_point)
{
	t_vect	normal;

	normal = sub_vect(hit_point, sphere.center);
	normal = normalization(normal);
	return (normal);
}
