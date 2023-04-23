/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/23 23:23:41 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

void swap_t_vec(t_vec *a, t_vec *b)
{
	t_vec *tmp;

	tmp->x = a->x;
	tmp->y = a->y;
	a->x = b->x;
	a->x = b->y;
	b->x = tmp->x;
	b->y = tmp->y;
}


// void	minimap(t_mlx2 *p)
// {
// 	void	*wall;
// 	void	*bg;
// 	M_PI
// }

void draw_line1(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color)
{
	int dx, dy, x, y, err, x_step, y_step;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	x = x1;
	y = y1;
	x_step = (x1 < x2) ? 1 : -1;
	y_step = (y1 < y2) ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;

	while (x != x2 || y != y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		int e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x += x_step;
		}
		if (e2 < dy)
		{
			err += dx;
			y += y_step;
		}
	}
}


void draw_line_by_angle(void *mlx_ptr, void *win_ptr, int x1, int y1, int length, double angle, int color)
{
	int x2, y2;

	x2 = x1 + length * cos(angle);
	y2 = y1 + length * sin(angle);

	mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);
	draw_line1(mlx_ptr, win_ptr, x1, y1, x2, y2, color);
}

// void draw_radar(t_mlx2 *p, int length, t_vei start)
// {
// 	double	angle_deg;
// 	double	angle_rad;

// 	while (angle_deg <= 66)
// 	{
// 		angle_rad = angle_deg * (M_PI / 180.0);
// 		draw_line_by_angle(p->mlx, p->win, start.x, start.y, length, angle_rad, 0xFFFFFF);
// 		angle_deg += 2;
// 	}
// }

// void minimap_put_block(t_mlx2 *p, int x, int y, void *img, int width, int heigth)
// {
// 	int block_x;
// 	int block_y;

// 	block_y = 0;
// 	while (block_y < 3)
// 	{
// 		block_x = 0;
// 		while (block_x < 3)
// 		{
// 			mlx_put_image_to_window(p->mlx, p->win, img, x, y);
// 			block_x++;
// 		}
// 	}
// }
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
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, img.img, 0, 0);
	draw_minimap(p);
	key_hook(p);
	mlx_loop(p->mlx.mlx);
}
