#include "../../cub3d.h"
int	tex_pixel_put(t_myimg *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return *(int *)dst;
}

void	wadwaii(float perp, t_pro *p, int i)
{
	int	height;
	// int	j;
	int dstart;
	int dend;
	// int	k;
	t_myimg	walltt;
	float	 wallX; //where exactly the wall was hit
	int texX;
	int	rgbtq;
	int	texwidth = 30;
	int	texheight = 30;
	float	step;
	float	texpos;
	int		texY;
	int	y;

	walltt.img = mlx_xpm_file_to_image(p->mlx.mlx, "./src/process/walltt30px.xpm", &walltt.line_length, &walltt.bits_per_pixel);

	walltt.addr = mlx_get_data_addr(walltt.img, &walltt.bits_per_pixel, &walltt.line_length, &walltt.endian);

	height = (int)(WIN_HEIGHT / perp);
	dstart = -height / 2 + WIN_HEIGHT / 2;
	if(dstart < 0)
		dstart = 0;
	dend = height / 2 + WIN_HEIGHT / 2;
	if(dend >= WIN_HEIGHT)
		dend = WIN_HEIGHT - 1;

	if (p->tline.side == 0)
		wallX = p->tline.pos.y + p->tline.perpdist * p->tline.rayDirY;
	else
		wallX = p->tline.pos.x + p->tline.perpdist * p->tline.rayDirX;
	wallX -= floor((wallX));



	texX = (int)(wallX * (double)texwidth);
	if(p->tline.side == 0 && p->tline.rayDirX > 0)
		texX = texwidth - texX - 1;
	if(p->tline.side == 1 && p->tline.rayDirY < 0)
		texX = texwidth - texX - 1;


	step = 1.0 * texheight / height;
	// step = height / texheight;

	texpos = (dstart - WIN_HEIGHT / 2 + height / 2) * step;
	y = dstart;

	// printf("texpos -> %d\n",)
	// printf("step[%d] = %f\n", i, step);
	while (y < dend)
	{
		if (y >= 0)
		{

			// rgbtq = (*(int *)walltt.addr + (double)texX);
			// texY = (int)texpos & (texheight - 1);
			texY = (int)texpos;
			// printf("line[%d] texx = %d texy = %d\n", i, texX, texY);
			// printf("texY -> %d\n", texY);
			texpos+=step;
			// texpos += step;
			// rgbtq = (*(int *)walltt.addr +(((float)(y - dstart) * texpos) * walltt.line_length + texX * (walltt.bits_per_pixel / 8)));
			// rgbtq = (*(int *)(walltt.addr + (texY * walltt.bits_per_pixel) + (texX * (walltt.bits_per_pixel / 8))));

			// printf("col -> %f\n", (*(int *)walltt.addr + (((float)(y - dstart) * texpos) * walltt.line_length + texX * (walltt.bits_per_pixel / 8))));
			// printf("rgb -> %d\n", rgbtq);
			// printf(" y -> %d\n", y);

			my_mlx_pixel_put(&p->mlx.img, i, y, tex_pixel_put(&walltt, texX, texY));
			// texpos += step;

		}
		++y;
	}
	// sleep(100);
	// k = 0;
	// j = (WIN_HEIGHT / 2) - (height / 2);
	// if (j < 0)
	// 	j = 0;
	// if (height > WIN_HEIGHT - 1)
	// 	height = WIN_HEIGHT - 1;

	// if (p->tline.news == 'N')
	// 	rgbtq = 0xFF0000;
	// else if (p->tline.news == 'E')
	// 	rgbtq = 0xFFFF00;
	// else if (p->tline.news == 'W')
	// 	rgbtq = 0x00FF00;
	// else if (p->tline.news == 'S')
	// 	rgbtq = 0x00FFFF;

	// rc->tex_x = (int)(rc->wall_hit_pos * (double) tex->w);
	// texX = (int)(wallX * (float)(texwidth));
	// if(p->tline.side == 0 && p->tline.rayDirX > 0) texX = texwidth - texX - 1;
	// if(p->tline.side == 1 && p->tline.rayDirY < 0) texX = texwidth - texX - 1;


	// texpos = (j - WIN_HEIGHT / 2 + height / 2) * step;

	// texY = (int)((j - (height - j)) * ((double)(texheight)) / ((double)height));
	// rgbtq = *(int*)(walltt.addr + (texY * walltt.line_length + texX * (walltt.bits_per_pixel) / 8));
	// while (k < height)
	// {
	// 	// texY = (int)texpos & (texheight - 1);
	// 	// texY = (((j - WIN_HEIGHT / 2 + height / 2) * walltt.line_length) / height);
	// 	texY = (int)((j * 2 - WIN_HEIGHT + height) * ((texheight / 2.0f) / height));
	// 	// texY = (double)(y - rc->draw_ends[0]) * (double)tex->h / (double)rc->line_height;
	// 	texpos += step;
	// 	rgbtq = *(int*)(walltt.addr + (texY * walltt.line_length + texX * (walltt.bits_per_pixel) / 8));
	// 	// rgbtq = *(int*)(walltt.addr + (texY * walltt.line_length + texX * (walltt.bits_per_pixel / 8)));
	// 	// rgbtq = walltt.addr[texheight * texY + texX];
	// 	my_mlx_pixel_put(&p->mlx.img, i, k + j, rgbtq);
	// 	k++;
	// }
}
	// while (k < height)
	// {
	// 	if (k + j > 0 && k + j < WIN_HEIGHT)
	// 		my_mlx_pixel_put(&p->mlx.img, i, k + j, rgbtq);
	// 	k += 1;
	// }

	// rc->tex_x = (int)(rc->wall_hit_pos * (double) tex->w);
	// if ((rc->hit_dir == 0 && rc->raydir.x > 0)|| (rc->hit_dir == 1 && rc->raydir.y < 0))
	// 	rc->tex_x = tex->w - rc->tex_x - 1;
	// h_ratio = (double)tex->h / (double)rc->line_height;
	// y = rc->draw_ends[0];
	// while (y < ft_min(rc->draw_ends[1], WINDOW_HEIGHT))
	// {
	// 	if (y >= 0)
	// 		img_pix_put(buf, x, y, img_pix_get(tex, rc->tex_x, (double)(y - rc->draw_ends[0]) * h_ratio));
	// 	++y;
	// }

