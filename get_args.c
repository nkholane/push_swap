/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:17:48 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/13 10:44:10 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		get_args(char *argv, t_lists *head, int end)
{
	t_stack *tmp;

	tmp = head->lst_a;
	if (!is_nums(argv))
		return (0);
	else if (ft_strstr(argv, " "))
	{
		if (!sort_args(head, argv))
			return (0);
	}
	else
	{
		if (ft_atoi(argv) < -217478368 || ft_atoi(argv) > 217478367)
			return (0);
		if (end)
			head->lst_a->next = ft_newlst();
		head->lst_a->data = (ft_atoi(argv));
		head->lst_a->puts = -2;
	}
	head->lst_a = tmp;
	return (1);
}

int		each_arg(int argc, char **argv, t_lists *head)
{
	int arg;

	arg = 1;
	while (arg < argc)
	{
		if (!get_args(argv[arg], head, (arg < argc - 1)))
		{
			return (0);
		}
		head->lst_a = head->lst_a->next;
		arg++;
	}
	return (1);
}

int		args(int argc, char **argv, t_lists *head)
{
	int		c;
	t_stack	*tmp;

	c = 0;
	if (argc <= 1)
		return (0);
		
	head->lst_a = ft_newlst();
	tmp = head->lst_a;
	c = each_arg(argc, argv, head);
	head->lst_a = tmp;
	if (c == 0)
	{
		free_stack(tmp);
		return (0);
	}
	c = put_head(head, argc);
	if (c == 0)
	{
		free_stack(tmp);
		return (0);
	}
	return (1);
}
