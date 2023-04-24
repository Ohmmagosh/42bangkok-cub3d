/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:26:45 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/25 01:18:57 by rchiewli         ###   ########.fr       */
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
	t_vei	player;

	if (key == 53)
	{
		mlx_clear_window(p->mlx.mlx, p->mlx.win);
		exit(0);
	}
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	player = get_pos_spt(p->map.map, 1);
	if (key == 13)
	{
		player_move(player, p->map.map, 0);
		p->tline.pos.y -= 0.1;
	}
	else if (key == 0)
	{
		player_move(player, p->map.map, 1);
		p->tline.pos.x -= 0.1;
	}
	else if (key == 2)
	{
		player_move(player, p->map.map, 2);
		p->tline.pos.x += 0.1;
	}
	else if (key == 1)
	{
		player_move(player, p->map.map, 3);
		p->tline.pos.y += 0.1;
	}
	lode_start(p);
	draw_minimap(p);
	// mlx_destroy_image(p->mlx.mlx, p->mlx.win);
	return (0);
}

void	key_hook(t_pro *p)
{
	// mlx_key_hook(p->mlx.win, hook, p);
	mlx_hook(p->mlx.win, 2, 1L<<0, hook, p);
	return ;
}



