/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:11 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/15 14:53:49 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	hit_sphere(t_sp *sp, t_ray ray, t_hit *hit)
{
	t_vect	p_interc;

	while (sp)
	{
		sp->t = sphere(*sp, ray);
		if (sp->t > 0 && sp->t < hit->t)
		{
			hit->t = sp->t;
			p_interc = ray_equation(ray.origine, ray.direct, hit->t);
			hit->normal = get_sphere_normal(*sp, p_interc);
			hit->color = sp->color;
		}
		sp = sp->next;
	}
}

static void	hit_cylinder(t_cy *cy, t_ray ray, t_hit *hit)
{
	t_vect	p;

	while (cy)
	{
		cy->t = check_cy_inters(cy, ray);
		if (cy->t > 0 && cy->t < hit->t)
		{
			hit->t = cy->t;
			p = ray_equation(ray.origine, ray.direct, hit->t);
			hit->normal = get_cylinder_normal(*cy, p);
			hit->color = cy->color;
		}
		cy = cy->next;
	}
}

static void	hit_plane(t_pl *pl, t_ray ray, t_hit *hit)
{
	while (pl)
	{
		pl->t = plan(*pl, ray);
		if (pl->t > 0 && pl->t < hit->t)
		{
			hit->t = pl->t;
			hit->normal = get_plane_normal(*pl);
			hit->color = pl->color;
		}
		pl = pl->next;
	}
}

void	check_objects(t_info *info, t_ray ray, t_hit *hit)
{
	hit_sphere(info->sp, ray, hit);
	hit_cylinder(info->cy, ray, hit);
	hit_plane(info->pl, ray, hit);
}