// void	draw_wall(t_game *g, t_raysult *r)
// {
// 	int		i[2];
// 	t_pos	p_tex;
// 	t_tex	*tex;
// 	t_pos	pixel;

// 	tex = &g->tex[r->direction];
// 	set_pos(&pixel, r->column, MAX(0, g->window.half.y - (r->height / 2.)));
// 	if (!tex->tex)
// 	{
// 		draw_vertical_line(&g->window, &pixel, r->height,
// 			distance_shade(g->options,
// 			g->config.c[r->direction], r->distance));
// 		return ;
// 	}
// 	init_draw_wall(tex, r, &p_tex);
// 	i[1] = MAX(0, g->window.half.y - (r->height / 2.));
// 	i[0] = 0;
// 	while (i[0] < r->height && (pixel.y = i[1]++) < g->window.size.y)
// 	{
// 		p_tex.y = (int)((pixel.y * 2 - g->window.size.y + r->height)
// 				* ((tex->height / 2.) / r->height));
// 		draw_pixel(&g->window, &pixel, distance_shade(g->options,
// 			get_tex_color(tex, &p_tex), r->distance));
// 		i[0]++;
// 	}
// }
// int			ft_put_pixel(t_img *img, unsigned int color, int p_x, int p_y)
// {
// 	if (p_y >= img->height || p_x >= img->width || p_x < 0 || p_y < 0 || ((p_y * img->width + p_x) >= (img->width * img->height - 1)))
// 		return (PIXEL_ERROR);
// 	img->img_data[p_y * img->width + p_x] = color;
// 	return (SUCCESS);
// }
