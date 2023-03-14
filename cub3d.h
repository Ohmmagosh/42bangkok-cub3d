/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:42:46 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/14 22:01:51 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "color.h"
# include <stdio.h>
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./st_cub3d.h"

//init
void	init_cube(t_pro *p);

//input
void	input_cube(t_pro *p, char *path);

//process
void	process_cube(t_pro *p);

//free
void	free_cube(t_pro *p);

//uitls
void	print_msg_err(char *msg);

#endif
