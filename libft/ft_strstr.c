/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:07:04 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/27 13:06:00 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	len = 0;
	while (needle[len] != '\0')
		len++;
	if (len == 0)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		count = 0;
		while (needle[count] == haystack[i + count])
		{
			if (needle[count + 1] == '\0')
				return ((char*)haystack + i);
			count++;
		}
		i++;
	}
	return (NULL);
}
