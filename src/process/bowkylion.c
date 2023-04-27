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

	// walltt.img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/kumpaeng.xpm", &walltt.line_length, &walltt.bits_per_pixel);

	// walltt.addr = mlx_get_data_addr(walltt.img, &walltt.bits_per_pixel, &walltt.line_length, &walltt.endian);
	// // printf("i = %d height = %d perp = %f j = %d\n", i, height, perp, j);
	// if (p->tline.side == 0)
	// 	wallX = p->tline.pos.y + p->tline.perpdist * p->tline.rayDirY;
	// else
	// 	wallX = p->tline.pos.x + p->tline.perpdist * p->tline.rayDirX;
	// wallX -= floor((wallX));
	// texX = (int)(wallX * 3500.0);
	// if(p->tline.side == 0 && p->tline.rayDirX > 0)
	// 	texX = 3500.0 - texX - 1;
	// if(p->tline.side == 1 && p->tline.rayDirY < 0)
	// 	texX = 3500.0 - texX - 1;

	// 			// How much to increase the texture coordinate per screen pixel
	// float step = 1.0 * 3500 / height;
	//   // Starting texture coordinate
	// float texPos = (j - WIN_HEIGHT / 2 + height / 2) * step;
	// int rgbtq;
			while (k < height)
			{
		// for(int y = j; y< (j + height); y++)
		// {
		// // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		// 	int texY = (int)texPos & (3500 - 1);
		// 	texPos += step;
		// 	rgbtq = *(int*)(walltt.addr + (texY * walltt.line_length + texX * (walltt.bits_per_pixel / 8)));
		// 	// rgbtq = *(int*)(walltt.addr + (texY * walltt.line_length + texX));
		// }
	// mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, img.img, 0, 0);
				// printf("CHK!!!\n");
				// printf("i = %d k + j = %d height = %d\n", i, k + j, height);
				if (k + j > 0 && k + j < WIN_HEIGHT)
					my_mlx_pixel_put(&p->mlx.img, i, k + j, rgbtq);
				k += 1;
			}
}
