/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:42:46 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/17 01:54:34 by psuanpro         ###   ########.fr       */
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
# include <fcntl.h>
# include "./st_cub3d.h"

//init
void	init_cube(t_pro *p);
t_txd	init_t_txd( void );
t_tex	init_t_tex( void );
t_txd	init_t_txd_v(char *direct, char *path);

//input
int		valid_path_texture(const char **file);
int		valid_color(const char **file);
int		valid_color_num(t_col color);
char	**get_file_fd(const char *path);
char	**get_texture_2d(char *texture, const char **file);
char	**get_map(const char **file);
void	input_cube(t_pro *p, char *path);
void	valid_path(const char *path);
void	valid_file(const char *path);
void	valid_map(const char *path);
void	valid_texture(const char *path);
int		valid_map_char(const char **file);
int		valid_map_char_dup(const char **file);
t_txd	get_texture(char *texture, const char **file);
t_txd	split_texture_path(char *texture);

//process
void	process_cube(t_pro *p);

//free
void	free_twod_str(char	**str);
void	free_threed_str(char ***str);

//uitls
int		lenx_map(const char *path);
int		leny_map(const char *path);
int		open_file(const char *path);
int		len_str_2d(const char **str);
void	print_msg_err(char *msg);
void	msg_err(char *msg);
void	print_twod_str(const char **str);
char	*ft_strdup_nonl(char *s);

#endif
