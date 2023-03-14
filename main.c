/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:44:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/14 21:16:32 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "lib/libft/libft.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		for (int i = 0; av[i]; i++)
			ft_putendl_fd(av[i], 1);
	}
	else{
		print_msg_err("wrong argument!!");
	}
	return (0);
}
