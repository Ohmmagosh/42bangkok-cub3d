/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/24 23:50:13 by rchiewli         ###   ########.fr       */
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

	t_myimg img;
	img.img = mlx_new_image(p->mlx.mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int y = 0; y < 300; y++)
	{
		for (int x = 0; x < 800; x++)
			my_mlx_pixel_put(&img, x, y, 0xFC0000);
	}

	// printf("%c %d %d %d %d\n", p->spt.cstart, p->spt.di.x, p->spt.di.y, p->spt.pos.x, p->spt.pos.y);
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, img.img, 0, 0);
	lode_start(p);
	draw_minimap(p);
	key_hook(p);
	mlx_loop(p->mlx.mlx);
}
