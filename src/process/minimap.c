/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:58:20 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/20 22:33:07 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**init_minimap(void)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * 10);
	if (!ret)
		return (NULL);
	while (i < 10)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}

void	draw_minimap(t_pro *p)
{
	char	**minimap;
	int		i;

	i = 0;
	minimap = init_minimap();


	// for (int i = 0; p->map.map[i]; i++)
	// 	printf("p->map.map[i] -> %s\n", p->map.map[i]);
	return;
}


