/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:19:55 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 03:05:47 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		main(int argc, char **argv)
{
	int		lst_a;
	t_lists	*head;

	if (argc <= 1)
		return (0);
	head = (t_lists *)ft_memalloc(sizeof(t_lists));
	head->lst_len = 0;
	lst_a = args(argc, argv, head);
	if (!lst_a)
	{
		ERROR;
		exit(0);
	}
	if (!read_instruction(head))
	{
		ERROR;
		exit(0);
	}
	if (!sort_list(head->lst_a, ascending) || ft_lstlen(head->lst_b) > 0)
	{
		KO;
		exit(0);
	}
	OK;
	exit(1);
}
