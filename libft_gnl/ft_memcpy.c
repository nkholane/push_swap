/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:02:21 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/06 15:33:05 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*i;
	char	*j;

	if (n == 0 || dst == src)
		return (dst);
	i = (char *)dst;
	j = (char *)src;
	while (--n)
		*i++ = *j++;
	*i = *j;
	return (dst);
}
