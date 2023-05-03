/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:58:20 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 04:09:44 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_img_to_win_utils(int *pic, int *len, int *pic_d)
{
	(*pic) += 15;
	(*len)++;
	(*pic_d)++;
}

void	draw_minmap_utils(int *posx, int *posy, int *leny)
{
	if ((*posx) - 5 < 0)
		(*posx) = 0;
	if (((*posy)) - 5 < 0)
	{
		((*posy)) = 0;
		(*leny) = 0;
	}
	if (((*posy)) != 0)
		(*leny) = ((*posy)) - 5;
	return ;
}

void	draw_minmap_utils2(int *picx, int *pic_dx, int *posx, int *lenx)
{
	(*lenx) = (*posx) - 5;
	if ((*lenx) < 0)
		(*lenx) = 0;
	(*picx) = 10;
	(*pic_dx) = 0;
	return ;
}

void	draw_minimap_utils3(t_pro *p, char c, t_vei pic)
{
	if (c == '1')
		put_img_to_win(p, 1, pic);
	else if (c == '0')
		put_img_to_win(p, 2, pic);
	else if (c == 'D')
		put_img_to_win(p, 3, pic);
	else if (c == 'P')
		put_img_to_win(p, 4, pic);
}

void	draw_minimap(t_pro *p)
{
	t_vei	pic;
	t_vei	len;
	t_vei	pos;
	t_vei	pic_d;

	pic_d = (t_vei){0, 0};
	pic = (t_vei){10, 10};
	pos = get_pos_spt(p->map.map, 1);
	p->map.img = init_minimap_img(p);
	draw_minmap_utils(&(pos).x, &(pos).y, &(len).y);
	while (p->map.map[len.y] && pic_d.y < 10)
	{
		draw_minmap_utils2(&(pic).x, &(pic_d).x, &(pos).x, &(len).x);
		while (p->map.map[len.y][len.x] && pic_d.x < 10)
		{
			draw_minimap_utils3(p, p->map.map[len.y][len.x], pic);
			put_img_to_win_utils(&pic.x, &len.x, &pic_d.x);
		}
		put_img_to_win_utils(&pic.y, &len.y, &pic_d.y);
	}
	return ;
}
