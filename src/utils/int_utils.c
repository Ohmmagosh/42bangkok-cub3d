/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:17:52 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/18 03:18:11 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	is_inarray(const int *array, int nbr, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
