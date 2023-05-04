/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:18 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/04 18:38:53 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ST_CUB3D_H
# define ST_CUB3D_H

enum	e_texture_direction {
	NO,
	SO,
	WE,
	EA,
	F,
	C,
};

typedef struct s_vei
{
	int	x;
	int	y;
}	t_vei;

typedef struct s_vef
{
	float	x;
	float	y;
}	t_vef;

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
}	t_vec;

typedef struct s_line
{
	float	camera_x;
	float	raydir_x;
	float	raydir_y;
	int		map_x;
	int		map_y;
	t_vef	sidedist;
	t_vef	delta;
	float	perpdist;
	int		side;
	t_vei	step;
	t_vef	pos;
	int		news;
	int		wall;
	int		stepcount;
	t_vei	doorpos;
	int		doorflag;
}	t_line;

typedef struct s_txd
{
	char	*direct;
	char	*path;
	void	*img;
	void	*addr;
}	t_txd;

typedef struct s_col
{
	int	r;
	int	g;
	int	b;
}	t_col;

typedef struct s_tex
{
	t_col	floor;
	t_col	ceil;
	t_txd	no;
	t_txd	so;
	t_txd	we;
	t_txd	ea;
}	t_tex;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_minimap
{
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	door;
}	t_mini;

typedef struct s_map
{
	char	**map;
	char	**minimap;
	t_mini	img;
	t_tex	tex;
}	t_map;

typedef struct s_spt
{
	t_vei	pos;
	t_vei	di;
	char	cstart;
	t_vef	plane;
}	t_spt;

typedef struct s_myimg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_myimg;

typedef struct s_wadd
{
	int		height;
	int		d_start;
	int		d_end;
	int		tex_x;
	int		tex_y;
	int		texwidth;
	int		texheight;
	float	step;
	float	texpos;
	float	wall_x;
	int		y;
}	t_wadd;

typedef struct s_render
{
	t_myimg	n;
	t_myimg	s;
	t_myimg	w;
	t_myimg	e;
	t_myimg	bg;
	t_myimg	wall;
	t_myimg	hb0;
	t_myimg	hb1;
	t_myimg	hb2;
	t_myimg	hb3;
	t_myimg	hb4;
	t_myimg	hb5;
	t_myimg	hl0;
	t_myimg	hl1;
	t_myimg	hl2;
	t_myimg	hl3;
	int		floor;
	int		ceil;
}	t_ren;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}	t_mlx;

typedef struct s_pro
{
	t_mlx	mlx;
	t_map	map;
	t_spt	spt;
	t_line	tline;
	t_vef	di;
	t_ren	render;
	int		timer;
	int		chkhand;
}	t_pro;

#endif
