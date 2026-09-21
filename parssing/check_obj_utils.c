/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_obj_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:09:49 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/17 22:35:29 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	add_back_sp(t_info **scene_inf, t_sp sp)
{
	t_sp	*tmp;

	tmp = (*scene_inf)->sp;
	if ((*scene_inf)->sp)
	{
		while ((*scene_inf)->sp->next)
			(*scene_inf)->sp = (*scene_inf)->sp->next;
		(*scene_inf)->sp->next = new_sp_node(sp);
		(*scene_inf)->sp = tmp;
	}
	else
		(*scene_inf)->sp = new_sp_node(sp);
}

void	add_back_pl(t_info **scene_inf, t_pl pl)
{
	t_pl	*tmp;

	tmp = (*scene_inf)->pl;
	if ((*scene_inf)->pl)
	{
		while ((*scene_inf)->pl->next)
			(*scene_inf)->pl = (*scene_inf)->pl->next;
		(*scene_inf)->pl->next = new_pl_node(pl);
		(*scene_inf)->pl = tmp;
	}
	else
		(*scene_inf)->pl = new_pl_node(pl);
}

void	add_back_cy(t_info **scene_inf, t_cy cy)
{
	t_cy	*tmp;

	tmp = (*scene_inf)->cy;
	if ((*scene_inf)->cy)
	{
		while ((*scene_inf)->cy->next)
			(*scene_inf)->cy = (*scene_inf)->cy->next;
		(*scene_inf)->cy->next = new_cy_node(cy);
		(*scene_inf)->cy = tmp;
	}
	else
		(*scene_inf)->cy = new_cy_node(cy);
}

t_sp	*new_sp_node(t_sp sp_)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	if (!sp)
		return (NULL);
	*sp = sp_;
	sp->next = NULL;
	return (sp);
}

t_cy	*new_cy_node(t_cy cy_)
{
	t_cy	*cy;

	cy = malloc(sizeof(t_cy));
	if (!cy)
		return (NULL);
	*cy = cy_;
	cy->next = NULL;
	return (cy);
}
