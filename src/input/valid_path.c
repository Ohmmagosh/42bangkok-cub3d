/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:45:56 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/30 20:43:56 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_valid_path(const char *path, char *suffix)
{
	char	*tmp;

	tmp = (char *)path;
	if (!ft_strncmp(tmp + ft_strlen(tmp) - 4, suffix, ft_strlen(suffix) + 1))
		return (1);
	return (0);
}

void	valid_path(const char *path)
{
	int	error;

	error = 0;
	if (!check_valid_path(path, ".cub"))
		error++ ;
	if (error != 0)
		print_msg_err("incorrect path!!");
	return ;
}
