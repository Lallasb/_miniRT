/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:35 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/19 06:29:59 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || W <= x || y < 0 || H <= y)
		return ;
	dst = img->pixel + (y * img->line_len + x * (img->bp / 8));
	*(unsigned int *)dst = color;
}

static int	valid_rgb(int r, int g, int b)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}

static void	ft_pixl(int x, int y, t_mlx *mx, t_info *info)
{
	t_ray	ray;
	t_hit	hit;

	ray = send_ray(x, y, info);
	hit.t = INFINITY;
	mx->color = 0x000000;
	check_objects(info, ray, &hit);
	if (hit.t != INFINITY)
	{
		hit.color = shdow(ray, info, hit);
		mx->color = valid_rgb(hit.color.r, hit.color.g, hit.color.b);
	}
	pixel_put(&mx->img, x, y, mx->color);
}

void	ft_put(t_mlx *mx, t_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			ft_pixl(x, y, mx, info);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mx->mlx_c, mx->mlx_w, mx->img.imgs, 0, 0);
}
