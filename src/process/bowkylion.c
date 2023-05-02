/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bowkylion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:01:40 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 23:33:52 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
int	tex_pixel_put(t_myimg *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return *(int *)dst;
}

void	wadwaii(float perp, t_pro *p, int i)
{
	int	height;
	int dstart;
	int dend;
	t_myimg	walltt;
	float	 wallX;
	int texX;
	int	rgbtq;
	int	texwidth = 30;
	int	texheight = 30;
	float	step;
	float	texpos;
	int		texY;
	int	y;

	height = (int)(WIN_HEIGHT / perp);
	dstart = -height / 2 + WIN_HEIGHT / 2;
	if(dstart < 0)
		dstart = 0;
	dend = height / 2 + WIN_HEIGHT / 2;
	if(dend >= WIN_HEIGHT)
		dend = WIN_HEIGHT - 1;

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
	texpos = (dstart - WIN_HEIGHT / 2 + height / 2) * step;
	y = dstart;
	while (y < dend)
	{
		if (y >= 0)
		{
			texY = (int)texpos;
			texpos+=step;
			my_mlx_pixel_put(&p->mlx.img, i, y, tex_pixel_put(&p->render.n, texX, texY));
		}
		++y;
	}
}
