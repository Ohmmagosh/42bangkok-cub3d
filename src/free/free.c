/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:38:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/30 09:57:15 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_twod_str(char	**str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++ ;
	}
	free(str);
	return ;
}

void	free_threed_str(char ***str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		free_twod_str(str[i]);
		str[i] = NULL;
		i++ ;
	}
	free(str);
	str = NULL;
	return ;
}

void	free_t_tex(t_tex *tex)
{
	free(tex->no.direct);
	free(tex->no.path);
	free(tex->so.direct);
	free(tex->so.path);
	free(tex->we.direct);
	free(tex->we.path);
	free(tex->ea.direct);
	free(tex->ea.path);
}

void	free_t_map(t_map *map)
{
	free_twod_str(map->map);
	free_t_tex(&map->tex);
	map->map = NULL;
}

void	free_cube(t_pro *p)
{
	free_t_map(&p->map);
}
