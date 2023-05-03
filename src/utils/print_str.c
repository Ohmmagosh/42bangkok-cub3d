/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:02:36 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 05:16:23 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_twod_str(const char **str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = (char **)str;
	while (tmp[i])
	{
		ft_printf("tmp[%d] -> %s\n", i, tmp[i]);
		i++;
	}
	return ;
}
