/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:58:58 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/06 17:00:12 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *cdest;
	unsigned char *csrc;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	if (len <= 0)
		return (dest);
	if (csrc < cdest)
	{
		while (len)
		{
			cdest[len - 1] = csrc[len - 1];
			len--;
		}
		return (cdest);
	}
	else
	{
		ft_memcpy(dest, src, len);
		return (cdest);
	}
}
