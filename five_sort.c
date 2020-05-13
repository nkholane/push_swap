/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 09:46:14 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/13 10:44:10 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_five(t_lists *head)
{
	while (ft_lstlen(head->lst_a) > 3)
	{
		if (find_next(head, ft_lstlen(head->lst_a), 1) == 0)
		{
			while (head->lst_a->puts > 1)
			{
				RA;
				rotate_ab(&head->lst_a);
			}
			PB;
			push_ab(&head->lst_a, &head->lst_b);
		}
		else
		{
			while (head->lst_a->puts > 1)
			{
				RRA;
				reverse_rotab(&head->lst_a);
			}
			PB;
			push_ab(&head->lst_a, &head->lst_b);
		}
	}
	three_sort(head);
	pushback_a(head);
}

int		find_next(t_lists *head, int len, int range)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = head->lst_a;
	while (tmp)
	{
		if (tmp->puts >= (len - range))
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int		pushback_a(t_lists *head)
{
	int n;

	n = find_high(head);
	while (ft_lstlen(head->lst_b) > 0)
	{
		if (head->lst_b->puts == n)
		{
			PA;
			push_ab(&head->lst_b, &head->lst_a);
			n--;
		}
		else if (find_spec_next(head, ft_lstlen(head->lst_b), n) == 0)
		{
			while (head->lst_b->puts != n)
			{
				RRB;
				reverse_rotab(&head->lst_b);
			}
		}
		else
		{
			while (head->lst_b->puts != n)
			{
				RB;
				rotate_ab(&head->lst_b);
			}
		}
	}
	return (1);
}
