/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:07 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 14:47:21 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_xyangle()
{
	g_xstart = 250;
	g_ystart = 250;
	g_angle = 270;
}

void	init_mlx_st(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
}

void	init_map_st(t_map *map)
{
	map->map = NULL;
}

void	init_pro(t_pro *p)
{
	init_mlx_st(&p->mlx);
	init_map_st(&p->map);
}

void	init_cube(t_pro *p)
{
	init_pro(p);
	return ;
}

