/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:42:39 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/05 02:12:10 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	findxy_player(char **map, int mode)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (chrstr_player(map[i][j]))
			{
				if (mode == 0)
					return (j);
				else if (mode == 1)
					return (i);
			}
			j++ ;
		}
		i++ ;
	}
	return (-1);
}

int	findxy_minimap(char **map, int mode)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				if (mode == 0)
					return (j);
				else if (mode == 1)
					return (i);
			}
			j++ ;
		}
		i++ ;
	}
	return (-1);
}

t_vei	get_pos_spt(char **map, int mode)
{
	t_vei	vector_int;

	vector_int = (t_vei){0, 0};
	if (mode == 0)
	{
		vector_int.x = findxy_player(map, 0);
		vector_int.y = findxy_player(map, 1);
	}
	else if (mode == 1)
	{
		vector_int.x = findxy_minimap(map, 0);
		vector_int.y = findxy_minimap(map, 1);
	}
	return (vector_int);
}

t_vei	get_direction_player(char player)
{
	t_vei	ret;

	ret = (t_vei){0, 0};
	if (player == 'N')
		ret = (t_vei){0, -1};
	else if (player == 'E')
		ret = (t_vei){1, 0};
	else if (player == 'S')
		ret = (t_vei){0, 1};
	else if (player == 'W')
		ret = (t_vei){-1, 0};
	return (ret);
}

t_spt	set_spt(char **map)
{
	t_spt	spt;

	spt.pos = get_pos_spt(map, 0);
	spt.di = get_direction_player(map[spt.pos.y][spt.pos.x]);
	spt.cstart = map[spt.pos.y][spt.pos.x];
	map[spt.pos.y][spt.pos.x] = 'P';
	return (spt);
}

// N=270 E=0 S=90 W=180
