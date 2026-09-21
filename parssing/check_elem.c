/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:06:38 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 22:08:29 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_store_a(char **sp_line, t_info **scene_inf)
{
	char		**sp_clor;
	static int	rep = 0;

	sp_clor = NULL;
	if (rep == 1 || !ft_strchr(sp_line[2], ','))
		return (1);
	rep += 1;
	sp_clor = ft_split(sp_line[2], ',');
	if (!sp_clor)
		return (1);
	if (check_nb_arg(sp_clor, 3) || store_ambient(sp_clor, scene_inf, sp_line))
	{
		ft_free_ptr_array(sp_clor);
		return (1);
	}
	return (0);
}

int	check_stor_c(char **sp_line, t_info **scene_inf)
{
	char		**sp_coord;
	char		**sp_n_v;
	static int	rep = 0;

	if (rep == 1 || check_num(sp_line[3]))
		return (1);
	rep += 1;
	(*scene_inf)->camera.fov = ft_atoi(sp_line[3]);
	if ((*scene_inf)->camera.fov > 180 || (*scene_inf)->camera.fov <= 0)
		return (1);
	sp_coord = ft_split(sp_line[1], ',');
	sp_n_v = ft_split(sp_line[2], ',');
	if (!sp_coord || !sp_n_v
		|| check_nb_arg(sp_coord, 3) || check_nb_arg(sp_n_v, 3))
	{
		ft_free_ptr_array(sp_coord);
		ft_free_ptr_array(sp_n_v);
		return (1);
	}
	if (stor_camera(sp_n_v, sp_coord, scene_inf))
		return ((ft_free_ptr_array(sp_n_v), ft_free_ptr_array(sp_coord), 1));
	return (0);
}

int	check_store_l(char **sp_line, t_info **scene_inf)
{
	char		**sp_light_p;
	char		**sp_color;
	static int	rep = 0;

	if (rep == 1)
		return (1);
	rep += 1;
	sp_light_p = ft_split(sp_line[1], ',');
	sp_color = ft_split(sp_line[3], ',');
	if (!sp_light_p || !sp_color
		|| check_nb_arg(sp_light_p, 3) || check_nb_arg(sp_color, 3))
	{
		ft_free_ptr_array(sp_light_p);
		ft_free_ptr_array(sp_color);
		return (1);
	}
	if (store_light(sp_light_p, sp_color, scene_inf, sp_line))
	{
		ft_free_ptr_array(sp_light_p);
		ft_free_ptr_array(sp_color);
		return (1);
	}
	return (0);
}
