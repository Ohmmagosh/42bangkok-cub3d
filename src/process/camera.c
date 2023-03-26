#include "../../cub3d.h"
#include <math.h>

void	anglechange(int keycode, t_pro *p)
{
	float	newan;
	int		ladex;

	ladex = 0;
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	if (keycode == 123)
		g_angle -= 2;
	else if (keycode == 124)
		g_angle += 2;
	// newan = g_angle + 15;
	// while (newan >= g_angle)
	// {
	// 	draw_line(&p->mlx, p->mlx.txy, newan);
	// 	newan -= 5;
	// }
	// p->mlx.txy->x1 = 1;
	// p->mlx.txy->y1 = 1;
	newan = g_angle - 30;
	while (newan <= g_angle + 30)
	{
		draw_line(&p->mlx, p->mlx.txy, newan, ladex);
		newan += 10;
		ladex++;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
	draw_wall(&p->mlx);
}

void	movechange(int keycode, t_pro *p)
{
	float	newan;
	int		ladex;

	ladex = 0;
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	if (keycode == 0)
		g_xstart -= 5;
	else if (keycode == 2)
		g_xstart += 5;
	else if (keycode == 1)
		g_ystart += 5;
	else if (keycode == 13)
		g_ystart -=5;
	// draw_line(&p->mlx, p->mlx.txy, g_angle);
	// newan = g_angle + 15;
	// while (newan > g_angle)
	// {
	// 	draw_line(p->mlx.mlx, p->mlx.txy, newan);
	// 	newan -= 5;
	// }
	// p->mlx.txy->x1 = 1;
	// p->mlx.txy->y1 = 1;
	newan = g_angle - 30;
	while (newan <= g_angle + 30)
	{
		draw_line(&p->mlx, p->mlx.txy, newan, ladex);
		newan += 10;
		ladex++;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
	draw_wall(&p->mlx);
}

void	ini_ray(t_pro *p)
{
	float	newan;
	int		ladex;

	ladex = 0;
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	newan = g_angle - 30;
	while (newan <= g_angle + 30)
	{
		draw_line(&p->mlx, p->mlx.txy, newan, ladex);
		newan += 10;
		ladex++;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
	draw_wall(&p->mlx);
}


// void	draw_line(t_mlx *tmlx, t_xy *txy,float ang, int ladex)
// {
// 	float	dx;
// 	float	dy;
// 	float	sx;
// 	float	sy;
// 	float	err;
// 	float	distance;
// 	int		i;

// 	showgrid(tmlx);
// 	get_point_on_circle(txy, ang);
// 	dx = fabsf(txy->x2 - txy->x1);
// 	dy = fabsf(txy->y2 - txy->y1);
// 	if (txy->x1 < txy->x2)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (txy->y1 < txy->y2)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	err = dx - dy;
// 	txy->x1 += g_xstart;
// 	txy->y1 += g_ystart;
// 	while (txy->x1 != 0 && txy->x1 != (WIN_WIDTH / 2) && txy->y1 != 0 && txy->y1 != WIN_HEIGHT && txy->x1 >= (g_gridsize * 2) && txy->y1 >= (g_gridsize * 3))
// 	{
// 		mlx_pixel_put(tmlx->mlx, tmlx->win, txy->x1, txy->y1, COLOR);
// 		if (ladex != -1)
// 		{
// 			tmlx->larray[ladex].x2 = txy->x1;
// 			tmlx->larray[ladex].y2 = txy->y1;
// 		}
// 		if (err * 2 > -dy)
// 		{
// 			err -= dy;
// 			txy->x1 += sx;
// 		}
// 		if (err * 2 < dx)
// 		{
// 			err += dx;
// 			txy->y1 += sy;
// 		}
// 	}
// 	// if (ladex >= 0)
// 	// {
// 	// 	tmlx->larray[ladex].distance = sqrt(pow((g_xstart - tmlx->larray[ladex].x2), 2) + pow((g_ystart - tmlx->larray[ladex].y2), 2));
// 	// 	printf("line array [%d] x = %f y = %f distance %f\n", ladex, tmlx->larray[ladex].x2, tmlx->larray[ladex].y2, tmlx->larray[ladex].distance);
// 	// }
// 	txy->x1 = 1;
// 	txy->y1 = 1;
// }
