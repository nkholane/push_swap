/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_orders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:18:10 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/13 10:44:10 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		enter_rot(char *buf, t_lists *head)
{
	if (strcmp(buf, "ra") == 0)
		rotate_ab(&head->lst_a);
	else if (strcmp(buf, "rb") == 0)
		rotate_ab(&head->lst_b);
	else if (strcmp(buf, "rr") == 0)
	{
		rotate_ab(&head->lst_a);
		rotate_ab(&head->lst_b);
	}
	else if (strcmp(buf, "rra") == 0)
		reverse_rotab(&head->lst_a);
	else if (strcmp(buf, "rrb") == 0)
		reverse_rotab(&head->lst_b);
	else if (strcmp(buf, "rrr") == 0)
	{
		reverse_rotab(&head->lst_a);
		reverse_rotab(&head->lst_b);
	}
	else
		return (0);
	return (1);
}

int		enter_swap(char *buf, t_lists *head)
{
	if (strcmp(buf, "sa") == 0)
		swap_ab(head->lst_a);
	else if (strcmp(buf, "sb") == 0)
		swap_ab(head->lst_b);
	else if (strcmp(buf, "ss") == 0)
	{
		swap_ab(head->lst_a);
		swap_ab(head->lst_b);
	}
	else
		return (0);
	return (1);
}

int		enter_push(char *buf, t_lists *head)
{
	if (strcmp(buf, "pb") == 0)
	{
		push_ab(&head->lst_a, &head->lst_b);
	}
	else if (strcmp(buf, "pa") == 0)
	{
		push_ab(&head->lst_b, &head->lst_a);
	}
	else
		return (0);
	return (1);
}

int		read_instruction(t_lists *head)
{
	int		ret;
	int		enter;
	char	*buf;

	enter = 0;
	while ((ret = get_next_line(head->fd, &buf) > 0))
	{
		if (strchr(buf, 's'))
			enter = enter_swap(buf, head);
		else if (strchr(buf, 'r'))
			enter = enter_rot(buf, head);
		else if (strchr(buf, 'p'))
			enter = enter_push(buf, head);
		else
			return (0);
		if (enter == 0)
		{
			free(buf);
			return (0);
		}
	}
	free(buf);
	return (1);
}

int		is_nums(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
