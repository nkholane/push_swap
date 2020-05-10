/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:33:39 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/10 21:21:49 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	free_array(char **ar, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(ar[i]);
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack->next)
		free_stack(stack->next);
	free(stack);
}
