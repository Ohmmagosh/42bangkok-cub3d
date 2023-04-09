/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:44:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/05 23:25:12 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_pro	p;

	if (ac == 2)
	{
		// init_cube(&p);
		//init_mlx_st(&p->mlx);
		// input_cube(&p, av[1]);
		process_cube(&p);
		//free_cube(&p);
	}
	else{
		print_msg_err("wrong argument!!");
	}
	return (0);
}

