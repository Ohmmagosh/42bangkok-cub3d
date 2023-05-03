/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:28:09 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 05:13:41 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	len_empty_line(const char **map)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			len++;
		i++;
	}
	return (len);
}

int	*set_numspace_array(const char **map, int *retsize)
{
	int	*ret;
	int	len;
	int	i;
	int	j;

	j = 0;
	i = 0;
	len = len_empty_line(map);
	ret = init_array_int(len);
	while (map[i] && j < len)
	{
		if (is_empty_line(map[i]))
		{
			ret[j] = i;
			j++;
		}
		i++;
	}
	*(retsize) = len;
	return (ret);
}

char	**set_map_str(const char **map, int *num_space, int len)
{
	int		i;
	char	**ret;
	int		size;
	int		j;

	i = 0;
	j = 0;
	ret = NULL;
	size = (len_str_2d(map) - len + 1);
	ret = (char **)malloc(sizeof(char *) * (size));
	while (map[i] && j < size)
	{
		if (!is_inarray(num_space, i, len))
		{
			ret[j] = ft_strdup_nonl((char *)map[i]);
			j++ ;
		}
		i++;
	}
	ret[size - 1] = NULL;
	return (ret);
}

char	**clean_space(const char **map)
{
	int		*num_space;
	char	**ret;
	int		i;
	int		len;

	i = 0;
	len = 0;
	ret = NULL;
	num_space = set_numspace_array(map, &len);
	ret = set_map_str(map, num_space, len);
	free(num_space);
	return (ret);
}

t_map	set_map(const char *path)
{
	t_map	map;
	char	**file;
	char	**map_str;

	init_map_st(&map);
	file = get_file_fd(path);
	map_str = get_map((const char **)file);
	map.map = clean_space((const char **)map_str);
	map.tex = set_tex((const char **)file);
	free_twod_str(map_str);
	free_twod_str(file);
	map_str = NULL;
	file = NULL;
	return (map);
}
