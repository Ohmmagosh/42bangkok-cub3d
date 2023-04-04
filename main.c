/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:44:08 by psuanpro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/04 15:58:53 by psuanpro         ###   ########.fr       */
=======
/*   Updated: 2023/04/03 22:13:20 by rchiewli         ###   ########.fr       */
>>>>>>> 8e8a66fa10d2e85c975242b576f8a6785a0568e5
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_pro	p;

	if (ac == 2)
	{
<<<<<<< HEAD
		//init_cube(&p);
		//input_cube(&p, av[1]);
		process_cube(&p);
=======
		// init_cube(&p);
		init_mlx_st(&p->mlx);
		// input_cube(&p, av[1]);
		process_cube(p);
>>>>>>> 8e8a66fa10d2e85c975242b576f8a6785a0568e5
		//free_cube(&p);
	}
	else{
		print_msg_err("wrong argument!!");
	}
	return (0);
}
