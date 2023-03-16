/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:56:28 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/17 01:13:41 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	len_str_2d(const char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++ ;
	return (len);
}

char	*ft_strdup_nonl(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	ret = (char *)malloc(sizeof(char *) * (ft_strlen_gnl(s) + 1));
	if (!ret)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
