/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <psuanpro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:18 by psuanpro          #+#    #+#             */
/*   Updated: 2023/05/02 12:11:46 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ST_CUB3D_H
# define ST_CUB3D_H

enum texture_direction {
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
} t_vei;

typedef	struct s_vef
{
	float	x;
	float	y;
} t_vef;

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
} t_vec;

typedef struct s_line
{
	float	cameraX;
	float	rayDirX;
	float	rayDirY;
	int		mapX;
	int		mapY;
	t_vef	sidedist;
	t_vef	delta;
	float	perpdist;
	int		side;
	t_vei	step;
	t_vef	pos;
	int		news;
}	t_line;

typedef struct s_txd
{
	char	*direct;
	char	*path;
	void	*img;
	void	*addr;
} t_txd;

typedef struct s_col
{
	int	r;
	int	g;
	int	b;
} t_col;

typedef struct s_tex
{
	t_col	floor;
	t_col	ceil;
	t_txd	no;
	t_txd	so;
	t_txd	we;
	t_txd	ea;
} t_tex;

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
} t_spt;

typedef struct	s_myimg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_myimg;

typedef struct s_render
{
	t_myimg	n;
	t_myimg	s;
	t_myimg	w;
	t_myimg	e;
	t_myimg bg;
	int		floor;
	int		ceil;
} t_ren;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_myimg		img;
} t_mlx;

typedef struct s_pro
{
	t_mlx	mlx;
	t_map	map;
	t_spt	spt;
	t_line	tline;
	t_vef	di;
	t_ren	render;
} t_pro;


#endif
