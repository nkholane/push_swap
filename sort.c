/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:02:40 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 02:24:10 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	three_sort(t_lists *head)
{
	while (!sort_list(head->lst_a, ascending))
	{
		if (head->lst_a->puts == 2)
		{
			RA;
			rotate_ab(&head->lst_a);
		}
		else if (head->lst_a->puts < head->lst_a->next->puts)
		{
			RRA;
			reverse_rotab(&head->lst_a);
		}
		else if (head->lst_a->puts > head->lst_a->next->puts)
		{
			SA;
			swap_ab(head->lst_a);
		}
		else
		{
			RRA;
			reverse_rotab(&head->lst_a);
		}
		
	}
}

// void	three_reverse(t_lists *head)
// {
// 	while (!sort_list(head->lst_a, ascending))
// 	{
// 		RRA;
// 		reverse_rotab(&head->lst_a);
// 	}
// }

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

void	sort(t_lists *head, int lst_len)
{
	if (ft_lstlen(head->lst_a) == 5)
	{
		sort_five(head);
		exit(0);
	}
	while (ft_lstlen(head->lst_a) >= 5)
	{
		get_many(head, lst_len - 1);
		lst_len = ft_lstlen(head->lst_a);
	}
	while (head->lst_a->puts != 3)
	{
		RA;
		rotate_ab(&head->lst_a);
	}
	PB;
	push_ab(&head->lst_a, &head->lst_b);
	three_sort(head);
	pushback_a(head);
	//three_reverse(head);
}
