/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:19:07 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 15:15:44 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ascending(int a, int b)
{
	return (a <= b);
}

t_stack	*sort_list(t_stack *lst, int (*cmp)(int, int))
{
	t_stack	*tmp;

	tmp = lst;
	while (lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			return (0);
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
