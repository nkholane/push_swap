/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:22:17 by nkholane          #+#    #+#             */
/*   Updated: 2019/06/06 15:09:58 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	buf = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buf[i] = 0;
		i++;
	}
}
