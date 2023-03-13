/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:44:08 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/13 18:45:02 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "lib/libft/libft.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("hello main\n");
	print_init();
	print_input();
	print_process();
	print_free();
	ft_putstr_fd("helllo ft", 1);
	return (0);
}
