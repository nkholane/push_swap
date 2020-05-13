/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:18:51 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 15:39:10 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		swap_ab(t_stack *first)
{
	if (first == NULL || first->next == NULL)
		return (0);
	if (ft_lstlen(first) <= 1)
		return (0);
	ft_swap(&first->data, &first->next->data);
	ft_swap(&first->norm, &first->next->norm);
	return (1);
}

void	rotate_ab(t_stack **lst)
{
	t_stack *tmp;
	t_stack *pop;

	if (ft_lstlen(*lst) <= 1)
		return ;
	pop = *lst;
	*lst = (*lst)->next;
	tmp = pop;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	pop->next = NULL;
	tmp->next = pop;
}

void	reverse_rotab(t_stack **lst)
{
	t_stack *tmp;
	t_stack *pop;

	if (ft_lstlen(*lst) <= 1)
		return ;
	pop = *lst;
	tmp = *lst;
	while (pop->next->next != NULL)
	{
		pop = pop->next;
	}
	tmp = pop;
	pop = pop->next;
	tmp->next = NULL;
	pop->next = *lst;
	*lst = pop;
}

void	push_ab(t_stack **first, t_stack **second)
{
	t_stack *stack1;
	t_stack *stack2;

	if (ft_lstlen(*first) < 1)
		return ;
	stack1 = *first;
	stack2 = stack1;
	stack2 = stack2->next;
	stack1->next = NULL;
	stack1->next = *second;
	*second = stack1;
	*first = stack2;
}
