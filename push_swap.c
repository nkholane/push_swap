/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:19:13 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 20:15:58 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	free_mem(t_lists *chk)
{
	if (chk->arr)
		free_array(chk->arr, ft_lstlen(chk->lst_a));
	free_stack(chk->lst_a);
	free(chk);
	exit(0);
}

int		main(int argc, char **argv)
{
	int		lst_a;
	t_lists	*chk;

	if (argc <= 1)
		return (0);
	chk = (t_lists *)ft_memalloc(sizeof(t_lists));
	lst_a = args(argc, argv, chk);
	if (!lst_a)
	{
		ERROR;
		if (chk->arr)
			free_array(chk->arr, ft_lstlen(chk->lst_a));
		free(chk);
		exit(0);
	}
	chk->lst_len = ft_lstlen(chk->lst_a);
	if (chk->lst_len >= 2 && chk->lst_len <= 3)
	{
		three_sort(chk);
		free_mem(chk);
	}
	if (sort_list(chk->lst_a, ascending))
		exit(0);
	sort(chk, chk->lst_len);
	free_mem(chk);
}
