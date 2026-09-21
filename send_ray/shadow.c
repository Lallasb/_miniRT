/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:50 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/17 22:44:58 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static float	compute_lambert(t_ray ray, t_hit hit, t_info *info, t_vect *p)
{
	t_vect	light_dir;
	float	lambert;

	*p = add_vect(ray.origine, scalar(ray.direct, hit.t));
	light_dir = sub_vect(info->light.posit, *p);
	light_dir = normalization(light_dir);
	lambert = dot(hit.normal, light_dir);
	if (lambert < 0)
		lambert = 0;
	return (lambert);
}

static void	ambient_color(t_info *info, t_hit hit, t_fcolor *c)
{
	c->r = (hit.color.r / 255.0) * (info->ambient.color.r / 255.0)
		* info->ambient.ratio;
	c->g = (hit.color.g / 255.0) * (info->ambient.color.g / 255.0)
		* info->ambient.ratio;
	c->b = (hit.color.b / 255.0) * (info->ambient.color.b / 255.0)
		* info->ambient.ratio;
}

static void	add_light(t_info *info, t_hit hit, float lambert, t_fcolor *c)
{
	c->r += (hit.color.r / 255.0) * (info->light.color.r / 255.0)
		* info->light.ratio * lambert;
	c->g += (hit.color.g / 255.0) * (info->light.color.g / 255.0)
		* info->light.ratio * lambert;
	c->b += (hit.color.b / 255.0) * (info->light.color.b / 255.0)
		* info->light.ratio * lambert;
}

t_color	shdow(t_ray ray, t_info *info, t_hit hit)
{
	t_vect		hit_point;
	t_fcolor	fc;
	t_color		out;
	float		lambert;

	lambert = compute_lambert(ray, hit, info, &hit_point);
	ambient_color(info, hit, &fc);
	if (!check_shadow(info, hit_point, hit.normal))
		add_light(info, hit, lambert, &fc);
	out.r = (int)(fc.r * 255);
	out.g = (int)(fc.g * 255);
	out.b = (int)(fc.b * 255);
	return (out);
}
