/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:42:46 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 22:29:43 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define COLOR 0xFFFFFF

# include "color.h"
# include <stdio.h>
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./st_cub3d.h"

float	g_xstart;
float	g_ystart;
float	g_angle;
int		g_gridsize;
int		g_linecounter;

//init
void	init_cube(t_pro *p);
void	init_xyangle();

//input
void	input_cube(t_pro *p, char *path);
void	valid_path(const char *path);
void	valid_file(const char *path);
void	valid_map(char *path);
void	valid_texture(const char *path);
char	**get_file_fd(const char *path);

//process
void	process_cube(t_pro *p);
void	anglechange(int keycode, t_pro *p);
void	draw_line(t_mlx *tmlx, t_xy *txy,float ang);
void	movechange(int keycode, t_pro *p);
void	showgrid(t_mlx *mlx);

//free
void	free_twod_str(char	**str);


//uitls
int		lenx_map(const char *path);
int		leny_map(const char *path);
void	print_msg_err(char *msg);
void	msg_err(char *msg);
void	print_twod_str(const char **str);

#endif
