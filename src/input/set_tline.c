/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:51:58 by rchiewli          #+#    #+#             */
/*   Updated: 2023/05/03 22:57:13 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_line	set_tline(t_vei *pos)
{
	t_line	ret;

	ret.stepcount = 0;
	ret.doorflag = 0;
	ret.doorpos = (t_vei){-1, -1};
	ret.pos = (t_vef){pos->x + 0.5, pos->y + 0.5};
	return (ret);
}
