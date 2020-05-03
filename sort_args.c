/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 08:33:30 by kmarchan          #+#    #+#             */
/*   Updated: 2020/05/03 13:00:50 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include <limits.h>

void	set_norm(int *arr, size_t n, t_lists *chk)
{
	t_stack	*tmp;
	size_t	e;

	tmp = chk->lst_a;
	while (chk->lst_a != NULL)
	{
		e = 0;
		while (e < n)
		{
			if (arr[e] == chk->lst_a->data)
			{
				chk->lst_a->norm = e;
			}
			e++;
		}
		chk->lst_a = chk->lst_a->next;
	}
	chk->lst_a = tmp;
}

int		normalise(t_lists *chk, size_t n)
{
	t_stack		*tmp;
	int			*arr;

	tmp = chk->lst_a;
	arr = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (chk->lst_a != NULL)
	{
		arr[n] = chk->lst_a->data;
		n++;
		chk->lst_a = chk->lst_a->next;
	}
	if (!sort_int_tab(arr, n))
	{
		free(arr);
		return (0);
	}
	chk->lst_a = tmp;
	set_norm(arr, n, chk);
	free(arr);
	return (1);
}

int		sort_args(t_lists *chk, char *str)
{
	int		e;

	e = 0;
	chk->arr = ft_split(str);
	while (chk->arr[e] != NULL)
	{
		if (ft_atoi(chk->arr[e]) < -217478368 || ft_atoi(chk->arr[e]) > 217478367)
		{
			return (0);
		}
		if (chk->arr[e + 1] != NULL)
			chk->lst_a->next = ft_intlstnew();
		chk->lst_a->data = (ft_atoi(chk->arr[e]));
		chk->lst_a = chk->lst_a->next;
		e++;
	}
	return (1);
}
