/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:17:48 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 12:59:17 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

int		get_args(char *argv, t_lists *chk, int end)
{
	t_stack *tmp;

	tmp = chk->lst_a;
	if (!is_all_digit(argv))
		return (0);
	else if (ft_strstr(argv, " "))
	{
		if (!sort_args(chk, argv))
			return (0);
	}
	else
	{
		if (ft_atoi(argv) < -217478368 || ft_atoi(argv) > 217478367)
			return (0);
		if (end)
			chk->lst_a->next = ft_intlstnew();
		chk->lst_a->data = (ft_atoi(argv));
		chk->lst_a->norm = -2;
	}
	chk->lst_a = tmp;
	return (1);
}

int		each_arg(int argc, char **argv, t_lists *chk)
{
	int arg;

	arg = 1;
	while (arg < argc)
	{
		if (ft_strcmp(argv[arg], "-v") == 0)
		{
			chk->vis = 1;
			arg++;
		}
		if (ft_strcmp(argv[arg], "-s") == 0)
		{
			chk->vis = 2;
			arg++;
		}
		if (!get_args(argv[arg], chk, (arg < argc - 1)))
		{
			return (0);
		}
		chk->lst_a = chk->lst_a->next;
		arg++;
	}
	return (1);
}

int		args(int argc, char **argv, t_lists *chk)
{
//	int		arg;
	int		c;
	t_stack	*tmp;

	c = 0;
	if (argc <= 1)
		return (0);
//	arg = 1;
	chk->lst_a = ft_intlstnew();
	tmp = chk->lst_a;
	c = each_arg(argc, argv, chk);
	chk->lst_a = tmp;
	if (c == 0)
	{
		free_stack(tmp);
		return (0);
	}
	c = normalise(chk, argc);
	if (c == 0)
	{
		free_stack(tmp);
		return (0);
	}
	return (1);
}
