/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:56:28 by psuanpro          #+#    #+#             */
/*   Updated: 2023/03/23 22:51:15 by psuanpro         ###   ########.fr       */
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

int	strlen_no_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_nonl(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char *) * (strlen_no_nl(s) + 1));
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

int	chrstr_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}
