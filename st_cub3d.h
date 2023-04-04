/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:18 by psuanpro          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/04 16:04:06 by psuanpro         ###   ########.fr       */
=======
/*   Updated: 2023/04/03 23:40:21 by rchiewli         ###   ########.fr       */
>>>>>>> 8e8a66fa10d2e85c975242b576f8a6785a0568e5
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

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
} t_vec;

<<<<<<< HEAD
typedef struct s_xy
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;

} t_xy;

typedef struct s_coord
{
	float x;
	float y;
=======
typedef struct s_coord{
    float x;
    float y;
>>>>>>> 8e8a66fa10d2e85c975242b576f8a6785a0568e5
}	t_coord;

typedef struct s_line
{
<<<<<<< HEAD
	t_coord p1;
	t_coord p2;

}	t_Line;

typedef struct s_linearray
{
	int		linenum;
	float	x2;
	float	y2;
=======
	t_coord costart;
	t_coord costop;
>>>>>>> 8e8a66fa10d2e85c975242b576f8a6785a0568e5
	float	distance;
}	t_line;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_spt
{
	t_vec	axis;
	int		di;
} t_spt;

typedef struct s_col
{
	int	r;
	int	g;
	int	b;
} t_col;

typedef struct s_txd
{
	char	*direct;
	char	*path;
} t_txd;

typedef struct s_tex
{
	t_col	floor;
	t_col	ceil;
	t_txd	no;
	t_txd	so;
	t_txd	we;
	t_txd	ea;
} t_tex;

typedef struct	s_hwa
{
	float	xstart;
	float	ystart;
	float	angle;
} t_hwa;

typedef struct	s_myimg
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_myimg;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_myimg		img;
	t_line		*tline;
} t_mlx;

typedef struct s_pro
{
	t_mlx	mlx;
	t_map	map;
} t_pro;


#endif
