/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:01:12 by psuanpro          #+#    #+#             */
/*   Updated: 2022/12/13 20:12:09 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	int				i;

	i = len;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (s == d || len == 0)
		return (dst);
	if (d < s)
		while (i--)
			*d++ = *s++;
	else
	{
		s = s + len - 1;
		d = d + len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
