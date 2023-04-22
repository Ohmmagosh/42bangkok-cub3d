/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/22 21:08:12 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

// # define WIN_WIDTH 500
// # define WIN_HEIGHT 500
// # define COLOR 0xFFFFFF

// void get_point_on_circle(t_xy *txy, float angle)
// {
// 	angle = angle * M_PI / 180.0;

// 	txy->x2 = txy->x1 + 10 * cos(angle);
// 	txy->y2 = txy->y1 + 10 * sin(angle);
// }

// int rotate_hook(int keycode, t_pro *p)
// {
// 	if (keycode == 124 || keycode == 123)
// 		anglechange(keycode, p);
// 	else if (keycode == 0 || keycode == 2 || keycode == 1 || keycode == 13)
// 		movechange(keycode, p);
// 	else
// 		printf("keykode = %d\n", keycode);
// 	return 0;
// }

// void	xy_become_start(t_xy *txy, int xstart, int ystart)
// {
// 	txy->x1 = 1;
// 	txy->y1 = 1;
// }

// void	circle(t_pro *p, t_xy *txy)
// {
// 	float	r;
// 	float	x;
// 	float	y;

// 	r = 5;
// 	x = txy->x1 - r;
// 	while (r > 0)
// 	{
// 		while (x <= txy->x1 + r)
// 		{
// 			y = txy->y1 + sqrt(r * r - (x - txy->x1) * (x - txy->x1));
// 			mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
// 			y = txy->y1 - sqrt(r * r - (x - txy->x1) * (x - txy->x1));
// 			mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
// 			x += 0.01;
// 		}
// 		x = txy->x1 - r;
// 		r -= 2;
// 	}
// }

// void	process_cube(t_pro *p)
// {
// 	t_xy	*txy;
// 	t_hwa	*hwa;
// 	// int		i;

// 	// i = 0;
// 	hwa = malloc(sizeof(t_hwa));
// 	txy = malloc(sizeof(t_xy));
// 	p->mlx.txy = txy;
// 	txy->x2 = 0;
// 	txy->x2 = 0;
// 	hwa->angle = 270;

// 	p->mlx.mlx = mlx_init();
// 	p->mlx.win = mlx_new_window(p->mlx.mlx, WIN_WIDTH,  WIN_HEIGHT, "My Window");
// 	p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
// 	p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, \
// 		&p->mlx.img.line_length, &p->mlx.img.endian);

// 	// while (i < 7)
// 	// {
// 	// 	printf ("bfore i\n");
// 	// 	p->mlx.larray[i].linenum = i;
// 	// 	printf ("aftr i\n");
// 	// }

// 	xy_become_start(txy, hwa->xstart, hwa->ystart);
// 	// circle(p,txy);
// 	ini_ray(p);
// 	// draw_line(&p->mlx, txy, hwa->angle, -1);
// 	// draw_plane(&p->mlx, g_xstart, g_ystart, g_angle);
// 	xy_become_start(txy, hwa->xstart, hwa->ystart);
// 	mlx_hook(p->mlx.win, 2, 0, rotate_hook, p);
// 	xy_become_start(txy, hwa->xstart, hwa->ystart);
// 	mlx_loop(p->mlx.mlx);
// }

t_coord	get_point_on_circle(float x, float y, int radiant, float angle)
{
	t_coord	tco;
	float	ang;

	ang = angle * M_PI / 180.0;

	tco.x = x + radiant * cos(ang);
	tco.y = y + radiant * sin(ang);
	return (tco);
}

void	draw_line(t_mlx *tmlx, t_line *tline,float ang, int ladex)
{
	t_coord	d;
	t_coord	s;
	float	err;
	float	distance;
	int		i;
	t_coord tend;

	showgrid(tmlx);
	tend = get_point_on_circle(tline[ladex].costart.x, tline[ladex].costart.y, 10, ang);
	d.x = fabsf(tend.x - tline[ladex].costart.x);
	d.y = fabsf(tend.y - tline[ladex].costart.y);
	if (tline[ladex].costart.x < tend.x)
		s.x = 1;
	else
		s.x = -1;
	if (tline[ladex].costart.y < tend.y)
		s.y = 1;
	else
		s.y = -1;
	err = d.x - d.y;
	tline[ladex].costop.x += g_xstart;
	tline[ladex].costop.y += g_ystart;

	while (tline[ladex].costop.x != 0 && tline[ladex].costop.x != (WIN_WIDTH / 2) && tline[ladex].costop.y != 0 \
		&& tline[ladex].costop.y != WIN_HEIGHT && tline[ladex].costop.x >= (g_gridsize * 2) && tline[ladex].costop.y >= (g_gridsize * 3))
	{
		mlx_pixel_put(tmlx->mlx, tmlx->win, tline[ladex].costop.x, tline[ladex].costop.y, COLOR);
		if (err * 2 > -d.y)
		{
			err -= d.y;
			tline[ladex].costop.x += s.x;
		}
		if (err * 2 < d.x)
		{
			err += d.x;
			tline[ladex].costop.y += s.y;
		}
	}
}

void	process_cube(t_pro *p)
{
	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx, WIN_WIDTH,  WIN_HEIGHT, "My Window");
	p->mlx.img.img = mlx_new_image(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	p->mlx.img.addr = mlx_get_data_addr(&p->mlx.img.img, &p->mlx.img.bits_per_pixel, \
		&p->mlx.img.line_length, &p->mlx.img.endian);

	// circle(p,txy);
	// ini_ray(p);

	// ----------------------------here---------------------------------------


	// draw_line(&p->mlx, txy, hwa->angle, -1);
	// draw_plane(&p->mlx, g_xstart, g_ystart, g_angle);
	// xy_become_start(txy, hwa->xstart, hwa->ystart);
	// mlx_hook(p->mlx.win, 2, 0, rotate_hook, p);
	// xy_become_start(txy, hwa->xstart, hwa->ystart);
	// exit(0);
	mlx_loop(p->mlx.mlx);
	printf("KUY!!\n");
}
