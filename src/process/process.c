/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/21 00:23:31 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

	float angle = 90;

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
	}
	printf("x1 = %f y1 = %f x2 = %f y2 = %f\n", txy->x1, txy->y1, txy->x2, txy->y2);
	// mlx_put_image_to_window(tmlx->mlx, tmlx->win, tmlx->img.img, 500, 500);
}

int rotate_hook(int keycode, t_pro *p)
{
	if (keycode == 2)
	{
		// mlx_destroy_image(p->mlx.mlx,p->mlx.img.img);
		// p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
		// p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length, &p->mlx.img.endian);
		// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img.img, 500, 500);
		angle++;
		draw_line(p->mlx.mlx, p->mlx.txy, angle);
		printf("zzzz\n");
		// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img.img, 500, 500);
		printf("keykode = %d angle = %f\n", keycode, angle);
	}
	else if (keycode == 0)
	{
		// mlx_destroy_image(p->mlx.mlx,p->mlx.img.img);
		// p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
		// p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length, &p->mlx.img.endian);
		// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img.img, 500, 500);
		angle--;
		draw_line(p->mlx.mlx, p->mlx.txy, angle);
		printf("zzzz\n");
		// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->mlx.img.img, 500, 500);
		printf("keykode = %d angle = %f\n", keycode, angle);
	}
	else
		printf("keykode = %d\n", keycode);
	return 0;
}

void	xy_become_start(t_xy *txy, int xstart, int ystart)
{
	txy->x1 = xstart;
	txy->y1 = ystart;
}

void	circle(t_pro *p, t_xy *txy)
{
	float	r;
	float	x;
	float	y;

	r = 5;
	x = txy->x1 - r;
	while (r > 0)
	{
		while (x <= txy->x1 + r)
		{
			y = txy->y1 + sqrt(r * r - (x - txy->x1) * (x - txy->x1));
			mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
			y = txy->y1 - sqrt(r * r - (x - txy->x1) * (x - txy->x1));
			mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
			x += 0.01;
		}
		x = txy->x1 - r;
		r -= 2;
	}
}

void	process_cube(t_pro *p)
{
	int		xstart = 250;
	int		ystart = 250;
	t_xy	*txy;

	txy = malloc(sizeof(t_xy));
	p->mlx.txy = txy;
	txy->x2 = 0;
	txy->x2 = 0;

	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx,WIN_WIDTH,  WIN_HEIGHT, "My Window");
	p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, &p->mlx.img.line_length, &p->mlx.img.endian);

	xy_become_start(txy, xstart,ystart);
	circle(p,txy);
	draw_line(&p->mlx, txy, angle);
	xy_become_start(txy, xstart,ystart);
	mlx_hook(p->mlx.win, 2, 0, rotate_hook, p);
	xy_become_start(txy, xstart,ystart);
	mlx_loop(p->mlx.mlx);
}
