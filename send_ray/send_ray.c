/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:06:04 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/17 22:42:46 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vect	find_pxel_in_view_port(float x, float y, t_info *info)
{
	t_vect	pixel_to_3d;
	float	ratio;
	float	half_h;

	half_h = tanf((info->camera.fov / 2) * (M_PI / 180.0));
	ratio = (float)W / (float)H;
	x = (x + 0.5f) / (float)(W);
	y = (y + 0.5f) / (float)(H);
	pixel_to_3d.x = ((x * 2) - 1) * ratio * half_h;
	pixel_to_3d.y = ((y * 2) - 1) * half_h * -1;
	pixel_to_3d.z = -1;
	return (pixel_to_3d);
}

t_coord	find_camera_coord(t_camera camera)
{
	t_coord	coord;
	t_vect	world_v;

	world_v.x = 0;
	world_v.y = 1;
	world_v.z = 0;
	coord.forward = normalization(camera.forward);
	coord.right = cross(coord.forward, world_v);
	if (magnaitude(coord.right) < 0.0001)
	{
		world_v.x = 0;
		world_v.y = 0;
		world_v.z = 1;
		coord.right = cross(world_v, coord.forward);
	}
	coord.right = normalization(coord.right);
	coord.up = cross(coord.right, coord.forward);
	coord.up = normalization(coord.up);
	return (coord);
}

t_ray	send_ray(float x, float y, t_info *info)
{
	t_ray	ray;
	t_vect	px_pos;
	t_coord	camera_coord;

	px_pos = find_pxel_in_view_port(x, y, info);
	camera_coord = find_camera_coord(info->camera);
	ray.direct = add_vect(add_vect(scalar(camera_coord.right, px_pos.x),
				scalar(camera_coord.up, px_pos.y)), camera_coord.forward);
	ray.origine = info->camera.posit;
	ray.direct = normalization(ray.direct);
	return (ray);
}
