/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:26:45 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/27 22:13:56 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	player_move_utils(t_vei current, t_vei new, char **map)
{
	map[current.y][current.x] = '0';
	map[new.y][new.x] = 'P';
}

int	is_valid_move(char map)
{
	if (map == '\0' || map == 0)
		return (0);
	if (map == '0')
		return (1);
	return (0);
}

void	player_move(t_vei pos, char **map, int mode)
{
	if (mode == 0)
	{
		if (is_valid_move(map[pos.y - 1][pos.x]))
			player_move_utils(pos, (t_vei){pos.x, pos.y - 1}, map);
	}
	else if (mode == 1)
	{
		if (is_valid_move(map[pos.y][pos.x -1]))
			player_move_utils(pos, (t_vei){pos.x - 1, pos.y }, map);
	}
	else if (mode == 2)
	{
		if (is_valid_move(map[pos.y][pos.x + 1]))
			player_move_utils(pos, (t_vei){pos.x + 1, pos.y}, map);
	}
	else if (mode == 3)
	{
		if (is_valid_move(map[pos.y + 1][pos.x]))
			player_move_utils(pos, (t_vei){pos.x, pos.y + 1}, map);
	}
}

int	hook(int key, t_pro *p)
{
	float		step = 0.15;

	if (key == 53)
	{
		mlx_clear_window(p->mlx.mlx, p->mlx.win);
		exit(0);
	}
	if (key == 13)
	{
		if(p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x + p->di.x * step)] != '1')
			p->tline.pos.x += p->di.x * step;
		if(p->map.map[(int)(p->tline.pos.y + p->di.y * step)][(int)(p->tline.pos.x)] != '1')
			p->tline.pos.y += p->di.y * step;
	}
	else if (key == 0)
	{
		if (p->map.map[(int)(p->tline.pos.y - p->di.x * step)][(int)(p->tline.pos.x + p->di.y * step)] != '1')
		{
			p->tline.pos.x += p->di.y * step;
			p->tline.pos.y += -p->di.x * step;
		}
	}
	else if (key == 2)
	{
		if (p->map.map[(int)(p->tline.pos.y + p->di.x * step)][(int)(p->tline.pos.x - p->di.y * step)] != '1')
		{
			p->tline.pos.x += -p->di.y * step;
			p->tline.pos.y += p->di.x * step;
		}
	}
	else if (key == 1)
	{
		if(p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x - p->di.x * step)] != '1')
			p->tline.pos.x -= p->di.x * step;
		if(p->map.map[(int)(p->tline.pos.y - p->di.y * step)][(int)(p->tline.pos.x)] != '1')
			p->tline.pos.y -= p->di.y * step;
	}
	if (key == 123)
		rotate_hook(-5.0, p);
	else if (key == 124)
		rotate_hook(5.0, p);
	player_move(p->map.map, 1);
	return (0);
}

void	key_hook(t_pro *p)
{
	// mlx_key_hook(p->mlx.win, hook, p);
	mlx_hook(p->mlx.win, 2, 1L<<0, hook, p);
	return ;
}



