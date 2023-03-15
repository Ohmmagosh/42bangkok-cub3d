/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:45:56 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/15 23:41:14 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_valid_path(const char *path)
{
	char	*tmp;

	tmp = (char *)path;
	if (!ft_strncmp(tmp + ft_strlen(tmp) - 4, ".cub", 5))
		return (1);
	return (0);
}

void	valid_path(const char *path)
{
	int	error;

	error = 0;
	if (!check_valid_path(path))
		error++ ;
	if (error != 0)
		print_msg_err("incorrect path!!");
	return ;
}
