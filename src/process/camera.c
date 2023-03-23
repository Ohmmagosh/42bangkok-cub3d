#include "../../cub3d.h"
#include <math.h>

void	anglechange(int keycode, t_pro *p)
{
	float newan;

	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	if (keycode == 123)
		g_angle -= 2;
	else if (keycode == 124)
		g_angle += 2;
	newan = g_angle + 15;
	while (newan >= g_angle)
	{
		draw_line(&p->mlx, p->mlx.txy, newan);
		newan -= 0.5;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
	newan = g_angle - 15;
	while (newan < g_angle)
	{
		draw_line(&p->mlx, p->mlx.txy, newan);
		newan += 0.5;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
}

void	movechange(int keycode, t_pro *p)
{
	float newan;

	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	if (keycode == 0)
		g_xstart -= 5;
	else if (keycode == 2)
		g_xstart += 5;
	else if (keycode == 1)
		g_ystart += 5;
	else if (keycode == 13)
		g_ystart -=5;
	draw_line(&p->mlx, p->mlx.txy, g_angle);
	newan = g_angle + 15;
	while (newan > g_angle)
	{
		draw_line(p->mlx.mlx, p->mlx.txy, newan);
		newan -= 0.5;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
	newan = g_angle - 15;
	while (newan < g_angle)
	{
		draw_line(&p->mlx, p->mlx.txy, newan);
		newan += 0.5;
	}
	p->mlx.txy->x1 = 1;
	p->mlx.txy->y1 = 1;
}
