/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:33:30 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/14 01:36:25 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	put_set(int *arr, size_t n, t_lists *head)
{
	t_stack	*tmp;
	size_t	i;

	tmp = head->lst_a;
	while (head->lst_a != NULL)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == head->lst_a->data)
			{
				head->lst_a->puts = i;
			}
			i++;
		}
		head->lst_a = head->lst_a->next;
	}
	head->lst_a = tmp;
}

int		put_back(t_lists *head, size_t n)
{
	t_stack		*tmp;
	int			*arr;

	tmp = head->lst_a;
	arr = (int*)malloc(sizeof(int) * n + 1);
	n = 0;
	while (head->lst_a != NULL)
	{
		arr[n] = head->lst_a->data;
		n++;
		head->lst_a = head->lst_a->next;
	}
	if (!sort_int_tab(arr, n))
	{
		free(arr);
		return (0);
	}
	head->lst_a = tmp;
	put_set(arr, n, head);
	free(arr);
	return (1);
}

int		sort_args(t_lists *head, char *str)
{
	int		i;

	i = 0;
	head->arr = ft_split(str);
	while (head->arr[i] != NULL)
	{
		if (ft_atoi(head->arr[i]) < -217478368 || ft_atoi(head->arr[i]) > 217478367)
		{
			return (0);
		}
		if (head->arr[i + 1] != NULL)
			head->lst_a->next = ft_newlst();
		head->lst_a->data = (ft_atoi(head->arr[i]));
		head->lst_a = head->lst_a->next;
		i++;
	}
	return (1);
}
