#include "../../cub3d.h"
#include <math.h>

int	hooker(int keycode, void *k)
{
	t_pro	*p;
	p = (t_pro *)k;

	printf("ketcode = %d\n", keycode);
	mlx_clear_window(p->mlx.mlx, p->mlx.win );
	if (keycode == 2)
		g_xstart += 2;
	else if (keycode == 0)
		g_xstart -= 2;
	else if (keycode == 1)
		g_ystart += 2;
	else if (keycode == 13)
		g_ystart -= 2;
	else if (keycode == 123)
		g_angle -= 2;
	else if (keycode == 124)
		g_angle += 2;
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, g_img, 0, 0);
	draw_T(p);
	return 0;
}
