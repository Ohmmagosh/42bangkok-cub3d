/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:26:45 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 02:05:39 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	player_move(t_pro *p)
{
	t_vei	pos;

	pos = get_pos_spt(p->map.map, 1);
	p->map.map[pos.y][pos.x] = '0';
	p->map.map[(int)p->tline.pos.y][(int)p->tline.pos.x] = 'P';
}

int	hook(int key, t_pro *p)
{
	float		step = 0.2;

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
		// player_move(p);
	}
	if (key == 123)
		rotate_hook(-5.0, p);
	else if (key == 124)
		rotate_hook(5.0, p);
	player_move(p);
	return (0);
}

void	key_hook(t_pro *p)
{
	// mlx_key_hook(p->mlx.win, hook, p);
	mlx_hook(p->mlx.win, 2, 1L<<0, hook, p);
	return ;
}



