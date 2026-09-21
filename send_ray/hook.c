/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:43:56 by h-el-ahr          #+#    #+#             */
/*   Updated: 2026/01/17 14:47:42 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	ft_close(t_mlx *mx)
{
	mlx_destroy_image(mx->mlx_c, mx->img.imgs);
	mlx_destroy_window(mx->mlx_c, mx->mlx_w);
	mlx_destroy_display(mx->mlx_c);
	ft_free_info(&mx->info);
	free(mx->mlx_c);
	free(mx);
	exit(0);
}

static int	ft_key(int key, t_mlx *mx)
{
	if (key == 65307)
		ft_close(mx);
	return (0);
}

void	ft_evant(t_mlx *mx)
{
	mlx_key_hook(mx->mlx_w, ft_key, mx);
	mlx_hook(mx->mlx_w, 17, 0, ft_close, mx);
}
