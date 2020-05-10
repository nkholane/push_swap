/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 09:02:40 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 22:24:53 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	three_sort(t_lists *chk)
{
	while (!sort_list(chk->lst_a, ascending))
	{
		if (chk->lst_a->norm == 2)
		{
			RA;
			rotate_ab(&chk->lst_a);
		}
		else if (chk->lst_a->norm < chk->lst_a->next->norm)
		{
			RRA;
			reverse_rotab(&chk->lst_a);
		}
		else if (chk->lst_a->norm > chk->lst_a->next->norm)
		{
			SA;
			swap_ab(chk->lst_a);
		}
	}
}

void	three_reverse(t_lists *chk)
{
	while (!sort_list(chk->lst_a, ascending))
	{
		RRA;
		reverse_rotab(&chk->lst_a);
	}
}

void	sort_five(t_lists *chk)
{
	while (ft_lstlen(chk->lst_a) > 3)
	{
		if (find_next(chk, ft_lstlen(chk->lst_a), 1) == 0)
		{
			while (chk->lst_a->norm > 1)
			{
				RA;
				rotate_ab(&chk->lst_a);
			}
			PB;
			push_ab(&chk->lst_a, &chk->lst_b);
		}
		else
		{
			while (chk->lst_a->norm > 1)
			{
				RRA;
				reverse_rotab(&chk->lst_a);
			}
			PB;
			push_ab(&chk->lst_a, &chk->lst_b);
		}
	}
	three_sort(chk);
	pushback_a(chk);
}

void	sort(t_lists *chk, int lst_len)
{
	if (ft_lstlen(chk->lst_a) == 5)
	{
		sort_five(chk);
		exit(0);
	}
	while (ft_lstlen(chk->lst_a) >= 5)
	{
		get_many(chk, lst_len - 1);
		lst_len = ft_lstlen(chk->lst_a);
	}
	while (chk->lst_a->norm != 3)
	{
		RA;
		rotate_ab(&chk->lst_a);
	}
	PB;
	push_ab(&chk->lst_a, &chk->lst_b);
	three_sort(chk);
	pushback_a(chk);
	three_reverse(chk);
}
