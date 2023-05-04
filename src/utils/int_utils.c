/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:17:52 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/05 02:13:01 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../cub3d.h"

int	is_inarray(const int *array, int nbr, size_t size)
{
	int	i;

	i = 0;
	while (i < (int)size)
	{
		if (array[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
