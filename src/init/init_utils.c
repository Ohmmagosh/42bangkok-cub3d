/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:38:55 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/26 18:19:12 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_txd	init_t_txd( void )
{
	t_txd	tdetail;

	tdetail.direct = NULL;
	tdetail.path = NULL;
	return (tdetail);
}

t_tex	init_t_tex( void )
{
	t_tex	texture;

	texture.ea = init_t_txd();
	texture.no = init_t_txd();
	texture.so = init_t_txd();
	texture.we = init_t_txd();
	return (texture);
}

t_txd	init_t_txd_v(char *direct, char *path)
{
	t_txd	tdtail;

	tdtail.direct = ft_strdup(direct);
	tdtail.path = ft_strdup(path);
	return (tdtail);
}

int	*init_array_int(int size)
{
	int	*ret;

	ret = 0;
	ret = (int *)malloc(sizeof(int) * size);
	if (!ret)
		return (0);
	return (ret);
}
