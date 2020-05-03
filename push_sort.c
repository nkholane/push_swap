/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:40:55 by kmarchan          #+#    #+#             */
/*   Updated: 2020/05/03 13:03:25 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <strings.h>

int		find_next(t_lists *chk, int len, int range)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = chk->lst_a;
	while (tmp)
	{
		if (tmp->norm >= (len - range))
		{
			if (count >= len / 2)
				return (0);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int		find_spec_next(t_lists *chk, int len, int num)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = chk->lst_b;
	while (tmp != NULL)
	{
		if (tmp->norm == num)
		{
			if (count > (len / 2))
				return (0);
			else
				return (1);
		}
		count++;
		tmp = tmp->next;
	}
	return (1);
}

int		get_chunk(t_lists *chk, int llen)
{
	int slen;

	slen = ft_lstlen(chk->lst_b);
	while (ft_lstlen(chk->lst_b) - slen <= (llen / 5))
	{
		if (chk->lst_a->norm >= (llen - (llen / 5)))
		{
			PB;
			push_ab(&chk->lst_a, &chk->lst_b);
		}
		else
		{
			if (find_next(chk, llen, (llen / 5)) == 1)
			{
				while (!(chk->lst_a->norm >= (llen - (llen / 5))))
				{
					RA
					rotate_ab(&chk->lst_a);
				}
			}
			else
			{
				while (!(chk->lst_a->norm >= (llen - (llen / 5))))
				{
					RRA;
					revrot_ab(&chk->lst_a);
				}
			}
		}
	}
	return (1);
}

int		find_hi(t_lists *chk)
{
	t_stack *tmp;
	int		ret;

	ret = 0;
	tmp = chk->lst_b;
	while (chk->lst_b)
	{
		if (chk->lst_b->norm > ret)
		{
			ret = chk->lst_b->norm;
		}
		chk->lst_b = chk->lst_b->next;
	}
	chk->lst_b = tmp;
	return (ret);
}

int		back2a(t_lists *chk)
{
	int n;

	n = find_hi(chk);
	while (ft_lstlen(chk->lst_b) > 0)
	{
		if (chk->lst_b->norm == n)
		{
			PA;
			push_ab(&chk->lst_b, &chk->lst_a);
			n--;
		}
		else if (find_spec_next(chk, ft_lstlen(chk->lst_b), n) == 0)
		{
			while (chk->lst_b->norm != n)
			{
				RRB;
				revrot_ab(&chk->lst_b);
			}
		}
		else
		{
			while (chk->lst_b->norm != n)
			{
				RB;
				rotate_ab(&chk->lst_b);
			}
		}
	}
	return (1);
}