#include "../../cub3d.h"

void	wadwaii(float perp, t_pro *p, int i)
{
	int	height;
	int	j;
	int	k;

	k = 0;
	height = (int)(WIN_HEIGHT / perp);
	j = (WIN_HEIGHT / 2) - (height / 2);
	// printf("i = %d height = %d perp = %f j = %d\n", i, height, perp, j);
	while (k < height)
	{
		// printf("CHK!!!\n");
		// printf("i = %d k + j = %d height = %d\n", i, k + j, height);
		if (k + j > 0 && k + j < WIN_HEIGHT)
			my_mlx_pixel_put(&p->mlx.img, i, k + j, 0xFFFF00);
		k += 1;
	}
	// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, img.img, 0, 0);
}
