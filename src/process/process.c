/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/20 17:53:50 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

	float angle = 0;

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define COLOR 0xFFFFFF

void get_point_on_circle(t_xy *txy, float angle)
{
	angle = angle * M_PI / 180.0;

	txy->x2 = txy->x1 + 10 * cos(angle);
	txy->y2 = txy->y1 + 10 * sin(angle);
}

void	draw_line(t_mlx *tmlx, t_xy *txy, float ang)
{
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	float	err;

	get_point_on_circle(txy, angle);
	// printf("get cir x1 = %f y1 = %f x2 = %f y2 = %f\n", txy->x1, txy->y1, txy->x2, txy->y2);
	dx = fabsf(txy->x2 - txy->x1);
	dy = fabsf(txy->y2 - txy->y1);
	if (txy->x1 < txy->x2)
		sx = 1;
	else
		sx = -1;
	if (txy->y1 < txy->y2)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	// if (txy->x1 < 0)
	// 	txy->x1 = 0;
	// if (txy->x1 >= WIN_WIDTH)
	// 	txy->x1 = WIN_WIDTH - 1;
	// if (txy->y1 < 0)
	// 	txy->y1 = 0;
	// if (txy->y1 >= WIN_HEIGHT)
	// 	txy->y1 = WIN_HEIGHT -1;
	// if (txy->x2 < 0)
	// 	txy->x2 = 0;
	// if (txy->x2 >= WIN_WIDTH)
	// 	txy->x2 = WIN_WIDTH - 1;
	// if (txy->y2 < 0)
	// 	txy->y2 = 0;
	// if (txy->y2 >= WIN_HEIGHT)
	// 	txy->y2 = WIN_HEIGHT - 1;
	// while (txy->x1 != txy->x2 || txy->y1 != txy->y2)
	// while (txy->x1 != WIN_WIDTH || txy->y1 != WIN_HEIGHT)
	while (txy->x1 != 0 && txy->x1 != WIN_WIDTH && txy->y1 != 0 && txy->y1 != WIN_HEIGHT)
	{
		mlx_pixel_put(tmlx->mlx, tmlx->win, txy->x1, txy->y1, COLOR);
		if (err * 2 > -dy)
		{
			err -= dy;
			txy->x1 += sx;
		}
		if (err * 2 < dx)
		{
			err += dx;
			txy->y1 += sy;
		}
		// printf("x1 = %f y1 = %f x2 = %f y2 = %f\n", txy->x1, txy->y1, txy->x2, txy->y2);
	}

}

void	process_cube(t_pro *p)
{
	int		xstart = 250;
	int		ystart = 250;
	t_xy	*txy;

	txy = malloc(sizeof(t_xy));
	txy->x1 = xstart;
	txy->y1 = ystart;
	txy->x2 = 0;
	txy->x2 = 0;

	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx,WIN_WIDTH,  WIN_HEIGHT, "My Window");
	p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length, &p->mlx.img.endian);

	draw_line(&p->mlx, txy, angle);
	mlx_loop(p->mlx.mlx);
}
