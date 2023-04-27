/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:42:46 by psuanpro          #+#    #+#             */
/*   Updated: 2023/04/26 18:27:39 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define COLOR 0xFFFFFF
# define BLOCK 10

# include "color.h"
# include <stdio.h>
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./st_cub3d.h"



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
t_spt	set_spt(char **map);
t_vei	get_pos_spt(char **map, int mode);
int		findxy_minimap(char **map, int mode);
//process
void	process_cube(t_pro *p);
void	draw_minimap(t_pro *p);
void	key_hook(t_pro *p);
void	lode_start(t_pro *p);
void	wadwaii(float perp, t_pro *p, int i);
void	my_mlx_pixel_put(t_myimg *data, int x, int y, int color);
void	rotate_hook(float	angdegree, t_pro *p);
t_vef	set_plane(char c);

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
