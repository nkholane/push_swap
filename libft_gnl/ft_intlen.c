/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:49:42 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 12:49:45 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	int		temp;
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	temp = n;
	if (n < 0)
	{
		i++;
		temp *= -1;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}
