/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:18:10 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 13:04:54 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		ins_rot(char *buf, t_lists *chk)
{
	if (strcmp(buf, "ra") == 0)
		rotate_ab(&chk->lst_a);
	else if (strcmp(buf, "rb") == 0)
		rotate_ab(&chk->lst_b);
	else if (strcmp(buf, "rr") == 0)
	{
		rotate_ab(&chk->lst_a);
		rotate_ab(&chk->lst_b);
	}
	else if (strcmp(buf, "rra") == 0)
		revrot_ab(&chk->lst_a);
	else if (strcmp(buf, "rrb") == 0)
		revrot_ab(&chk->lst_b);
	else if (strcmp(buf, "rrr") == 0)
	{
		revrot_ab(&chk->lst_a);
		revrot_ab(&chk->lst_b);
	}
	else
		return (0);
	return (1);
}

int		ins_swap(char *buf, t_lists *chk)
{
	if (strcmp(buf, "sa") == 0)
		swap_ab(chk->lst_a);
	else if (strcmp(buf, "sb") == 0)
		swap_ab(chk->lst_b);
	else if (strcmp(buf, "ss") == 0)
	{
		swap_ab(chk->lst_a);
		swap_ab(chk->lst_b);
	}
	else
		return (0);
	return (1);
}

int		ins_push(char *buf, t_lists *chk)
{
	if (strcmp(buf, "pb") == 0)
	{
		push_ab(&chk->lst_a, &chk->lst_b);
	}
	else if (strcmp(buf, "pa") == 0)
	{
		push_ab(&chk->lst_b, &chk->lst_a);
	}
	else
		return (0);
	return (1);
}

int		read_instruction(t_lists *chk)
{
	int		ret;
	int		e;
	char	*buf;

	e = 0;
	while ((ret = get_next_line(chk->fd, &buf) > 0))
	{
		print(chk);
		if (strchr(buf, 's'))
			e = ins_swap(buf, chk);
		else if (strchr(buf, 'r'))
			e = ins_rot(buf, chk);
		else if (strchr(buf, 'p'))
			e = ins_push(buf, chk);
		else
			return (0);
		if (e == 0)
		{
			free(buf);
			return (0);
		}
	}
	print(chk);
	free(buf);
	return (1);
}

int		is_all_digit(char *str)
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
