/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 09:02:40 by kmarchan          #+#    #+#             */
/*   Updated: 2020/05/03 13:03:55 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <strings.h>

void	sort_thre(t_lists *chk)
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
			revrot_ab(&chk->lst_a);
		}
		else if (chk->lst_a->norm > chk->lst_a->next->norm)
		{
			SA;
			swap_ab(chk->lst_a);
		}
	}
}

void	rra3(t_lists *chk)
{
	while (!sort_list(chk->lst_a, ascending))
	{
		RRA;
		revrot_ab(&chk->lst_a);
	}
}

int		find_5(t_lists *chk, int len, int smal)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = chk->lst_a;
	while (tmp)
	{
		if (tmp->norm <= smal)
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

void	sort_5(t_lists *chk)
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
				revrot_ab(&chk->lst_a);
			}
			PB;
			push_ab(&chk->lst_a, &chk->lst_b);
		}
	}
	sort_thre(chk);
	back2a(chk);
}

void	sort(t_lists *chk, int llen)
{
	if (ft_lstlen(chk->lst_a) == 5)
	{
		sort_5(chk);
		exit(0);
	}
	while (ft_lstlen(chk->lst_a) >= 5)
	{
		get_chunk(chk, llen - 1);
		llen = ft_lstlen(chk->lst_a);
	}
	while (chk->lst_a->norm != 3)
	{
		RA;
		rotate_ab(&chk->lst_a);
	}
	PB;
	push_ab(&chk->lst_a, &chk->lst_b);
	sort_thre(chk);
	back2a(chk);
	rra3(chk);
}
