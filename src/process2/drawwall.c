#include "../../cub3d.h"
#include <math.h>

void draw_wall(t_mlx *tmlx)
{
	int	i;
	int	linecount;
	int	hight;
	int	j;

	j = 0;
	linecount = 0;
	while (linecount < 7)
	{
		i = 70;
		while (i)
		{
			// printf("[0] - %f\n", tmlx->larray[0].distance);
			// printf("[1] - %f\n", tmlx->larray[1].distance);
			// printf("[2] - %f\n", tmlx->larray[2].distance);
			// printf("%f\n", tmlx->larray[linecount].distance);
			// exit (0);
			hight = (2000 / tmlx->larray[linecount].distance);
			while (hight > 0)
			{
				printf("hight %d\n", hight);
				mlx_pixel_put(tmlx->mlx, tmlx->win, j + 500, hight + 250 , COLOR);
				hight -= 2;
			}
			j++;
			i--;
		}
		linecount++;
	}
}

t_xy draw_core(t_mlx *tmlx, float g_x, float g_y, float g_angle)
{
	t_xy	txy;
	float	angle_rad;
	float	dx;
	float	dy;
	int		i;

	i = 0;
	angle_rad = g_angle * M_PI / 180.0;
	// dx = 100.0 * cos(angle_rad);
	// dy = 100.0 * sin(angle_rad);
	while (i <= 30)
	{
		txy.x2 = g_x + i * cos(angle_rad);
		txy.y2 = g_y + i * sin(angle_rad);
		if (txy.x2 < 0 || txy.x2 >= WIN_WIDTH / 2 || txy.y2 < 0 || txy.y2 >= WIN_HEIGHT)
			break;
		mlx_pixel_put(tmlx->mlx, tmlx->win, txy.x2, txy.y2, 0xFF0000);
		i++;
	}
	return (txy);
}

void draw_plane(t_mlx *tmlx, float g_x, float g_y, float g_angle)
{
	t_xy	txy;
	float	x_end;
	float	y_end;
	float	angle_rad;
	float	x1;
	float	y1;
	float	x2;
	float	y2;

	txy = draw_core(tmlx, g_x, g_y, g_angle);
	angle_rad = g_angle * M_PI / 180.0;
	x_end = txy.x2;
	y_end = txy.y2;
	// x1 = x_end + 30 * cos(angle_rad + M_PI/2.0);
	// y1 = y_end + 30 * sin(angle_rad + M_PI/2.0);
	x2 = x_end - 30 * cos(angle_rad + M_PI/2.0);
	y2 = y_end - 30 * sin(angle_rad + M_PI/2.0);
	printf("xend = %f yend = %f\n", txy.x2, txy.y2);
	printf("x1 = %f y1 = %f\n", x1, y1);
	printf("x2 = %f y2 = %f\n", x2, y2);
	// draw_core(tmlx, x1, y1, g_angle + 90.0);
	draw_core(tmlx, x2, y2, g_angle + 90.0);
}
