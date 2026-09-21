/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h-el-ahr <h-el-ahr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:47:28 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/17 22:39:04 by h-el-ahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	ft_free_sp(t_sp **sp_top)
{
	t_sp	*sp;

	if (!sp_top || !*sp_top)
		return ;
	while ((*sp_top))
	{
		sp = (*sp_top)->next;
		free(*sp_top);
		*sp_top = sp;
	}
}

static void	ft_free_cy(t_cy **cy_top)
{
	t_cy	*cy;

	if (!cy_top || !*cy_top)
		return ;
	while ((*cy_top))
	{
		cy = (*cy_top)->next;
		free(*cy_top);
		*cy_top = cy;
	}
}

static void	ft_free_pl(t_pl **pl_top)
{
	t_pl	*pl;

	if (!pl_top || !*pl_top)
		return ;
	while ((*pl_top))
	{
		pl = (*pl_top)->next;
		free(*pl_top);
		*pl_top = pl;
	}
}

void	ft_free_ptr_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_info(t_info **info)
{
	if (!info || !*info)
		return ;
	ft_free_sp(&(*info)->sp);
	ft_free_cy(&(*info)->cy);
	ft_free_pl(&(*info)->pl);
	free(*info);
}
