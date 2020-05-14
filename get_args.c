/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:17:48 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 01:43:57 by nokhwezi         ###   ########.fr       */
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
	int i;

	i = 1;
	while (i < argc)
	{
		if (!get_args(argv[i], head, (i < argc - 1)))
		{
			return (0);
		}
		head->lst_a = head->lst_a->next;
		i++;
	}
	return (1);
}

int		args(int argc, char **argv, t_lists *head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (argc <= 1)
		return (0);
		
	head->lst_a = ft_newlst();
	tmp = head->lst_a;
	i = each_arg(argc, argv, head);
	head->lst_a = tmp;
	if (i == 0)
	{
		free_stack(tmp);
		return (0);
	}
	i = put_back(head, argc);
	if (i == 0)
	{
		free_stack(tmp);
		return (0);
	}
	return (1);
}
