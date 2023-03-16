/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:40:06 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/17 00:01:54 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_valid(const char *path)
{
	valid_path(path);
	valid_file(path);
	valid_texture(path);
	printf("%s----------valid map----------%s\n", "\e[42m", "\e[0m");
	valid_map(path);
}

void	input_cube(t_pro *p, char *path)
{
	check_valid(path);
	exit(0);
}
