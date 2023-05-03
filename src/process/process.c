/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:41:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 05:00:17 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	my_mlx_pixel_put(t_myimg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	render(t_pro *p)
{
	mlx_clear_window(p->mlx.mlx, p->mlx.win);
	lode_start(p);
	hand_animation(p);
	draw_minimap(p);
	p->timer++;
	return (0);
}

void	process_cube(t_pro *p)
{
	p->mlx.mlx = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	p->tline = set_tline(&p->spt.pos);
	p->timer = 0;
	p->chkhand = 0;
	p->render = set_render(&p->map.tex, p->mlx.mlx, p->mlx.win);
	p->spt.plane = set_plane(p->spt.cstart);
	p->di = (t_vef){(float)p->spt.di.x, (float)p->spt.di.y};
	create_background(p);
	mlx_loop_hook(p->mlx.mlx, render, p);
	key_hook(p);
	mlx_loop(p->mlx.mlx);
}
