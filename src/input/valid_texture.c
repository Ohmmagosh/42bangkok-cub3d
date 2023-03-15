/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:45:53 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/16 00:15:53 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

int dup_texture(const char **file)
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
		err_len++;
	free_twod_str(file);
	if (err_len != 0)
		print_msg_err("texture incorrect");
	return ;
}

