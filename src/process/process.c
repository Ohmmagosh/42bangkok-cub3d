/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/04 19:03:50 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

// should know index x,y of start
int	x = 3;
int	y = 3;

t_coord	get_point_on_circle(float x, float y, int radiant, float angle)
{
	t_coord	tco;
	float	ang;

	ang = angle * M_PI / 180.0;

	tco.x = x + radiant * cos(ang);
	tco.y = y + radiant * sin(ang);
	return (tco);
}

void	draw_line(float startx, float starty, t_coord stop, t_pro *p)
{
	float	dx = fabsf(stop.x - startx);
	float	dy = fabsf(stop.y - starty);
	float	sx, sy, err;
	int		x;
	int		y;

	stop.x = (int)stop.x;
	stop.y = (int)stop.y;
	printf("x-y =  %f %f stop x-y %f %f\n", startx, starty, stop.x, stop.y);
	if (startx < stop.x)
		sx = 1;
	else
		sx = -1;
	if (starty < stop.y)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	x = startx;
	y = starty;
	while (1)
	{
		printf("%d %d, stop x y %f %f\n", x, y, stop.x, stop.y);
		// exit(0);
		mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, COLOR);
		if (x == stop.x && y == stop.y || x < 0)
			break;
		int e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void	ini_start(char c, int x, int y)
{
	if (c == 'N')
		g_angle = 270;
	else if (c == 'E')
		g_angle = 0;
	else if (c == 'S')
		g_angle = 90;
	else if (c == 'W')
		g_angle = 180;
	g_xstart = (BLOCK * x) + (BLOCK / 2) - 1;
	g_ystart = (BLOCK * y) + (BLOCK / 2) - 1;
}

void	process_cube(t_pro *p)
{
	char *map[] = {
		"11111",
		"10001",
		"10101",
		"100N1",
		"11111",
		NULL
	};
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);

	ini_start(map[3][3], x, y);
	// printf("%f %f %f\n", g_xstart, g_ystart, g_angle);

	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx, WIN_WIDTH,  WIN_HEIGHT, "My Window");
	int mwidth = 500;
    int mheight = 500;
	g_img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/aaa.xpm", &mwidth, &mheight);
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, g_img, 0, 0);
	draw_T(p);
	mlx_hook(p->mlx.win, 2, 0, hooker, p);
	mlx_loop(p->mlx.mlx);
	// exit(0);
}
