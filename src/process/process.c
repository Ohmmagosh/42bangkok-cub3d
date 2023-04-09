/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/08 01:22:51 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <math.h>

// should know index x,y of start
//typedef struct t_main
//{
//	void	*mlx;
//	void	*win;
//	float	xstart;
//	float	ystart;
//	float	angle;
//} t_main;


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

void	process_cube1(t_pro *p)
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

void	draw_player(t_pro *p)
{
	float x = 300;
	float y = 300;
	while (x < 600)
	{
		mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, 0xFFFFFF);
		x++;
	}
}

int hook(int key, t_pro *p)
{
	printf("key -> %d\n", key);
	return (0);
}

void	draw1_line(t_pro *p, t_coord start, t_coord end)
{
	t_coord tmp;
	float x;
	float y;

	if (start.x > end.x)
	{
		tmp.x = start.x;
		tmp.y = start.y;
		start.x = end.x;
		start.y = end.y;
		end.x = tmp.x;
		end.y = tmp.y;
	}
	x = start.x;
	y = start.y;
	float	dx = end.x - start.x;
	float	dy = end.y - start.y;
	float	len = dx > dy ? fabsf(dx) : fabsf(dy);
	float	xinc = dx / len;
	float	yinc = dy / len;
	printf("xinc -> %f\n", xinc);
	printf("yinc -> %f\n", yinc);
	printf("start.x -> %f\n", start.x);
	printf("start.y -> %f\n", start.y);
	printf("end.x -> %f\n", end.x);
	printf("end.y -> %f\n", end.y);
	while (x < end.x || y < end.y)
	{
		mlx_pixel_put(p->mlx.mlx, p->mlx.win, x, y, 0xffffff);
		x += xinc;
		y += yinc;
	}
}

float degree_to_radian(float degree)
{
	float radian;

	float pi = 3.14159;
	radian = degree * pi / 180;
	return radian;
}

void	draw_map_utils(void *mlx, void *win, int xs, int ys)
{
	int		width;
	int		height;
	void	*img_ptr;


	printf("xs -> %d\n", xs);
	printf("ys -> %d\n", ys);
	img_ptr  = mlx_xpm_file_to_image(mlx, "./src/process/wall2.xpm", &width, &height);
	for (int i = ys; i < height * 3; i++)
	{
		for (int j = xs; j < width * 3; j++)
		{
			mlx_put_image_to_window(mlx, win, img_ptr, i, j);
			j += width;
		}
		i += height;
	}
}

void	draw_mini_map(void *mlx, void *win, char **map)
{
	int width;
	int height;

	void	*img_wall;
	void	*img_floor;
	img_wall = mlx_xpm_file_to_image(mlx, "./src/process/Layer_1.xpm", &width, &height);
	img_floor = mlx_xpm_file_to_image(mlx, "./src/process/Layer_2.xpm", &width, &height);
	int	x = 10;
	int y = 10;
	for (int i = 0; map[i]; i++)
	{
		x = 10;
		for (int j = 0; map[i][j]; j++)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img_wall, x, y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, img_floor, x, y);
			x += width + 1;
		}
		y += height + 1;
	}
	//for (int i = 0; map[i]; i++)
	//{
	//	// 0 1 2 3 4 5 6 7
	//	x = 0;
	//	for (int j = 0; map[i][j]; j++)
	//	{
	//		x += width * 4;
	//	}
	//	y += height * 4;
	//}
	//x += width;
	//mlx_put_image_to_window(mlx, win, img_ptr, x, y);
	//for (int i = 0; i < 4; i++)
	//{
	//	x = 0;
	//	for (int j = 0; j < 4; j++)
	//	{
	//		mlx_put_image_to_window(mlx, win, img_ptr, x, y);
	//		x += width;
	//	}
	//	y += height;
	//}

}


void	draw_bg(void *mlx_ptr, void *win_ptr, int win_width, int win_height){
	void *img_ptr;
	int img_width = win_width;
	int img_height = win_height;
	img_ptr = mlx_new_image(mlx_ptr, img_width, img_height);

	// Get image buffer data
	int bpp, size_line, endian;
	char *data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);

	// Set the background color (e.g., red)
	int x, y;
	int color = 0x4f4f4f; // Red in hexadecimal format (0xRRGGBB)

	for (y = 0; y < img_height; y++)
	{
		for (x = 0; x < img_width; x++)
		{
			int index = (y * size_line) + (x * bpp / 8);
			*(unsigned int *)(data + index) = color;
		}
	}

	// Draw the image buffer to the window
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}

void	process_cube(t_pro *p)
{
	char *map[] = {
		"111111111",
		"101000001",
		"101000001",
		"100000001",
		"100001001",
		"100000001",
		"100000001",
		"111111111",
		NULL
	};
	void *mlx;
	void *win;

	int win_width = 1280;
	int win_height = 720;

	mlx = mlx_init();
	win = mlx_new_window(mlx, win_width, win_height, "My Window");

	draw_bg(mlx,win, win_width, win_height);
	draw_mini_map(mlx, win, map);
	//draw_map(mlx_ptr, win_ptr, map);
	// Run the mlx loop
	mlx_loop(mlx);

}
//up 126
//down 125
//right 123
//left 124
