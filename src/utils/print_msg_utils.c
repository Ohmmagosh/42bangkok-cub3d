/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:56:35 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/14 21:17:13 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_msg_err(char *msg)
{
	ft_putstr_fd(BRED, 2);
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RES, 2);
	ft_putstr_fd("\n", 2);
	return ;
}
