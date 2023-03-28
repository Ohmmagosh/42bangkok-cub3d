/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:40:06 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/26 23:42:11 by psuanpro         ###   ########.fr       */
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
	//for (int i = 0; p->map.map[i]; i++)
	//	printf("map[%d] -> %s\n", i, p->map.map[i]);
	//printf("%s----------texture----------%s\n", "\e[42m", "\e[0m");
	//printf("ceil r -> %d\n", p->map.tex.ceil.r);
	//printf("ceil g -> %d\n", p->map.tex.ceil.g);
	//printf("ceil b -> %d\n", p->map.tex.ceil.b);
	//printf("floor r -> %d\n", p->map.tex.floor.r);
	//printf("floor g -> %d\n", p->map.tex.floor.g);
	//printf("floor b -> %d\n", p->map.tex.floor.b);
	//printf("p->map.tex.ea.direct -> %s\n", p->map.tex.ea.direct);
	//printf("p->map.tex.ea.path -> %s\n", p->map.tex.ea.path);
	//printf("p->map.tex.so.direct -> %s\n", p->map.tex.so.direct);
	//printf("p->map.tex.so.path -> %s\n", p->map.tex.so.path);
	//printf("p->map.tex.we.direct -> %s\n", p->map.tex.we.direct);
	//printf("p->map.tex.we.path -> %s\n", p->map.tex.we.path);
	//printf("p->map.tex.no.direct -> %s\n", p->map.tex.no.direct);
	//printf("p->map.tex.no.path -> %s\n", p->map.tex.no.path);
}

void	input_cube(t_pro *p, char *path)
{
	check_valid(path);
	variable_set(p, path);
}
