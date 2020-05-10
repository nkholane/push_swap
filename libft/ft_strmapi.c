/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:05:35 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/27 12:59:59 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;

	if (s == NULL && f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (1 + len));
	if (!new)
		return (NULL);
	len = 0;
	while (s[len])
	{
		new[len] = f(len, s[len]);
		len++;
	}
	new[len] = '\0';
	return (new);
}
