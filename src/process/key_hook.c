/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:26:45 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/05 03:20:31 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	getdoorpos(int x, int y, t_pro *p)
{
	if (p->map.map[y][x] == 'D' && p->tline.doorflag == 0)
	{
		p->map.map[y][x] = '0';
		p->tline.doorpos = (t_vei){x, y};
		p->tline.doorflag = 1;
	}
	else if (p->map.map[y][x] == '0' && p->tline.doorflag == 1)
	{
		if (p->tline.doorpos.y == (int)p->tline.pos.y && \
				p->tline.doorpos.x == (int)p->tline.pos.x)
			return ;
		p->map.map[p->tline.doorpos.y][p->tline.doorpos.x] = 'D';
		p->tline.doorflag = 0;
		p->tline.doorpos = (t_vei){-1, -1};
	}
	return ;
}

void	player_move(t_pro *p)
{
	t_vei	pos;

	pos = get_pos_spt(p->map.map, 1);
	p->map.map[pos.y][pos.x] = '0';
	p->map.map[(int)p->tline.pos.y][(int)p->tline.pos.x] = 'P';
	return ;
}

int	hook(int key, t_pro *p)
{
	float	step;

	step = 0.2;
	if (key == 53)
		close_win(p);
	if (key == 3)
		key_3(p, step);
	else if (key == 13)
		key_13(p, step);
	else if (key == 0 || key == 2)
		key_0_or_2(p, step, key);
	else if (key == 1)
		key_1(p, step);
	if (key == 123)
		rotate_hook(-5.0, p);
	else if (key == 124)
		rotate_hook(5.0, p);
	player_move(p);
	return (0);
}

void	key_hook(t_pro *p)
{
	mlx_hook (p->mlx.win, 2, 1L << 0, hook, p);
	mlx_hook (p->mlx.win, 17, 1L << 0, close_win, p);
	mlx_mouse_hook(p->mlx.win, mouse_hook, p);
	return ;
}
