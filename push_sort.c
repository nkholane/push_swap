/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:40:55 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 01:36:25 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

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

int		find_spec_next(t_lists *head, int len, int num)
{
	t_stack *tmp;
	int		count;

	count = 0;
	tmp = head->lst_b;
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

int		get_many(t_lists *head, int lst_len)
{
	int slen;

	slen = ft_lstlen(head->lst_b);
	while (ft_lstlen(head->lst_b) - slen <= (lst_len / 5))
	{
		if (head->lst_a->puts >= (lst_len - (lst_len / 5)))
		{
			PB;
			push_ab(&head->lst_a, &head->lst_b);
		}
		else
		{
			if (find_next(head, lst_len, (lst_len / 5)) == 1)
			{
				while (!(head->lst_a->puts >= (lst_len - (lst_len / 5))))
				{
					RA
					rotate_ab(&head->lst_a);
				}
			}
			else
			{
				while (!(head->lst_a->puts >= (lst_len - (lst_len / 5))))
				{
					RRA;
					reverse_rotab(&head->lst_a);
				}
			}
		}
	}
	return (1);
}

int		find_high(t_lists *head)
{
	t_stack *tmp;
	int		ret;

	ret = 0;
	tmp = head->lst_b;
	while (head->lst_b)
	{
		if (head->lst_b->puts > ret)
		{
			ret = head->lst_b->puts;
		}
		head->lst_b = head->lst_b->next;
	}
	head->lst_b = tmp;
	return (ret);
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
