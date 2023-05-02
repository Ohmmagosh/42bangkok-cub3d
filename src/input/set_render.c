/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:07:58 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 12:13:36 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
int	rgb_to_color(t_col col)
{
	int ret;

	ret |= col.r << 16;
	ret |= col.g << 8;
	ret |= col.b;
	return ret;
}

t_ren	set_render(t_tex *tex, void *mlx, void *win)
{
	t_ren	ret;

	ret.w.img = mlx_xpm_file_to_image(mlx, tex->we.path, &ret.w.line_length, &ret.w.bits_per_pixel);
	ret.n.img = mlx_xpm_file_to_image(mlx, tex->no.path, &ret.n.line_length, &ret.n.bits_per_pixel);
	ret.e.img = mlx_xpm_file_to_image(mlx, tex->ea.path, &ret.e.line_length, &ret.e.bits_per_pixel);
	ret.s.img = mlx_xpm_file_to_image(mlx, tex->so.path, &ret.s.line_length, &ret.w.bits_per_pixel);
	ret.w.addr = mlx_get_data_addr(ret.w.img, &ret.w.bits_per_pixel, &ret.w.line_length, &ret.w.endian);
	ret.n.addr = mlx_get_data_addr(ret.n.img, &ret.n.bits_per_pixel, &ret.n.line_length, &ret.n.endian);
	ret.e.addr = mlx_get_data_addr(ret.e.img, &ret.e.bits_per_pixel, &ret.e.line_length, &ret.e.endian);
	ret.s.addr = mlx_get_data_addr(ret.s.img, &ret.s.bits_per_pixel, &ret.s.line_length, &ret.s.endian);
	ret.bg.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	ret.bg.addr = mlx_get_data_addr(ret.bg.img, &ret.bg.bits_per_pixel, &ret.bg.line_length, &ret.bg.endian);
	ret.floor = rgb_to_color(tex->floor);
	ret.ceil = rgb_to_color(tex->ceil);
	return (ret);
}
