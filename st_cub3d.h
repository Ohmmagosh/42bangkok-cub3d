/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:18 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 19:12:10 by psuanpro         ###   ########.fr       */
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
	float	x;
	float	y;
} t_vec;

typedef struct s_spt
{
	t_vec	axis;
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

typedef struct s_map
{
	t_tex	tex;
	char	**map;
} t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
} t_mlx;

typedef struct s_pro
{
	t_mlx	mlx;
	t_map	map;
} t_pro;


#endif
