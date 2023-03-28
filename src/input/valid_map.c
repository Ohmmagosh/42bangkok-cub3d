/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:16:37 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/27 01:44:56 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	find_str_line(char *texture, const char **file)
{
	int		len;
	char	**tmp;

	len = 0;
	tmp = (char **)file;
	while (tmp[len])
	{
		if (!ft_strncmp(tmp[len], texture, ft_strlen(texture)))
			break;
		len++ ;
	}
	return (len);
}

int	*is_direction_col(const char **file)
{
	int	*direct_color;

	direct_color = (int *)malloc(sizeof(int) * 6);
	if (!direct_color)
		return (0);
	direct_color[0] = find_str_line("NO ", file);
	direct_color[1] = find_str_line("SO ", file);
	direct_color[2] = find_str_line("WE ", file);
	direct_color[3] = find_str_line("EA ", file);
	direct_color[4] = find_str_line("F ", file);
	direct_color[5] = find_str_line("C ", file);
	return (direct_color);
}

char	**get_map(const char **file)
{
	char	**ret;
	int		*di_col;
	int		i;
	int		copy;

	i = 0;
	copy = 0;
	di_col = is_direction_col(file);
	ret = (char **)malloc(sizeof(char *) * (len_str_2d(file) - 5));
	if (!ret)
		return (NULL);
	while (file[i])
	{
		if (!is_inarray((const int *)di_col, i, 6))
		{
			ret[copy] = ft_strdup_nonl((char *)file[i]);
			copy++;
		}
		i++;
	}
	ret[copy] = NULL;
	return (ret);
}

int	find_pos_spt(char **map, int mode)
{
	int	y;
	int	x;
	int	status;

	status = 1;
	y = 0;
	while (map[y] && status)
	{
		x = 0;
		while (map[y][x])
		{
			if (chrstr_player(map[y][x]))
			{
				status = 0;
				break ;
			}
			x++;
		}
		if (status == 0)
			break;
		y++;
	}
	if (mode == 0)
		return (x);
	else if (mode == 1)
		return (y);
	return (-1);
}

int	flood_fill_check(char c)
{
	if (c == '0' || chrstr_player(c))
		return (1);
	return (0);
}

void	flood_fill(char **map, t_vei vec, t_vei size, int *err)
{
	if (!map)
		return ;
	if ( vec.x > size.x || vec.y > size.y)
		return ;
	if (map[vec.y][vec.x] == '\0' || map[vec.y][vec.x] == '\n' || \
		map[vec.y][vec.x] == ' ')
		(*err)++;
	if (!flood_fill_check(map[vec.y][vec.x]))
		return ;
	if (flood_fill_check(map[vec.y][vec.x]))
		map[vec.y][vec.x] = '1';
	map[vec.y][vec.y] = '1';
	flood_fill(map, (t_vei){vec.x - 1 , vec.y} ,size, err);
	flood_fill(map, (t_vei){vec.x , vec.y - 1} ,size, err);
	flood_fill(map, (t_vei){vec.x + 1 , vec.y} ,size, err);
	flood_fill(map, (t_vei){vec.x , vec.y + 1} ,size, err);
	return ;
}

int	len_max_y(char **map)
{
	int	y;

	y = 0;
	if (map || map[0] == NULL)
		return (0);
	while (map[y] && map[y] != (void *)NULL)
		y++ ;
	return (y);
}

int	len_max(char **map, int mode)
{
	if (!map)
		return (-1);
	if (mode == 0)
		return (strlen_no_nl(map[0]));
	else if (mode == 1)
		return (len_max_y(map));
	return (-1);
}

int	valid_flood_fill(char **map)
{
	int	err;
	t_vei	vec;
	t_vei	size;

	err = 0;
	vec.x = find_pos_spt(map, 0);
	vec.y = find_pos_spt(map, 1);
	size.x = len_max(map, 0);
	size.y = len_max(map, 1);
	flood_fill(map, vec, size, &err);
	if (err)
		return (1);
	return (0);
}

int	valid_map_wall(const char **file)
{
	int		err;
	char	**map_flood;
	char	**map_str;

	err = 0;
	map_flood = NULL;
	map_str = NULL;
	map_str = get_map(file);
	map_flood = clean_space((const char **)map_str);
	err = valid_flood_fill(map_flood);
	free_twod_str(map_str);
	free_twod_str(map_flood);
	//free(map_str);
	//free(map_flood);
	map_flood = NULL;
	map_str = NULL;
	if (err)
		return (1);
	return (0);
}

void	valid_map(const char *path)
{
	char	**file;
	int		err_len;

	err_len = 0;
	file = NULL;
	file = get_file_fd(path);
	if (valid_map_char((const char **)file))
		err_len++ ;
	if (valid_map_char_dup((const char **)file))
		err_len++ ;
	if (valid_map_wall((const char **)file))
		err_len++ ;
	if (valid_map_wall((const char **)file))
		err_len++ ;
	free_twod_str(file);
	//free(file);
	file = NULL;
	if (err_len != 0)
		print_msg_err("map incorrect");
	return ;
}
