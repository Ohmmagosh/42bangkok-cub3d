/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:23:49 by psuanpro          #+#    #+#             */
/*   Updated: 2022/03/27 22:20:01 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_countword(char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (*s != '\0' && *s != c)
		j += 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			j += 1;
		i++;
	}
	return (j + 1);
}

static	size_t	ft_countcword(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] == c)
		i++;
	while (i < len && s[i])
	{
		if (s[i] == c)
		{
			i++;
			break ;
		}
		i++;
		j++;
	}
	return (j + 1);
}

static	char	*ft_getword(char *s, char c)
{
	char	*str;

	str = malloc(sizeof(char) * ft_countcword(s, c));
	while (*s == c)
	{
		s++;
	}
	ft_strlcpy(str, s, ft_countcword(s, c));
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		i;
	int		sl;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	tmp = (char *)s;
	sl = ft_countword(tmp, c);
	array = (char **)malloc(ft_countword(tmp, c) * (sizeof(char *)));
	if (!array)
		return (NULL);
	while (i < sl - 1)
	{
		while (*tmp == c)
			tmp++;
		array[i] = ft_getword(tmp, c);
		tmp += ft_countcword(tmp, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
