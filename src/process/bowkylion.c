/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bowkylion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:01:40 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 23:44:37 by rchiewli         ###   ########.fr       */
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

	// /Users/rchiewli/mclone/src/process/Screen-Shot-2023-05-01-at-11.49.58-PM.xpm

	if (p->tline.news == 'N')
	{
		walltt.img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/hello.xpm", &walltt.line_length, &walltt.bits_per_pixel);

		walltt.addr = mlx_get_data_addr(walltt.img, &walltt.bits_per_pixel, &walltt.line_length, &walltt.endian);
	}
	else if (p->tline.news == 'E')
	{
		walltt.img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/walltt30px.xpm", &walltt.line_length, &walltt.bits_per_pixel);

		walltt.addr = mlx_get_data_addr(walltt.img, &walltt.bits_per_pixel, &walltt.line_length, &walltt.endian);
	}
	else if (p->tline.news == 'W')
	{
		walltt.img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/walltt30px.xpm", &walltt.line_length, &walltt.bits_per_pixel);

		walltt.addr = mlx_get_data_addr(walltt.img, &walltt.bits_per_pixel, &walltt.line_length, &walltt.endian);
	}
	else if (p->tline.news == 'S')
	{
		walltt.img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/walltt30px.xpm", &walltt.line_length, &walltt.bits_per_pixel);

		walltt.addr = mlx_get_data_addr(walltt.img, &walltt.bits_per_pixel, &walltt.line_length, &walltt.endian);
	}

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
