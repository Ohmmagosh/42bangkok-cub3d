/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:56:35 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/05 02:12:51 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	msg_err(char *msg)
{
	ft_putstr_fd(BRED, 2);
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RES, 2);
	ft_putstr_fd("\n", 2);
	return ;
}

void	print_msg_err(char *msg)
{
	ft_putstr_fd(BRED, 2);
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RES, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
	return ;
}

int	leny_file(const char *path)
{
	int		len;
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_msg_err("file not found!!");
	len = 0;
	tmp = get_next_line(fd);
	len++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		len++;
	}
	close(fd);
	return (len);
}

char	**get_file_fd(const char *path)
{
	int		fd;
	char	**map;
	int		leny;
	int		i;

	i = 0;
	leny = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_msg_err("file not found!!");
	leny = leny_file(path);
	map = (char **)malloc(sizeof(char *) * (leny + 1));
	while (i <= leny)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
