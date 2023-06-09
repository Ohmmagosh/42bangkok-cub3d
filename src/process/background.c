/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:05:40 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 00:49:51 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	create_background(t_pro *p)
{
	t_vei	vex;

	vex = (t_vei){0, 0};
	while (vex.y < WIN_HEIGHT)
	{
		vex.x = 0;
		while (vex.x < WIN_WIDTH - 1)
		{
			if (vex.y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&p->render.bg, vex.x, vex.y, p->render.ceil);
			else if (vex.y >= WIN_HEIGHT / 2)
				my_mlx_pixel_put(&p->render.bg, vex.x, vex.y, p->render.floor);
			vex.x++;
		}
		vex.y++;
	}
	return ;
}

void	draw_background(t_pro *p)
{
	mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->render.bg.img, 0, 0);
	return ;
}
