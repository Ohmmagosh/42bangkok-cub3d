/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 23:34:29 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_mlx_pixel_put(t_myimg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	render(t_pro *p)
{
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	draw_background(p);
	lode_start(p);
	draw_minimap(p);

	return (0);
}

void process_cube(t_pro *p)
{
	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	p->render = set_render(&p->map.tex, p->mlx.mlx, p->mlx.win);
	p->spt.plane = set_plane(p->spt.cstart);
	p->di.x = (float)p->spt.di.x;
	p->di.y = (float)p->spt.di.y;
	p->tline.pos = (t_vef){p->spt.pos.x + 0.5, p->spt.pos.y + 0.5};
	create_background(p);

	mlx_loop_hook(p->mlx.mlx, render, p);
	key_hook(p);
	mlx_loop(p->mlx.mlx);
}
