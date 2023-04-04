/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:40:06 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/30 09:43:45 by psuanpro         ###   ########.fr       */
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
}

void	input_cube(t_pro *p, char *path)
{
	check_valid(path);
	variable_set(p, path);
}
