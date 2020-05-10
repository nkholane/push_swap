/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:05:26 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 15:27:25 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"
#include "libft.h"

int		sort_int_tab(int *tab, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (tab[j + 1] == tab[j])
				return (0);
			if (tab[j + 1] < tab[j])
			{
				ft_swap(&tab[j + 1], &tab[j]);
			}
			j++;
		}
		i++;
	}
	return (1);
}
