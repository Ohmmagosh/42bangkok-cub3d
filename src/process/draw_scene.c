/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:01:40 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 18:40:21 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	tex_pixel_put(t_myimg *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(int *)dst);
}

void	p_kratoei_bok(t_wadd *wadd, t_pro *p, int i)
{
	while (wadd->y < wadd->d_end)
	{
		if (wadd->y >= 0)
		{
			wadd->tex_y = (int)wadd->texpos;
			wadd->texpos += wadd->step;
			my_mlx_pixel_put(&p->render.bg, i, wadd->y, \
			tex_pixel_put(&p->render.wall, wadd->tex_x, wadd->tex_y));
		}
		++wadd->y;
	}
}

int	tex_xfinder(t_pro *p, int texwidth, int tex_xinp)
{
	if (p->tline.side == 0 && p->tline.raydir_x > 0)
		tex_xinp = texwidth - tex_xinp - 1;
	if (p->tline.side == 1 && p->tline.raydir_y < 0)
		tex_xinp = texwidth - tex_xinp - 1;
	return (tex_xinp);
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
	t_wadd	wadd;

	wadd.texheight = 30;
	wadd.texwidth = 30;
	walldirchk(p);
	wadd.height = (int)(WIN_HEIGHT / perp);
	wadd.d_start = -wadd.height / 2 + WIN_HEIGHT / 2;
	if (wadd.d_start < 0)
		wadd.d_start = 0;
	wadd.d_end = wadd.height / 2 + WIN_HEIGHT / 2;
	if (wadd.d_end >= WIN_HEIGHT)
		wadd.d_end = WIN_HEIGHT - 1;
	if (p->tline.side == 0)
		wadd.wall_x = p->tline.pos.y + p->tline.perpdist * p->tline.raydir_y;
	else
		wadd.wall_x = p->tline.pos.x + p->tline.perpdist * p->tline.raydir_x;
	wadd.wall_x -= floor((wadd.wall_x));
	wadd.tex_x = (int)(wadd.wall_x * (double)wadd.texwidth);
	wadd.tex_x = tex_xfinder(p, wadd.texwidth, wadd.tex_x);
	wadd.step = 1.0 * wadd.texheight / wadd.height;
	wadd.texpos = (wadd.d_start - WIN_HEIGHT / 2 + wadd.height / 2) * wadd.step;
	wadd.y = wadd.d_start;
	p_kratoei_bok(&wadd, p, i);
}
