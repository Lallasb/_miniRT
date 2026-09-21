/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:07:38 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/18 00:46:16 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		len(char *str);
char	*ft_strdup_g(char *str);
char	*ft_strjoin_g(char *rest, char *rd);
char	*ft_strch(char *rest, char nl);
char	*ft_substr_g(char *rest, int start, int ln);
void	save_ptr(char *ptr, int flag);

#endif
