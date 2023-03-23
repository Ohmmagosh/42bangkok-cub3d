/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:44:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 14:26:44 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_pro	*p;

	p = malloc(sizeof(t_pro));
	if (ac == 2)
	{
		// init_cube(&p);
		init_xyangle();
		// input_cube(&p, av[1]);
		process_cube(p);
		//free_cube(&p);
	}
	else{
		print_msg_err("wrong argument!!");
	}
	return (0);
}
