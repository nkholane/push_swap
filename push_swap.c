/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:19:13 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 02:47:15 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	int		lst_a;
	t_lists	*head;

	if (argc <= 1)
		return (0);
	head = (t_lists *)ft_memalloc(sizeof(t_lists));
	lst_a = args(argc, argv, head);
	if (!lst_a)
	{
		ERROR;
		if (head->arr)
			free_array(head->arr, ft_lstlen(head->lst_a));
		free(head);
		exit(0);
	}
	head->lst_len = ft_lstlen(head->lst_a);
	if (head->lst_len >= 2 && head->lst_len <= 3)
	{
		three_sort(head);
		free_mem(head);
	}
	if (sort_list(head->lst_a, ascending))
		exit(0);
	sort(head, head->lst_len);
	free_mem(head);
}
