/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:45:53 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 05:09:24 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	valid_color_num(t_col color)
{
	int	err;

	err = 0;
	if (color.r > 255 || color.r < 0)
		err++ ;
	if (color.g > 255 || color.g < 0)
		err++ ;
	if (color.b > 255 || color.b < 0)
		err++ ;
	if (err)
		return (1);
	return (0);
}

int	texture_access(const char **file)
{
	t_txd	texture[4];
	int		err;
	int		i;
	int		j;

	err = 0;
	i = -1;
	j = -1;
	texture[NO] = get_texture("NO ", file);
	texture[SO] = get_texture("SO ", file);
	texture[WE] = get_texture("WE ", file);
	texture[EA] = get_texture("EA ", file);
	while (++i < 4)
	{
		if (!open_file(texture[i].path))
			err++ ;
	}
	while (++j < 4)
	{
		free(texture[j].direct);
		free(texture[j].path);
	}
	if (err)
		return (1);
	return (0);
}

int	len_texture(char *texture, const char **file)
{
	char	**tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	tmp = (char **)file;
	while (file[i])
	{
		if (!ft_strncmp(tmp[i], texture, ft_strlen(texture)))
			len++ ;
		i++ ;
	}
	if (len != 1)
		return (1);
	return (0);
}

int	dup_texture(const char **file)
{
	int	error;

	error = 0;
	error += len_texture("NO ", file);
	error += len_texture("SO ", file);
	error += len_texture("WE ", file);
	error += len_texture("EA ", file);
	error += len_texture("C ", file);
	error += len_texture("F ", file);
	return (error);
}

void	valid_texture(const char *path)
{
	char	**file;
	int		err_len;

	err_len = 0;
	file = get_file_fd(path);
	if (dup_texture((const char **)file))
		err_len++ ;
	if (texture_access((const char **)file))
		err_len++ ;
	if (valid_path_texture((const char **)file))
		err_len++ ;
	if (valid_color((const char **)file))
		err_len++ ;
	free_twod_str(file);
	file = NULL;
	if (err_len != 0)
		print_msg_err("texture incorrect");
	return ;
}
