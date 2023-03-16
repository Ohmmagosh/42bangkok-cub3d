/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_texture_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:46:15 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/16 23:01:18 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_col	get_color_t_col(const char *color)
{
	char	*tmp;
	char	**rgb;
	t_col	col;

	tmp = (char *)color;
	rgb = ft_split(tmp, ',');
	col.r = ft_atoi(rgb[0]);
	col.g = ft_atoi(rgb[1]);
	col.b = ft_atoi(rgb[2]);
	free_twod_str(rgb);
	rgb = NULL;
	return (col);
}


int	valid_color(const char **file)
{
	int		err;
	t_col	floor;
	t_col	ceil;
	char	***texture;

	err = 0;
	texture = (char ***)malloc(sizeof(char **) * (2));
	texture[0] = get_texture_2d("F ", file);
	texture[1] = get_texture_2d("C ", file);
	texture[2] = NULL;
	floor = get_color_t_col(texture[0][1]);
	ceil = get_color_t_col(texture[1][1]);
	free_threed_str(texture);
	texture = NULL;
	if (valid_color_num(floor) || valid_color_num(ceil))
		err++ ;
	if (err)
		return (1);
	return (0);
}
