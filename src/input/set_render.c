/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:07:58 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/05 02:12:24 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	rgb_to_color(t_col col)
{
	int	ret;

	ret = (col.r << 16) | (col.g << 8) | col.b;
	return (ret);
}

t_myimg	set_myimg_new(void *mlx, int width, int height)
{
	t_myimg	ret;

	ret.img = mlx_new_image(mlx, width, height);
	ret.addr = mlx_get_data_addr(ret.img, &ret.bits_per_pixel, \
									&ret.line_length, &ret.endian);
	return (ret);
}

t_myimg	set_myimg(char *path, void *mlx, void *win)
{
	t_myimg	ret;

	(void)win;
	ret.img = mlx_xpm_file_to_image(mlx, path, &ret.line_length, \
									&ret.bits_per_pixel);
	ret.addr = mlx_get_data_addr(ret.img, &ret.bits_per_pixel, \
									&ret.line_length, &ret.endian);
	return (ret);
}

t_ren	set_render(t_tex *tex, void *mlx, void *win)
{
	t_ren	ret;

	ret.w = set_myimg(tex->we.path, mlx, win);
	ret.n = set_myimg(tex->no.path, mlx, win);
	ret.e = set_myimg(tex->ea.path, mlx, win);
	ret.s = set_myimg(tex->so.path, mlx, win);
	ret.hl0 = set_myimg("./img/hl0.xpm", mlx, win);
	ret.hl1 = set_myimg("./img/hr2.xpm", mlx, win);
	ret.hl2 = set_myimg("./img/hr3.xpm", mlx, win);
	ret.hl3 = set_myimg("./img/hr4.xpm", mlx, win);
	ret.hb1 = set_myimg("./img/hl1.xpm", mlx, win);
	ret.hb2 = set_myimg("./img/hl2.xpm", mlx, win);
	ret.hb3 = set_myimg("./img/hl3.xpm", mlx, win);
	ret.hb4 = set_myimg("./img/hl4.xpm", mlx, win);
	ret.hb5 = set_myimg("./img/hl5.xpm", mlx, win);
	ret.bg = set_myimg_new(mlx, WIN_WIDTH, WIN_HEIGHT);
	ret.floor = rgb_to_color(tex->floor);
	ret.ceil = rgb_to_color(tex->ceil);
	return (ret);
}
