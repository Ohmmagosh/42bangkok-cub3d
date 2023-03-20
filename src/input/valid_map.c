/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:16:37 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/18 03:19:35 by psuanpro         ###   ########.fr       */
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
		return (NULL);
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

void	valid_map(const char *path)
{
	char	**file;
	int		err_len;
	char	**map;

	err_len = 0;
	file = get_file_fd(path);
	if (valid_map_char((const char **)file))
		err_len++ ;
	if (valid_map_char_dup((const char **)file))
		err_len++ ;
	free_twod_str(file);
	file = NULL;
	if (err_len != 0)
		print_msg_err("map incorrect");
	return ;
}
