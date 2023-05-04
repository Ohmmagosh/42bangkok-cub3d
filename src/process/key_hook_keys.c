/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:39:32 by rchiewli          #+#    #+#             */
/*   Updated: 2023/05/04 18:33:55 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	key_3(t_pro *p, float step)
{
	if (p->map.map[(int)(p->tline.pos.y)] \
		[(int)(p->tline.pos.x + p->di.x * (step * 4))] == 'D' \
		|| p->map.map[(int)(p->tline.pos.y)] \
		[(int)(p->tline.pos.x + p->di.x * (step * 4))] == '0')
		getdoorpos((int)(p->tline.pos.x + p->di.x * (step * 4)), \
		(int)(p->tline.pos.y), p);
	if (p->map.map[(int)(p->tline.pos.y + p->di.y * (step * 4))] \
		[(int)(p->tline.pos.x)] == 'D' \
		|| p->map.map[(int)(p->tline.pos.y + p->di.y * (step * 4))] \
		[(int)(p->tline.pos.x)] == '0')
		getdoorpos((int)(p->tline.pos.x), \
		(int)(p->tline.pos.y + p->di.y * (step * 4)), p);
	p->chkhand = 1;
}

void	key_13(t_pro *p, float step)
{
	if (p->map.map[(int)(p->tline.pos.y)] \
	[(int)(p->tline.pos.x + p->di.x * (step * 2))] != '1' \
	&& p->map.map[(int)(p->tline.pos.y)] \
	[(int)(p->tline.pos.x + p->di.x * (step * 2))] != 'D')
		p->tline.pos.x += p->di.x * step;
	if (p->map.map[(int)(p->tline.pos.y + p->di.y * (step * 2))] \
	[(int)(p->tline.pos.x)] != '1' \
	&& p->map.map[(int)(p->tline.pos.y + p->di.y * (step * 2))] \
	[(int)(p->tline.pos.x)] != 'D')
		p->tline.pos.y += p->di.y * step;
}

void	key_0_or_2(t_pro *p, float step, int key)
{
	if (key == 0)
	{
		if (p->map.map[(int)(p->tline.pos.y - p->di.x * (step * 2))] \
		[(int)(p->tline.pos.x + p->di.y * (step * 2))] != '1')
		{
			p->tline.pos.x += p->di.y * step;
			p->tline.pos.y += -p->di.x * step;
		}
	}
	else if (key == 2)
	{
		if (p->map.map[(int)(p->tline.pos.y + p->di.x * (step * 2))] \
		[(int)(p->tline.pos.x - p->di.y * (step * 2))] != '1')
		{
			p->tline.pos.x += -p->di.y * step;
			p->tline.pos.y += p->di.x * step;
		}
	}
}

void	key_1(t_pro *p, float step)
{
	if (p->map.map[(int)(p->tline.pos.y)] \
	[(int)(p->tline.pos.x - p->di.x * (step * 2))] != '1')
		p->tline.pos.x -= p->di.x * step;
	if (p->map.map[(int)(p->tline.pos.y - p->di.y * (step * 2))] \
	[(int)(p->tline.pos.x)] != '1')
		p->tline.pos.y -= p->di.y * step;
}
