/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:18 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 14:24:38 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ST_CUB3D_H
# define ST_CUB3D_H

typedef struct s_vec
{
	int	x;
	int	y;
	int	z;
} t_vec;

typedef struct s_xy
{
	float	x1;
	float	y1;
	float	x2;
	float	y2;

} t_xy;

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_spt
{
	t_vec	axis;
} t_spt;

typedef struct s_tex
{

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
	void	*mlx;
	void	*win;
	t_xy	*txy;
	t_myimg	img;
	t_hwa	*hwa;
} t_mlx;

typedef struct s_var
{
	char	*file;


} t_var;

typedef struct s_pro
{
	t_mlx	mlx;
	t_map	map;
} t_pro;


#endif
