/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:53:23 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 15:15:44 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr(const char *s, char **dest, char c, size_t w)
{
	size_t	i;
	size_t	n;
	size_t	a;

	i = 0;
	a = 0;
	if (!dest)
		return (NULL);
	while (s[i] && a < w)
	{
		n = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			n++;
			i++;
		}
		dest[a] = ft_strsub(s, i - n, n);
		a++;
	}
	dest[a] = (NULL);
	return (dest);
}
