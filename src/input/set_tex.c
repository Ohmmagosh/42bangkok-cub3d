/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:54:17 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/21 00:17:57 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_tex	set_tex(const char **file)
{
	t_tex	ret;
	char	***texture;

	texture = (char ***)malloc(sizeof(char **) * (2));
	texture[0] = get_texture_2d("F ", file);
	texture[1] = get_texture_2d("C ", file);
	texture[2] = NULL;
	ret.floor = get_color_t_col(texture[0][1]);
	ret.ceil = get_color_t_col(texture[1][1]);
	ret.ea = get_texture("EA ", file);
	ret.no = get_texture("NO ", file);
	ret.so = get_texture("SO ", file);
	ret.we = get_texture("WE ", file);
	free_threed_str(texture);
	texture = NULL;
	return (ret);
}
