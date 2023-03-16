/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:54:54 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/17 01:13:50 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

char	**get_texture_2d(char *texture, const char **file)
{
	int		i;
	char	**tmp;
	char	**ret;

	i = 0;
	tmp = (char **)file;
	while (tmp[i])
	{
		if (!ft_strncmp(tmp[i], texture, ft_strlen(texture)))
		{
			ret = ft_split(tmp[i], ' ');
			break ;
		}
		i++ ;
	}
	return (ret);
}

t_txd	get_texture(char *texture, const char **file)
{
	char	**tmp;
	t_txd	tdetail;
	int		i;

	i = 0;
	tmp = (char **)file;
	while (tmp[i])
	{
		if (!ft_strncmp(texture, tmp[i], ft_strlen(texture)))
			tdetail = split_texture_path(tmp[i]);
		i++;
	}
	return (tdetail);
}

t_txd	split_texture_path(char *texture)
{
	t_txd	tdetail;
	char	**split;

	split = NULL;
	tdetail = init_t_txd();
	split = ft_split(texture, ' ');
	tdetail.direct = ft_strdup(split[0]);
	tdetail.path = ft_strdup_nonl(split[1]);
	free_twod_str(split);
	return (tdetail);
}

int	valid_path_texture(const char **file)
{
	char	***texture;
	int		i;
	int		err;

	i = 0;
	err = 0;
	texture = (char ***)malloc((sizeof(char **) * (6)));
	texture[NO] = get_texture_2d("NO ", file);
	texture[SO] = get_texture_2d("SO ", file);
	texture[WE] = get_texture_2d("WE ", file);
	texture[EA] = get_texture_2d("EA ", file);
	texture[F] = get_texture_2d("F ", file);
	texture[C] = get_texture_2d("C ", file);
	texture[6] = NULL;
	while (texture[i])
	{
		if (len_str_2d((const char **)texture[i]) != 2)
			err++;
		i++;
	}
	free_threed_str(texture);
	texture = NULL;
	if (err)
		return (1);
	return (0);
}
