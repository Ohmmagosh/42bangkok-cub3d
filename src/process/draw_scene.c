/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:01:40 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 04:31:40 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	tex_pixel_put(t_myimg *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return *(int *)dst;
}

void	walldirchk(t_pro *p)
{
	if (p->tline.news == 'N')
		p->render.wall = p->render.n;
	else if (p->tline.news == 'E')
		p->render.wall = p->render.e;
	else if (p->tline.news == 'W')
		p->render.wall = p->render.w;
	else if (p->tline.news == 'S')
		p->render.wall = p->render.s;
}

void	wadwaii(float perp, t_pro *p, int i)
{
	int		height;
	int		d_start;
	int		d_end;
	int		texX;
	int		texY;
	int		texwidth = 30;
	int		texheight = 30;
	float	step;
	float	texpos;
	float	wallX;
	int	y;

	walldirchk(p);
	height = (int)(WIN_HEIGHT / perp);
	d_start = -height / 2 + WIN_HEIGHT / 2;
	if(d_start < 0)
		d_start = 0;
	d_end = height / 2 + WIN_HEIGHT / 2;
	if(d_end >= WIN_HEIGHT)
		d_end = WIN_HEIGHT - 1;
	if (p->tline.side == 0)
		wallX = p->tline.pos.y + p->tline.perpdist * p->tline.rayDirY;
	else
		wallX = p->tline.pos.x + p->tline.perpdist * p->tline.rayDirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)texwidth);
	if(p->tline.side == 0 && p->tline.rayDirX > 0)
		texX = texwidth - texX - 1;
	if(p->tline.side == 1 && p->tline.rayDirY < 0)
		texX = texwidth - texX - 1;
	step = 1.0 * texheight / height;
	texpos = (d_start - WIN_HEIGHT / 2 + height / 2) * step;
	y = d_start;
	while (y < d_end)
	{
		if (y >= 0)
		{
			texY = (int)texpos;
			texpos += step;
			my_mlx_pixel_put(&p->render.bg, i, y, tex_pixel_put(&p->render.wall, texX, texY));
		}
		++y;
	}
}
