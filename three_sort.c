/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 09:45:00 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/13 10:44:10 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	three_sort(t_lists *head)
{
	while (!sort_list(head->lst_a, ascending))
	{
		if (head->lst_a->puts == 2)
		{
			RA;
			rotate_ab(&head->lst_a);
		}
		else if (head->lst_a->puts < head->lst_a->next->puts)
		{
			RRA;
			reverse_rotab(&head->lst_a);
		}
		else if (head->lst_a->puts > head->lst_a->next->puts)
		{
			SA;
			swap_ab(head->lst_a);
		}
	}
}

void	three_reverse(t_lists *head)
{
	while (!sort_list(head->lst_a, ascending))
	{
		RRA;
		reverse_rotab(&head->lst_a);
	}
}