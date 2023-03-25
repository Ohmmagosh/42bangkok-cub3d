/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:38:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/21 20:50:42 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_twod_str(char	**str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
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
}
