/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 07:34:48 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/18 12:07:41 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_info	*init_info(void)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (NULL);
	return (info);
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_mlx	*mx;

	if (ac != 2)
		return ((ft_putstr_fd("Error\n", 2), 1));
	if (W == 0 || H == 0)
		return ((ft_putstr_fd("Error\n", 2), 1));
	info = init_info();
	if (!info)
		return ((ft_putstr_fd("Error\n", 2), 1));
	if (read_file(av[1], &info))
		return ((ft_putstr_fd("Error\n", 2), 1));
	mx = malloc(sizeof(t_mlx));
	if (!mx)
		return ((ft_free_info(&info), ft_putstr_fd("Error\n", 2), 1));
	mx->name = av[1];
	mx->info = info;
	ft_init(mx);
	ft_put(mx, info);
	ft_evant(mx);
	mlx_loop(mx->mlx_c);
	return (0);
}
