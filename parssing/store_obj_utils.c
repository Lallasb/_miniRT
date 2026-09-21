/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_obj_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:13:15 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 23:47:54 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	store_pl_info(t_pl *pl, char **sp_coord, char **sp_nrml_v, char **sp_color)
{
	pl->posit.x = ft_atof(sp_coord[0]);
	pl->posit.y = ft_atof(sp_coord[1]);
	pl->posit.z = ft_atof(sp_coord[2]);
	pl->normal_v.x = ft_atof(sp_nrml_v[0]);
	pl->normal_v.y = ft_atof(sp_nrml_v[1]);
	pl->normal_v.z = ft_atof(sp_nrml_v[2]);
	pl->color.r = ft_atoi(sp_color[0]);
	pl->color.g = ft_atoi(sp_color[1]);
	pl->color.b = ft_atoi(sp_color[2]);
	if (pl->posit.x == UN || pl->posit.y == UN || pl->posit.z == UN
		|| pl->normal_v.x == UN || pl->normal_v.y == UN || pl->normal_v.z == UN)
		return (1);
	return (0);
}

int	store_cy_info(t_cy *cy, char **sp_coord, char **sp_nrml_v, char **sp_color)
{
	cy->center.x = ft_atof(sp_coord[0]);
	cy->center.y = ft_atof(sp_coord[1]);
	cy->center.z = ft_atof(sp_coord[2]);
	cy->axis_v.x = ft_atof(sp_nrml_v[0]);
	cy->axis_v.y = ft_atof(sp_nrml_v[1]);
	cy->axis_v.z = ft_atof(sp_nrml_v[2]);
	cy->color.r = ft_atoi(sp_color[0]);
	cy->color.g = ft_atoi(sp_color[1]);
	cy->color.b = ft_atoi(sp_color[2]);
	if (cy->center.x == UN || cy->center.y == UN || cy->center.z == UN
		|| cy->axis_v.x == UN || cy->axis_v.y == UN || cy->axis_v.z == UN)
		return (1);
	return (0);
}

int	store_info_sp(t_sp *sp, char **sp_coord, char **sp_color)
{
	sp->center.x = ft_atof(sp_coord[0]);
	sp->center.y = ft_atof(sp_coord[1]);
	sp->center.z = ft_atof(sp_coord[2]);
	sp->color.r = ft_atoi(sp_color[0]);
	sp->color.g = ft_atoi(sp_color[1]);
	sp->color.b = ft_atoi(sp_color[2]);
	if (sp->center.x == UN || sp->center.y == UN || sp->center.z == UN)
		return (1);
	return (0);
}

t_pl	*new_pl_node(t_pl pl_)
{
	t_pl	*pl;

	pl = malloc(sizeof(t_pl));
	if (!pl)
		return (NULL);
	*pl = pl_;
	pl->next = NULL;
	return (pl);
}
