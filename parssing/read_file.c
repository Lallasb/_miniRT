/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:50:15 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/18 13:29:46 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

static int	check_file_name(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	if (ft_strlen(str) <= 3)
		return (1);
	if (str[ft_strlen(str) - 3] != '.' || str[ft_strlen(str) - 2] != 'r'
		|| str[ft_strlen(str) - 1] != 't')
		return (1);
	return (0);
}

static int	ft_read(int fd, t_info **scene_info, int *flag, int *nobj)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (pars(line, scene_info, &flag, &nobj))
		{
			save_ptr(NULL, 1);
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	read_file(char *file, t_info **scene_info)
{
	int	fd;
	int	flag;
	int	nobj;

	flag = 0;
	nobj = 0;
	if (check_file_name(file))
	{
		ft_free_info(scene_info);
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((ft_free_info(scene_info), 1));
	if (ft_read(fd, scene_info, &flag, &nobj))
		return ((close(fd), ft_free_info(scene_info), 1));
	close(fd);
	if (flag != 3 || nobj < 1)
		return ((ft_free_info(scene_info), 1));
	return (0);
}
