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

t_xy	get_point_on_circle2(float x, float y, float angle)
{
	t_xy	txy;
	float	ang;

	ang = angle * M_PI / 180.0;

	txy.x1 = x + 30 * cos(ang);
	txy.y1 = y + 30 * sin(ang);
}

void	draw_plane(t_mlx *tmlx)
{

}
