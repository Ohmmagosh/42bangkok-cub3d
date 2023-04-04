/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:42:46 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/04 16:04:19 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 1000
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
t_txd	init_t_txd( void );
t_tex	init_t_tex( void );
t_txd	init_t_txd_v(char *direct, char *path);
void	init_map_st(t_map *map);
int		*init_array_int(int size);
void	init_xyangle();
void	init_mlx_st(t_mlx *mlx);

//input
int		valid_path_texture(const char **file);
int		valid_color(const char **file);
int		valid_color_num(t_col color);
int		valid_map_char(const char **file);
int		valid_map_char_dup(const char **file);
int		valid_map_wall(const char **file);
char	**get_file_fd(const char *path);
char	**get_texture_2d(char *texture, const char **file);
char	**get_map(const char **file);
void	input_cube(t_pro *p, char *path);
void	valid_path(const char *path);
void	valid_file(const char *path);
void	valid_map(const char *path);
void	valid_texture(const char *path);
t_txd	get_texture(char *texture, const char **file);
t_txd	split_texture_path(char *texture);
t_map	set_map(const char *path);
char	**clean_space(const char **map);
char	**set_map_str(const char **map, int *num_space, int len);
int		*set_numspace_array(const char **map, int *retsize);
int		len_empty_line(const char **map);
int		is_empty_line(const char *line);
t_col	get_color_t_col(const char *color);
t_tex	set_tex(const char **file);
//process
void	process_cube(t_pro *p);
void	anglechange(int keycode, t_pro *p);
void	draw_line(t_mlx *tmlx, t_xy *txy,float ang, int ladex);
void	movechange(int keycode, t_pro *p);
void	showgrid(t_mlx *mlx);
void	draw_wall(t_mlx *tmlx);
void	ini_ray(t_pro *p);
t_xy	get_point_on_circle2(float x, float y, float angle, int radiant);
t_xy	draw_core(t_mlx *tmlx, float g_x, float g_y, float g_angle);
void	draw_plane(t_mlx *tmlx, float g_x, float g_y, float g_angle);

//free
void	free_twod_str(char	**str);
void	free_threed_str(char ***str);
void	free_cube(t_pro *p);

//uitls
int		lenx_map(const char *path);
int		leny_map(const char *path);
int		open_file(const char *path);
int		len_str_2d(const char **str);
void	print_msg_err(char *msg);
void	msg_err(char *msg);
void	print_twod_str(const char **str);
char	*ft_strdup_nonl(char *s);
int		is_inarray(const int *array, int nbr, size_t size);
int		strlen_no_nl(char *s);
int		chrstr_player(char c);

#endif
