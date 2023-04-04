/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:07 by psuanpro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/04 15:56:04 by psuanpro         ###   ########.fr       */
=======
/*   Updated: 2023/04/03 22:13:13 by rchiewli         ###   ########.fr       */
>>>>>>> 8e8a66fa10d2e85c975242b576f8a6785a0568e5
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_mlx_st(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->tline = malloc(sizeof(t_linearray) * 7);
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
