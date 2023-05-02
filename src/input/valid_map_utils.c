/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:23:03 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/01 22:01:31 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	len_token_one(const int *array, size_t size)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] >= 1)
			len++ ;
		i++ ;
	}
	if (len == 1)
		return (0);
	return (1);
}

int	len_map_token(char **map, char token)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == token)
				len++ ;
			j++ ;
		}
		i++ ;
	}
	return (len);
}

int	valid_map_char_dup(const char **file)
{
	int		err;
	char	**map;
	int		token[4];
	int		i;

	i = 0;
	err = 0;
	map = get_map(file);
	token[0] = len_map_token(map, 'N');
	token[1] = len_map_token(map, 'E');
	token[2] = len_map_token(map, 'W');
	token[3] = len_map_token(map, 'S');
	free_twod_str(map);
	map = NULL;
	while (i < 4)
	{
		if (token[i] > 1)
			err++ ;
		i++ ;
	}
	err += len_token_one(token, 4);
	if (err)
		return (1);
	return (0);
}

int	is_map_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'E' || \
		c == 'W' || c == 'S' || c == ' ' || c == 'D')
		return (1);
	return (0);
}

int	valid_map_char(const char **file)
{
	int		err;
	char	**map;
	int		i;
	int		j;

	err = 0;
	i = 0;
	map = get_map(file);
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (!is_map_char(map[i][j]))
				err++ ;
			j++ ;
		}
		i++ ;
	}
	free_twod_str(map);
	map = NULL;
	if (err)
		return (1);
	return (0);
}
