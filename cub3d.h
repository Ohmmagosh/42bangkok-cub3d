/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:42:46 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 18:37:04 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH 1290
# define WIN_HEIGHT 720
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
void	init_xyangle(void);
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
t_ren	set_render(t_tex *tex, void *mlx, void *win);
t_line	set_tline(t_vei *pos);
t_myimg	set_myimg(char *path, void *mlx, void *win);
t_myimg	set_myimg_new(void *mlx, int width, int height);

//process
void	process_cube(t_pro *p);
void	draw_minimap(t_pro *p);
void	key_hook(t_pro *p);
void	lode_start(t_pro *p);
void	wadwaii(float perp, t_pro *p, int i);
void	my_mlx_pixel_put(t_myimg *data, int x, int y, int color);
void	rotate_hook(float angdegree, t_pro *p);
t_vef	set_plane(char c);
int		mouse_hook(int button, int x, int y, t_pro *p);
void	create_background(t_pro *p);
void	draw_background(t_pro *p);
void	hand_animation(t_pro *p);
int		close_win(t_pro *p);
char	**init_minimap(void);
t_img	init_img(void *mlx, char *path);
t_mini	init_minimap_img(t_pro *p);
void	create_minimap(t_vei pos, t_pro *p);
void	put_img_to_win(t_pro *p, int mode, t_vei pic);
int		iswall(int x, int y, t_pro *p);
void	lode_start_tline_init(t_pro *p, int i);
void	key_3(t_pro *p, float step);
void	key_13(t_pro *p, float step);
void	key_0_or_2(t_pro *p, float step, int key);
void	key_1(t_pro *p, float step);
void	getdoorpos(int x, int y, t_pro *p);

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
