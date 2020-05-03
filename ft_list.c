/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:20:05 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 12:20:09 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*ft_intlstnew(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		return (NULL);
	}
	new->data = -3;
	new->norm = -3;
	new->next = NULL;
	return (new);
}

int			ft_lstlen(t_stack *lst)
{
	int		c;
	t_stack	*tmp;

	c = 0;
	tmp = lst;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	lst = tmp;
	return (c);
}

int			acending(int a, int b)
{
	return (a <= b);
}

void		del_extra(t_stack *lst)
{
	t_stack *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next->norm < 0)
			tmp->next = NULL;
		tmp = tmp->next;
	}
	free(tmp);
}
