/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_elem_uils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:17:35 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 23:23:10 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	store_light_info(char **sp_light_p, char **sp_color, t_info **scene_inf)
{
	(*scene_inf)->light.posit.x = ft_atof(sp_light_p[0]);
	(*scene_inf)->light.posit.y = ft_atof(sp_light_p[1]);
	(*scene_inf)->light.posit.z = ft_atof(sp_light_p[2]);
	(*scene_inf)->light.color.r = ft_atoi(sp_color[0]);
	(*scene_inf)->light.color.g = ft_atoi(sp_color[1]);
	(*scene_inf)->light.color.b = ft_atoi(sp_color[2]);
	if ((*scene_inf)->light.posit.x == UN || (*scene_inf)->light.posit.y == UN
		|| (*scene_inf)->light.posit.z == UN
		|| check_color((*scene_inf)->light.color.r,
			(*scene_inf)->light.color.g, (*scene_inf)->light.color.b))
		return (1);
	return (0);
}

int	store_camera_info(t_info **scene_inf, char **sp_coord, char **sp_n_v)
{
	(*scene_inf)->camera.posit.x = ft_atof(sp_coord[0]);
	(*scene_inf)->camera.posit.y = ft_atof(sp_coord[1]);
	(*scene_inf)->camera.posit.z = ft_atof(sp_coord[2]);
	(*scene_inf)->camera.forward.x = ft_atof(sp_n_v[0]);
	(*scene_inf)->camera.forward.y = ft_atof(sp_n_v[1]);
	(*scene_inf)->camera.forward.z = ft_atof(sp_n_v[2]);
	if ((*scene_inf)->camera.posit.x == UN || (*scene_inf)->camera.posit.y == UN
		|| (*scene_inf)->camera.posit.z == UN
		|| (*scene_inf)->camera.forward.x == UN
		|| (*scene_inf)->camera.forward.y == UN
		|| (*scene_inf)->camera.forward.z == UN)
		return (1);
	return (0);
}

int	store_ambient(char **sp_clor, t_info **scene_inf, char **sp_line)
{
	(*scene_inf)->ambient.ratio = ft_atof(sp_line[1]);
	if ((*scene_inf)->ambient.ratio > 1.0 || (*scene_inf)->ambient.ratio < 0.0)
		return (1);
	(*scene_inf)->ambient.color.r = ft_atoi(sp_clor[0]);
	(*scene_inf)->ambient.color.g = ft_atoi(sp_clor[1]);
	(*scene_inf)->ambient.color.b = ft_atoi(sp_clor[2]);
	if (check_color((*scene_inf)->ambient.color.r,
			(*scene_inf)->ambient.color.g, (*scene_inf)->ambient.color.b))
		return (1);
	ft_free_ptr_array(sp_clor);
	return (0);
}

int	stor_camera(char **sp_n_v, char **sp_coord, t_info **scene_inf)
{
	int	i;

	i = 0;
	while (sp_coord[i] && sp_n_v[i])
	{
		if (!check_num(sp_coord[i]) && !check_num(sp_n_v[i]))
			i++;
		else
			break ;
	}
	if (i != 3)
		return (1);
	if (store_camera_info(scene_inf, sp_coord, sp_n_v))
		return (1);
	if (check_coord((*scene_inf)->camera.forward.x,
			(*scene_inf)->camera.forward.y, (*scene_inf)->camera.forward.z))
		return (1);
	ft_free_ptr_array(sp_n_v);
	ft_free_ptr_array(sp_coord);
	return (0);
}

int	store_light(char **sp_light_p, char **sp_color, t_info **inf,
		char **sp_line)
{
	int	i;

	i = 0;
	while (sp_light_p[i] && sp_color[i])
	{
		if (!check_num(sp_light_p[i]) && !check_num(sp_color[i]))
			i++;
		else
			break ;
	}
	if (i != 3)
		return (1);
	if (store_light_info(sp_light_p, sp_color, inf) || check_num(sp_line[2]))
		return (1);
	(*inf)->light.ratio = ft_atof(sp_line[2]);
	if ((*inf)->light.ratio > 1.0 || (*inf)->light.ratio < 0.0)
		return (1);
	ft_free_ptr_array(sp_light_p);
	ft_free_ptr_array(sp_color);
	return (0);
}
