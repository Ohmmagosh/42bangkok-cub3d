/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/25 01:09:28 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

void	my_mlx_pixel_put(t_myimg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void process_cube(t_pro *p)
{
	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx, 800, 600, "cub3d");

	// t_myimg img;
	// p->mlx.img.img = mlx_new_image(p->mlx.mlx, 800, 600);
	// p->mlx.img.addr = mlx_get_data_addr(p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length,
	// 							&p->mlx.img.endian);
	// for (int y = 0; y < 300; y++)
	// {
	// 	for (int x = 0; x < 800; x++)
	// 		my_mlx_pixel_put(&p->mlx.img, x, y, 0xFC0000);
	// }

	// printf("%c %d %d %d %d\n", p->spt.cstart, p->spt.di.x, p->spt.di.y, p->spt.pos.x, p->spt.pos.y);
	p->tline.pos = (t_vef){p->spt.pos.x + 0.5, p->spt.pos.y + 0.5};
	// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, img.img, 0, 0);
	lode_start(p);
	draw_minimap(p);
	key_hook(p);
	mlx_loop(p->mlx.mlx);
}
