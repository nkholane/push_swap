/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:19:13 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 13:03:49 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void	free_mem(t_lists *chk)
{
	if (chk->arr)
		free_ar(chk->arr, ft_lstlen(chk->lst_a));
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
			free_ar(chk->arr, ft_lstlen(chk->lst_a));
		free(chk);
		exit(0);
	}
	chk->llen = ft_lstlen(chk->lst_a);
	if (chk->llen >= 2 && chk->llen <= 3)
	{
		sort_thre(chk);
		free_mem(chk);
	}
	if (sort_list(chk->lst_a, ascending))
		exit(0);
	sort(chk, chk->llen);
	free_mem(chk);
}
