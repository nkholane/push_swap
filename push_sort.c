/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:40:55 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 10:46:22 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		find_next(t_lists *chk, int len, int range)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = chk->lst_a;
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

int		find_spec_next(t_lists *chk, int len, int num)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = chk->lst_b;
	while (tmp != NULL)
	{
		if (tmp->puts == num)
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

int		get_many(t_lists *chk, int lst_len)
{
	int slen;

	slen = ft_lstlen(chk->lst_b);
	while (ft_lstlen(chk->lst_b) - slen <= (lst_len / 5))
	{
		if (chk->lst_a->puts >= (lst_len - (lst_len / 5)))
		{
			PB;
			push_ab(&chk->lst_a, &chk->lst_b);
		}
		else
		{
			if (find_next(chk, lst_len, (lst_len / 5)) == 1)
			{
				while (!(chk->lst_a->puts >= (lst_len - (lst_len / 5))))
				{
					RA
					rotate_ab(&chk->lst_a);
				}
			}
			else
			{
				while (!(chk->lst_a->puts >= (lst_len - (lst_len / 5))))
				{
					RRA;
					reverse_rotab(&chk->lst_a);
				}
			}
		}
	}
	return (1);
}

int		find_high(t_lists *chk)
{
	t_stack *tmp;
	int		ret;

	ret = 0;
	tmp = chk->lst_b;
	while (chk->lst_b)
	{
		if (chk->lst_b->puts > ret)
		{
			ret = chk->lst_b->puts;
		}
		chk->lst_b = chk->lst_b->next;
	}
	chk->lst_b = tmp;
	return (ret);
}

int		pushback_a(t_lists *chk)
{
	int n;

	n = find_high(chk);
	while (ft_lstlen(chk->lst_b) > 0)
	{
		if (chk->lst_b->puts == n)
		{
			PA;
			push_ab(&chk->lst_b, &chk->lst_a);
			n--;
		}
		else if (find_spec_next(chk, ft_lstlen(chk->lst_b), n) == 0)
		{
			while (chk->lst_b->puts != n)
			{
				RRB;
				reverse_rotab(&chk->lst_b);
			}
		}
		else
		{
			while (chk->lst_b->puts != n)
			{
				RB;
				rotate_ab(&chk->lst_b);
			}
		}
	}
	return (1);
}
