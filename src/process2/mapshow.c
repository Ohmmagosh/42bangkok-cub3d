#include "../../cub3d.h"
#include <math.h>

void showgrid(t_mlx *mlx)
{
	int	x;
	int	y;
	float	distance;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x + (g_gridsize * 2), y, COLOR);
		y++;
	}
	x = 0;
	y = 0;
	while (x < (WIN_WIDTH / 2))
	{
		mlx_pixel_put(mlx->mlx, mlx->win, x , y + (g_gridsize * 3), COLOR);
		x++;
	}
}
