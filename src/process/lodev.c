/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:45:56 by rchiewli          #+#    #+#             */
/*   Updated: 2023/04/28 23:54:30 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_vef	set_plane(char c)
{
	t_vef	rst;

	if (c == 'N' || c == 'S')
		rst = (t_vef){0.66, 0};
	else
		rst = (t_vef){0, 0.66};
	return (rst);
}

int	iswall(int x, int y, t_pro *p)
{
	if (p->map.map[y][x] == '1')
		return (1);
	return (0);
}

void	lode_start(t_pro *p)
{
	int		i;

	i = 0;
	p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	p->mlx.img.addr = mlx_get_data_addr(p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length,
								&p->mlx.img.endian);
	while (i < WIN_WIDTH)
	{
		p->tline.cameraX = 2 * i / (float)WIN_WIDTH - 1;
		p->tline.rayDirX = p->di.x + p->spt.plane.x * p->tline.cameraX;
		p->tline.rayDirY = p->di.y + p->spt.plane.y * p->tline.cameraX;
		p->tline.mapX = (int)p->tline.pos.x;
		p->tline.mapY = (int)p->tline.pos.y;
		if (p->tline.rayDirX == 0)
			p->tline.delta.x = 1e30;
		else
			p->tline.delta.x = fabsf(1 / p->tline.rayDirX);
		if (p->tline.rayDirY == 0)
			p->tline.delta.y = 1e30;
		else
			p->tline.delta.y = fabsf(1 / p->tline.rayDirY);
		if (p->tline.rayDirX < 0)
		{
			p->tline.step.x = -1;
			p->tline.sidedist.x = (p->tline.pos.x - p->tline.mapX) * p->tline.delta.x;
		}
		else
		{
			p->tline.step.x = 1;
			p->tline.sidedist.x = (p->tline.mapX + 1.0 - p->tline.pos.x) * p->tline.delta.x;
		}
		if (p->tline.rayDirY < 0)
		{
			p->tline.step.y = -1;
			p->tline.sidedist.y = (p->tline.pos.y - p->tline.mapY) * p->tline.delta.y;
		}
		else
		{
			p->tline.step.y = 1;
			p->tline.sidedist.y = (p->tline.mapY + 1.0 - p->tline.pos.y) * p->tline.delta.y;
		}
		while (!iswall(p->tline.mapX, p->tline.mapY, p))
		{
			if (p->tline.sidedist.x < p->tline.sidedist.y)
			{
				p->tline.sidedist.x += p->tline.delta.x;
				p->tline.mapX += p->tline.step.x;
				p->tline.side = 0;
			}
			else
			{
				p->tline.sidedist.y += p->tline.delta.y;
				p->tline.mapY += p->tline.step.y;
				p->tline.side = 1;
			}
		}
		if (p->tline.side == 0)
			p->tline.perpdist = (p->tline.sidedist.x - p->tline.delta.x);
		else
			p->tline.perpdist = (p->tline.sidedist.y - p->tline.delta.y);

		if (p->tline.side == 0 && p->tline.rayDirX > 0)
			p->tline.news = 'W';
		else if (p->tline.side == 0 && p->tline.rayDirX < 0)
			p->tline.news = 'E';
		else if (p->tline.side == 1 && p->tline.rayDirY > 0)
			p->tline.news = 'N';
		else if (p->tline.side == 1 && p->tline.rayDirY < 0)
			p->tline.news = 'S';

		wadwaii(p->tline.perpdist, p, i);
		i+= 1;
	}
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img.img, 0, 0);
}
