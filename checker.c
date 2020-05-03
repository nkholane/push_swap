/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:19:55 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 13:06:06 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		main(int argc, char **argv)
{
	int		lst_a;
	t_lists	*chk;

	if (argc <= 1)
		return (0);
	chk = (t_lists *)ft_memalloc(sizeof(t_lists));
	chk->llen = 0;
	lst_a = args(argc, argv, chk);
	if (!lst_a)
	{
		ERROR;
		exit(0);
	}
	if (!read_instruction(chk))
	{
		ERROR;
		exit(0);
	}
	if (!sort_list(chk->lst_a, ascending) || ft_lstlen(chk->lst_b) > 0)
	{
		KO;
		exit(0);
	}
	OK;
	exit(1);
}
