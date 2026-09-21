/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:19 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/15 14:49:38 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	shadow_sphere(t_sp *sp, t_ray ray, float light_dist)
{
	float	t;

	while (sp)
	{
		t = sphere(*sp, ray);
		if (t > 0.001 && t < light_dist)
			return (1);
		sp = sp->next;
	}
	return (0);
}

static int	shadow_cylinder(t_cy *cy, t_ray ray, float light_dist)
{
	float	t;

	while (cy)
	{
		t = check_cy_inters(cy, ray);
		if (t > 0.001 && t < light_dist)
			return (1);
		cy = cy->next;
	}
	return (0);
}

static int	shadow_plane(t_pl *pl, t_ray ray, float light_dist)
{
	float	t;

	while (pl)
	{
		t = plan(*pl, ray);
		if (t > 0.001 && t < light_dist)
			return (1);
		pl = pl->next;
	}
	return (0);
}

static t_ray	create_shadow_ray(t_vect hit_point, t_vect light_pos,
		t_vect normal)
{
	t_ray	ray;
	t_vect	dir;

	dir = sub_vect(light_pos, hit_point);
	ray.origine = add_vect(hit_point, scalar(normalization(normal), 0.001));
	ray.direct = normalization(dir);
	return (ray);
}

int	check_shadow(t_info *info, t_vect hit_point, t_vect normal)
{
	t_vect	light_dir;
	t_ray	shadow_ray;
	float	light_dist;

	light_dir = sub_vect(info->light.posit, hit_point);
	light_dist = magnaitude(light_dir);
	shadow_ray = create_shadow_ray(hit_point, info->light.posit, normal);
	if (shadow_sphere(info->sp, shadow_ray, light_dist))
		return (1);
	if (shadow_cylinder(info->cy, shadow_ray, light_dist))
		return (1);
	if (shadow_plane(info->pl, shadow_ray, light_dist))
		return (1);
	return (0);
}
