/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:01:45 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 04:33:55 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate_hook(float angdegree, t_pro *p)
{
	float	angrad;
	float	olddirx;
	float	oldplanex;

	angrad = angdegree * (M_PI / 180.0);
	olddirx = p->di.x;
	oldplanex = p->spt.plane.x;
	p->di.x = (p->di.x * cos(angrad)) - (p->di.y * sin(angrad));
	p->di.y = (olddirx * sin(angrad)) + (p->di.y * cos(angrad));
	p->spt.plane.x = (p->spt.plane.x * cos(angrad)) - \
							(p->spt.plane.y * sin(angrad));
	p->spt.plane.y = (oldplanex * sin(angrad)) + \
							(p->spt.plane.y * cos(angrad));
	return ;
}

int	mouse_hook(int button, int x, int y, t_pro *p)
{
	if (button == 4)
		rotate_hook(-5.0, p);
	else if (button == 5)
		rotate_hook(5.0, p);
	return (0);
}

int	close_win(t_pro *p)
{
	mlx_destroy_window(p->mlx.mlx, p->mlx.win);
	exit (0);
}
