/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:55:35 by rchiewli          #+#    #+#             */
/*   Updated: 2023/05/04 04:57:45 by rchiewli         ###   ########.fr       */
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
	else if (p->map.map[y][x] == 'D')
		return (2);
	return (0);
}

void	lode_start_tline_init(t_pro *p, int i)
{
	p->tline.cameraX = 2 * i / (float)WIN_WIDTH - 1;
	p->tline.rayDirX = p->di.x + p->spt.plane.x * p->tline.cameraX;
	p->tline.rayDirY = p->di.y + p->spt.plane.y * p->tline.cameraX;
	p->tline.mapX = (int)p->tline.pos.x;
	p->tline.mapY = (int)p->tline.pos.y;
	return ;
}
