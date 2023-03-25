/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:54:54 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/21 21:32:36 by psuanpro         ###   ########.fr       */
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
	ret = NULL;
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

char	***valid_path_texture3d(const char **file)
{
	char	***ret;
	int		i;

	i = 0;
	ret = NULL;
	ret = (char ***)malloc((sizeof(char **) * (7)));
	if (!ret)
		return (NULL);
	while (i < 7)
	{
		ret[i] = NULL;
		i++;
	}
	i = 0;
	ret[NO] = get_texture_2d("NO ", file);
	ret[SO] = get_texture_2d("SO ", file);
	ret[WE] = get_texture_2d("WE ", file);
	ret[EA] = get_texture_2d("EA ", file);
	ret[F] = get_texture_2d("F ", file);
	ret[C] = get_texture_2d("C ", file);
	return (ret);
}

int	valid_path_texture(const char **file)
{
	char	***texture;
	int		i;
	int		err;

	i = 0;
	err = 0;
	texture = valid_path_texture3d(file);
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
