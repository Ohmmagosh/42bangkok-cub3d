/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:58:20 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/29 00:15:56 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**init_minimap(void)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * 10);
	if (!ret)
		return (NULL);
	while (i < 10)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}

t_img	init_img(void *mlx, char *path)
{
	t_img	ret;

	ret.img = mlx_xpm_file_to_image(mlx, path, &ret.width, &ret.height);
	return (ret);
}

t_mini	init_minimap_img(t_pro *p)
{
	t_mini	mini;

	mini.wall = init_img(p->mlx.mlx, "./img/wall15px.xpm");
	mini.floor = init_img(p->mlx.mlx, "./img/floor15px.xpm");
	mini.player = init_img(p->mlx.mlx, "./img/player15px.xpm");
	return (mini);
}

void	create_minimap(t_vei pos, t_pro *p)
{
	t_vei	vx;

	vx = (t_vei){10, 10};
	if (pos.y - 5 < 0)
		pos.x = 0;
	if (pos.y - 5 < 0)
		pos.y = 0;
	while (p->map.map[pos.y] && vx.y < 10)
	{
		vx.x = 0;
		while (p->map.map[pos.y][pos.x] && vx.x < 10)
			vx.x++;
		vx.y++;
	}
}


void	draw_minimap(t_pro *p)
{
	t_vei	pic;
	t_vei	len;
	t_vei	pos;
	t_vei	pic_d;

	pic_d = (t_vei){0, 0};
	pos = get_pos_spt(p->map.map, 1);
	pic = (t_vei){10, 10};
	p->map.img = init_minimap_img(p);
	if (pos.x - 5 < 0)
		pos.x = 0;
	if (pos.y - 5 < 0)
	{
		pos.y = 0;
		len.y = 0;
	}
	if (pos.y != 0)
		len.y = pos.y - 5;
	while (p->map.map[len.y] && pic_d.y < 10)
	{
		len.x = pos.x - 5;
		if (len.x < 0)
			len.x = 0;
		pic.x = 10;
		pic_d.x = 0;
		while (p->map.map[len.y][len.x] && pic_d.x < 10)
		{
			if (p->map.map[len.y][len.x] == '1')
				mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->map.img.wall.img, pic.x, pic.y);
			else if (p->map.map[len.y][len.x] == '0')
				mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->map.img.floor.img, pic.x, pic.y);
			else if (p->map.map[len.y][len.x] == 'P')
			{
				mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->map.img.floor.img, pic.x, pic.y);
				mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, p->map.img.player.img, pic.x, pic.y);
			}
			pic.x+=15;
			len.x++;
			pic_d.x++;
		}
		pic_d.y++;
		pic.y+=15;
		len.y++;
	}
	return;
}


