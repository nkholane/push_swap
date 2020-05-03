/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:02:57 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 14:02:57 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

static int			ft_strc(char const *s)
{
	int		i;
	int		count;
	int		len;

	len = ft_strlen(s);
	i = 0;
	count = 0;
	while (i < len)
	{
		while (ft_isspace(s[i]) == 1 && s[i] != '\0')
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
		while (ft_isspace(s[i]) != 1 && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void			ft_strpull(int w, char **ret, char *str)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[len] && ft_isspace(str[len]) == 0)
		len++;
	ret[w] = (char*)malloc(len + 1);
	while (i < len)
	{
		ret[w][i] = *str;
		i++;
		str++;
	}
	ret[w][i] = '\0';
}

char				**ft_split(char *str)
{
	int		words;
	char	**ret;
	int		i;

	words = ft_strc(str);
	ret = (char**)malloc(sizeof(*ret) * words + 1);
	i = 0;
	while (i < words)
	{
		while (ft_isspace(*str) == 1 && *str != '\0')
			str++;
		ft_strpull(i, ret, str);
		while (ft_isspace(*str) != 1 && *str != '\0')
			str++;
		i++;
	}
	ret[words] = NULL;
	return (ret);
}
