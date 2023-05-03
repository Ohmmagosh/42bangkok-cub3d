/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:06:11 by rchiewli          #+#    #+#             */
/*   Updated: 2023/05/04 04:19:22 by rchiewli         ###   ########.fr       */
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
	mini.door = init_img(p->mlx.mlx, "./img/door15px.xpm");
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

void	put_img_to_win(t_pro *p, int mode, t_vei pic)
{
	if (mode == 1)
		mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
									p->map.img.wall.img, pic.x, pic.y);
	else if (mode == 2)
		mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
									p->map.img.floor.img, pic.x, pic.y);
	else if (mode == 3)
		mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
									p->map.img.door.img, pic.x, pic.y);
	else if (mode == 4)
	{
		mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
									p->map.img.floor.img, pic.x, pic.y);
		mlx_put_image_to_window(p->mlx.mlx, p->mlx.win, \
									p->map.img.player.img, pic.x, pic.y);
	}
	return ;
}
