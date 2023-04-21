/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:52:09 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/19 14:42:35 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_empty_line(const char *line)
{
	int	len;
	int i;

	i = 0;
	len = ft_strlen((char *)line);
	if (len == 0)
		return (1);
	while (line[i] && line[i] == ' ' )
		i++;
	if (i == len)
		return (1);
	return (0);
}

