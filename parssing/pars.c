/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 07:57:51 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/23 00:27:28 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	check_nb_arg(char **line, int m)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != m)
		return (1);
	return (0);
}

static int	pars_object(t_info **scene_inf, char **sp_line, int ***nobj)
{
	if (sp_line[0][0] == 's' && sp_line[0][1] == 'p')
	{
		if (check_nb_arg(sp_line, 4) || check_store_sp(sp_line, scene_inf))
			return (1);
		(***nobj)++;
	}
	else if (sp_line[0][0] == 'p' && sp_line[0][1] == 'l')
	{
		if (check_nb_arg(sp_line, 4) || check_store_pl(sp_line, scene_inf))
			return (1);
		(***nobj)++;
	}
	else if (sp_line[0][0] == 'c' && sp_line[0][1] == 'y')
	{
		if (check_nb_arg(sp_line, 6) || check_store_cy(sp_line, scene_inf))
			return (1);
		(***nobj)++;
	}
	return (0);
}

static int	pars_paramt(t_info **scene_inf, char **sp_line, int ***flag)
{
	if (sp_line[0][0] == 'A')
	{
		if (check_nb_arg(sp_line, 3) || check_store_a(sp_line, scene_inf))
			return (1);
		(***flag)++;
	}
	else if (sp_line[0][0] == 'C')
	{
		if (check_nb_arg(sp_line, 4) || check_stor_c(sp_line, scene_inf))
			return (1);
		(***flag)++;
	}
	else if (sp_line[0][0] == 'L')
	{
		if (check_nb_arg(sp_line, 4) || check_store_l(sp_line, scene_inf))
			return (1);
		(***flag)++;
	}
	return (0);
}

int	invalid_chr(char *str)
{
	if (!ft_strncmp(str, "A", ft_strlen(str)) || !ft_strncmp(str, "C",
			ft_strlen(str)) || !ft_strncmp(str, "L", ft_strlen(str))
		|| !ft_strncmp(str, "sp", ft_strlen(str)) || !ft_strncmp(str, "cy",
			ft_strlen(str)) || !ft_strncmp(str, "pl", ft_strlen(str)))
		return (0);
	return (1);
}

int	pars(char *line, t_info **scene_inf, int **flag, int **nobj)
{
	char	**sp_line;
	int		i;

	i = 0;
	if (!line)
		return (0);
	if (line[i] == '\0')
		return (0);
	while (*line && (*line == 32 || (*line <= 13 && *line >= 9)))
		line++;
	if (!*line)
		return (0);
	sp_line = NULL;
	line = ft_strtrim(line, "\n");
	sp_line = ft_split(line, ' ');
	free(line);
	if (!sp_line)
		return (1);
	if (invalid_chr(sp_line[0]) || pars_paramt(scene_inf, sp_line, &flag)
		|| pars_object(scene_inf, sp_line, &nobj))
		return ((ft_free_ptr_array(sp_line), 1));
	ft_free_ptr_array(sp_line);
	return (0);
}
