/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:26:45 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 23:43:02 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_vei	getdoorpos(int x, int y, t_pro *p)
{
	printf("x -> %d\n", x);
	printf("y -> %d\n", y);
	if (p->map.map[y][x] == 'D' && p->tline.doorflag == 0)
	{
		p->map.map[y][x] = '0';
		p->tline.doorpos = (t_vei){x, y};
		p->tline.doorflag =  1;
	}
	// else if (x != p->tline.doorpos.x && y != p->tline.doorpos.y && p->tline.doorflag == 1)
	else if (p->map.map[y][x] == '0' && p->tline.doorflag == 1)
	{
		printf("hello\n");
		p->map.map[p->tline.doorpos.y][p->tline.doorpos.x] = 'D';
		p->tline.doorflag = 0;
		p->tline.doorpos = (t_vei){-1, -1};
	}
}

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

	printf("keycode %d\n", key);
	if (key == 53)
	{
		mlx_clear_window(p->mlx.mlx, p->mlx.win);
		exit(0);
	}
	if (key == 3)
	{
		if(p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x + p->di.x * (step * 4))] == 'D' || p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x + p->di.x * (step * 4))] == '0')
		{
			getdoorpos((int)(p->tline.pos.x + p->di.x * (step * 4)), (int)(p->tline.pos.y), p);
			printf("hello\n");
		}
		if(p->map.map[(int)(p->tline.pos.y + p->di.y * (step * 4))][(int)(p->tline.pos.x)] == 'D' || p->map.map[(int)(p->tline.pos.y + p->di.y * (step * 4))][(int)(p->tline.pos.x)] == '0')
		{
			getdoorpos((int)(p->tline.pos.x), (int)(p->tline.pos.y + p->di.y * (step * 4)), p);
			printf("hello2\n");
		}
		printf("hello---->\n");
		print_twod_str(p->map.map);
	}
	else if (key == 13)
	{
		if(p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x + p->di.x * step)] != '1' \
		&& p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x + p->di.x * step)] != 'D')
			p->tline.pos.x += p->di.x * step;
		if(p->map.map[(int)(p->tline.pos.y + p->di.y * step)][(int)(p->tline.pos.x)] != '1' \
		&& p->map.map[(int)(p->tline.pos.y + p->di.y * step)][(int)(p->tline.pos.x)] != 'D')
			p->tline.pos.y += p->di.y * step;
		// player_move(p);
		// printf("map = %c\n", p->map.map[(int)(p->tline.pos.y + p->di.y * step)][(int)(p->tline.pos.x)]);
		p->tline.stepcount++;
	}
	else if (key == 0)
	{
		if (p->map.map[(int)(p->tline.pos.y - p->di.x * step)][(int)(p->tline.pos.x + p->di.y * step)] != '1')
		{
			p->tline.pos.x += p->di.y * step;
			p->tline.pos.y += -p->di.x * step;
		}
		p->tline.stepcount++;
	}
	else if (key == 2)
	{
		if (p->map.map[(int)(p->tline.pos.y + p->di.x * step)][(int)(p->tline.pos.x - p->di.y * step)] != '1')
		{
			p->tline.pos.x += -p->di.y * step;
			p->tline.pos.y += p->di.x * step;
		}
		p->tline.stepcount++;
	}
	else if (key == 1)
	{
		if(p->map.map[(int)(p->tline.pos.y)][(int)(p->tline.pos.x - p->di.x * step)] != '1')
			p->tline.pos.x -= p->di.x * step;
		if(p->map.map[(int)(p->tline.pos.y - p->di.y * step)][(int)(p->tline.pos.x)] != '1')
			p->tline.pos.y -= p->di.y * step;
		// player_move(p);
		p->tline.stepcount++;
	}
	if (key == 123)
	{
		rotate_hook(-5.0, p);
		p->tline.stepcount++;
	}
	else if (key == 124)
	{
		rotate_hook(5.0, p);
		p->tline.stepcount++;
	}
	player_move(p);
	return (0);
}

void	key_hook(t_pro *p)
{
	// mlx_key_hook(p->mlx.win, hook, p);
	mlx_hook(p->mlx.win, 2, 1L<<0, hook, p);
	mlx_mouse_hook(p->mlx.win, mouse_hook, p);
	return ;
}



