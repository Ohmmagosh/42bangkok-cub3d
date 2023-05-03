/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:36:20 by rchiewli          #+#    #+#             */
/*   Updated: 2023/05/04 04:29:47 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	hand_animation_utils(t_pro *p)
{
	if (p->chkhand == 0)
	{
		if (p->timer % 60 >= 0 && p->timer % 60 <= 10)
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hl0.img, 450, 490);
		else if ((p->timer % 60 >= 11 && p->timer % 60 <= 20) || \
					(p->timer % 60 >= 51 && p->timer % 60 <= 60))
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hl1.img, 450, 490);
		else if ((p->timer % 60 >= 21 && p->timer % 60 <= 30) || \
					(p->timer % 60 >= 41 && p->timer % 60 <= 50))
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hl2.img, 450, 490);
		else if (p->timer % 60 >= 31 && p->timer % 60 <= 40)
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hl3.img, 450, 490);
	}
	return ;
}

void	hand_animation(t_pro *p)
{
	if (p->chkhand == 1 || p->chkhand == 2)
	{
		if (p->chkhand == 1)
		{
			p->timer = 0;
			p->chkhand = 2;
		}
		else if (p->timer % 30 >= 5 && p->timer % 30 <= 9)
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hb2.img, 40, 320);
		else if (p->timer % 30 >= 10 && p->timer % 30 <= 14)
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hb3.img, 40, 320);
		else if (p->timer % 30 >= 15 && p->timer % 30 <= 19)
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hb4.img, 40, 320);
		else if (p->timer % 30 >= 20 && p->timer % 30 <= 24)
			mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
										p->render.hb5.img, 40, 320);
		else if (p->timer % 30 == 29)
			p->chkhand = 0;
	}
	hand_animation_utils(p);
	return ;
}
