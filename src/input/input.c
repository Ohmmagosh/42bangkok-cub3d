/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:40:06 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/20 22:41:20 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_valid(const char *path)
{
	valid_path(path);
	valid_file(path);
	valid_texture(path);
	valid_map(path);
}

void	variable_set(t_pro *p, const char *path)
{
	p->map = set_map(path);
	p->spt = set_spt(p->map.map);
	for (int i = 0; p->map.map[i]; i++)
	{
		printf("p->map.map[i] -> %s\n", p->map.map[i]);
	}
	exit(0);
}

void	input_cube(t_pro *p, char *path)
{
	check_valid(path);
	variable_set(p, path);
}
