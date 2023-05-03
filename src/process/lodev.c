/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:45:56 by rchiewli          #+#    #+#             */
/*   Updated: 2023/05/04 04:58:21 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	lode_start_delta_intit(t_pro *p)
{
	if (p->tline.rayDirX == 0)
		p->tline.delta.x = 1e30;
	else
		p->tline.delta.x = fabsf(1 / p->tline.rayDirX);
	if (p->tline.rayDirY == 0)
		p->tline.delta.y = 1e30;
	else
		p->tline.delta.y = fabsf(1 / p->tline.rayDirY);
	return ;
}

void	lode_start_step_dist_init(t_pro *p)
{
	if (p->tline.rayDirX < 0)
	{
		p->tline.step.x = -1;
		p->tline.sidedist.x = (p->tline.pos.x - p->tline.mapX) * \
									p->tline.delta.x;
	}
	else
	{
		p->tline.step.x = 1;
		p->tline.sidedist.x = (p->tline.mapX + 1.0 - p->tline.pos.x) * \
									p->tline.delta.x;
	}
	if (p->tline.rayDirY < 0)
	{
		p->tline.step.y = -1;
		p->tline.sidedist.y = (p->tline.pos.y - p->tline.mapY) * \
									p->tline.delta.y;
	}
	return ;
}

void	lode_start_loop(t_pro *p)
{
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
	return ;
}

void	lode_start_perp(t_pro *p)
{
	if (p->tline.side == 0)
		p->tline.perpdist = (p->tline.sidedist.x - p->tline.delta.x);
	else
		p->tline.perpdist = (p->tline.sidedist.y - p->tline.delta.y);
	return ;
}

void	lode_start(t_pro *p)
{
	int	i;

	i = 0;
	create_background(p);
	while (i < WIN_WIDTH)
	{
		lode_start_tline_init(p, i);
		lode_start_delta_intit(p);
		lode_start_step_dist_init(p);
		lode_start_loop(p);
		lode_start_perp(p);
		if (p->tline.side == 0 && p->tline.rayDirX > 0)
			p->tline.news = 'W';
		else if (p->tline.side == 0 && p->tline.rayDirX < 0)
			p->tline.news = 'E';
		else if (p->tline.side == 1 && p->tline.rayDirY > 0)
			p->tline.news = 'N';
		else if (p->tline.side == 1 && p->tline.rayDirY < 0)
			p->tline.news = 'S';
		wadwaii(p->tline.perpdist, p, i);
		i += 1;
	}
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->render.bg.img, 0, 0);
	return ;
}
