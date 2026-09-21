/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:13:56 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 23:19:30 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	loop_check_num(char **sp_coord, char **sp_color, char **sp_nrml_v)
{
	int	i;

	i = 0;
	if (!sp_nrml_v)
	{
		while (sp_coord[i] && sp_color[i])
		{
			if (!check_num(sp_coord[i]) && !check_num(sp_color[i]))
				i++;
			else
				break ;
		}
		return (i);
	}
	while (sp_coord[i] && sp_color[i] && sp_nrml_v[i])
	{
		if (!check_num(sp_coord[i]) && !check_num(sp_color[i])
			&& !check_num(sp_nrml_v[i]))
			i++;
		else
			break ;
	}
	return (i);
}

int	check_store_sp(char **sp_line, t_info **scene_inf)
{
	char	**sp_coord;
	char	**sp_color;
	t_sp	sp;

	sp_coord = ft_split(sp_line[1], ',');
	sp_color = ft_split(sp_line[3], ',');
	if (!sp_coord || !sp_color
		|| check_nb_arg(sp_coord, 3)
		|| check_nb_arg(sp_color, 3))
	{
		ft_free_ptr_array(sp_coord);
		ft_free_ptr_array(sp_color);
		return (1);
	}
	if (loop_check_num(sp_coord, sp_color, NULL) != 3)
		return ((ft_free_ptr_array(sp_color), ft_free_ptr_array(sp_coord), 1));
	if (store_info_sp(&sp, sp_coord, sp_color))
		return ((ft_free_ptr_array(sp_color), ft_free_ptr_array(sp_coord), 1));
	sp.ray = ft_atof(sp_line[2]) / 2;
	if (check_color(sp.color.r, sp.color.g, sp.color.b) || sp.ray == UN / 2)
		return ((ft_free_ptr_array(sp_color), ft_free_ptr_array(sp_coord), 1));
	add_back_sp(scene_inf, sp);
	ft_free_ptr_array(sp_color);
	ft_free_ptr_array(sp_coord);
	return (0);
}

static int	cleanup(char **sp_color, char **sp_coord, char **sp_nrml_v)
{
	ft_free_ptr_array(sp_color);
	ft_free_ptr_array(sp_coord);
	ft_free_ptr_array(sp_nrml_v);
	return (1);
}

int	check_store_pl(char **sp_line, t_info **scene_inf)
{
	char	**sp_coord;
	char	**sp_color;
	char	**sp_nrml_v;
	t_pl	pl;

	sp_coord = ft_split(sp_line[1], ',');
	sp_nrml_v = ft_split(sp_line[2], ',');
	sp_color = ft_split(sp_line[3], ',');
	if (!sp_coord || !sp_color || !sp_nrml_v || check_nb_arg(sp_coord, 3)
		|| check_nb_arg(sp_nrml_v, 3) || check_nb_arg(sp_color, 3))
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	if (loop_check_num(sp_coord, sp_color, sp_nrml_v) != 3)
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	if (store_pl_info(&pl, sp_coord, sp_nrml_v, sp_color))
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	if (check_color(pl.color.r, pl.color.g, pl.color.b)
		|| check_coord(pl.normal_v.x, pl.normal_v.y, pl.normal_v.z))
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	add_back_pl(scene_inf, pl);
	cleanup(sp_color, sp_coord, sp_nrml_v);
	return (0);
}

int	check_store_cy(char **sp_line, t_info **scene_inf)
{
	char	**sp_coord;
	char	**sp_color;
	char	**sp_nrml_v;
	t_cy	cy;

	sp_coord = ft_split(sp_line[1], ',');
	sp_nrml_v = ft_split(sp_line[2], ',');
	sp_color = ft_split(sp_line[5], ',');
	if (!sp_coord || !sp_color || !sp_nrml_v || check_nb_arg(sp_coord, 3)
		|| check_nb_arg(sp_nrml_v, 3) || check_nb_arg(sp_color, 3))
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	if (loop_check_num(sp_coord, sp_color, sp_nrml_v) != 3)
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	if (store_cy_info(&cy, sp_coord, sp_nrml_v, sp_color))
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	if (check_color(cy.color.r, cy.color.g, cy.color.b)
		|| check_coord(cy.axis_v.x, cy.axis_v.y, cy.axis_v.z))
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	cy.ray = ft_atof(sp_line[3]) / 2;
	cy.height = ft_atof(sp_line[4]);
	if (cy.ray == UN / 2 || cy.height == UN)
		return (cleanup(sp_color, sp_coord, sp_nrml_v));
	add_back_cy(scene_inf, cy);
	cleanup(sp_color, sp_coord, sp_nrml_v);
	return (0);
}
