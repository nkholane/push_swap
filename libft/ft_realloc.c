/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkholane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:26:06 by nkholane          #+#    #+#             */
/*   Updated: 2020/02/25 13:26:09 by nkholane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(char **str, size_t new_size)
{
	char	*temp;

	temp = str[0];
	str[0] = ft_strnew(new_size);
	if (str[0] != NULL)
	{
		ft_strcpy(str[0], temp);
		ft_strdel(&temp);
	}
}
