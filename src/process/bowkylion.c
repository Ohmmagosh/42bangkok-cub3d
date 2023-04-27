#include "../../cub3d.h"

void	wadwaii(float perp, t_pro *p, int i)
{
	int	height;
	int	j;
	int	k;
	t_myimg	walltt;
	float	 wallX; //where exactly the wall was hit
	int texX;
	int	rgbtq;

	if (p->tline.news == 'N')
		rgbtq = 0xFF0000;
	else if (p->tline.news == 'E')
		rgbtq = 0xFFFF00;
	else if (p->tline.news == 'W')
		rgbtq = 0x00FF00;
	else if (p->tline.news == 'S')
		rgbtq = 0x00FFFF;

	k = 0;
	height = (int)(WIN_HEIGHT / perp);
	j = (WIN_HEIGHT / 2) - (height / 2);
	if (j < 0)
		j = 0;
	if (height > WIN_HEIGHT - 1)
		height = WIN_HEIGHT - 1;

	while (k < height)
	{
		if (k + j > 0 && k + j < WIN_HEIGHT)
			my_mlx_pixel_put(&p->mlx.img, i, k + j, rgbtq);
		k += 1;
	}
}
