/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:33:30 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/10 16:07:33 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	set_norm(int *arr, size_t n, t_lists *chk)
{
	t_stack	*tmp;
	size_t	i;

	tmp = chk->lst_a;
	while (chk->lst_a != NULL)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == chk->lst_a->data)
			{
				chk->lst_a->norm = i;
			}
			i++;
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
	int		i;

	i = 0;
	chk->arr = ft_split(str);
	while (chk->arr[i] != NULL)
	{
		if (ft_atoi(chk->arr[i]) < -217478368 || ft_atoi(chk->arr[i]) > 217478367)
		{
			return (0);
		}
		if (chk->arr[i + 1] != NULL)
			chk->lst_a->next = ft_newlst();
		chk->lst_a->data = (ft_atoi(chk->arr[i]));
		chk->lst_a = chk->lst_a->next;
		i++;
	}
	return (1);
}
