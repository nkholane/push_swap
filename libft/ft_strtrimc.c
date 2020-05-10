/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 18:40:16 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 16:08:02 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*t;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] == c && s[i])
		i++;
	while (s[j - 1] == c)
		j--;
	if (i > j)
		return ("");
	n = (j - i);
	t = (char *)ft_strsub(s, i, n);
	if (!t)
		return (NULL);
	t[n] = '\0';
	return (t);
}
