/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:47:42 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/16 19:29:39 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	valid_file(const char *path)
{
	int error;

	error = 0;
	if (!open_file(path))
		error++ ;
	if (error != 0)
		print_msg_err("file not found!!");
	return ;
}
