/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:26:46 by nkholane          #+#    #+#             */
/*   Updated: 2020/02/25 13:26:49 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strswap(char *a, char *b)
{
	char	*temp;

	temp = a;
	a = ft_strcpy(a, b);
	b = ft_strcpy(b, temp);
}