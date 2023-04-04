/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:07 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/04 15:56:04 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_xyangle()
{
	// char tmp[6][6] = {{'1', '1', '1', '1', '1'}, {'1', '0', '0', '0', '1'}, {'1', '0', '1', '0', '1'}, {'1', '0', '0', '0', '1'}, {'1', '1', '1', '1', '1'}, {NULL}};
	g_xstart = 250;
	g_ystart = 250;
	g_angle = 270;
	g_gridsize = 75;
	g_linecounter = 0;
	// g_map = {{'1', '1', '1', '1', '1'}, {'1', '0', '0', '0', '1'}, {'1', '0', '1', '0', '1'}, {'1', '0', '0', '0', '1'}, {'1', '1', '1', '1', '1'}, {NULL}};
}

void	init_mlx_st(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->larray = malloc(sizeof(t_linearray) * 7);
}


void	init_map_st(t_map *map)
{
	map->map = NULL;
	map->tex = init_t_tex();
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

/*
11111
10001
10101
10N01
11111
*/
