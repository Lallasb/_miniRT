/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:44:27 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/17 14:48:23 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	ft_init(t_mlx *mx)
{
	mx->mlx_c = mlx_init();
	if (mx->mlx_c == NULL)
		exit((ft_free_info(&mx->info), free(mx), 1));
	mx->mlx_w = mlx_new_window(mx->mlx_c, W, H, mx->name);
	if (mx->mlx_w == NULL)
	{
		ft_free_info(&mx->info);
		mlx_destroy_display(mx->mlx_c);
		free(mx->mlx_c);
		free(mx);
		exit(1);
	}
	mx->img.imgs = mlx_new_image(mx->mlx_c, W, H);
	if (mx->img.imgs == NULL)
	{
		ft_free_info(&mx->info);
		mlx_destroy_window(mx->mlx_c, mx->mlx_w);
		mlx_destroy_display(mx->mlx_c);
		free(mx->mlx_c);
		free(mx);
		exit(1);
	}
	mx->img.pixel = mlx_get_data_addr(mx->img.imgs, &mx->img.bp,
			&mx->img.line_len, &mx->img.endian);
}
