/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:20:20 by nokhwezi          #+#    #+#             */
/*   Updated: 2020/05/03 13:00:16 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

void	print_stack(t_stack *lst_a)
{
	t_stack *tmp;

	tmp = lst_a;
	while (lst_a != NULL)
	{
		ft_putnbr_fd(lst_a->data, 2);
		ft_putchar_fd(' ', 2);
		lst_a = lst_a->next;
	}
	ft_putchar_fd('\n', 2);
	lst_a = tmp;
	while (lst_a != NULL)
	{
		ft_putnbr_fd(lst_a->norm, 2);
		ft_putchar_fd(' ', 2);
		lst_a = lst_a->next;
	}
	ft_putchar_fd('\n', 2);
	return ;
}

void	print_ab(t_lists *chk)
{
	ft_putendl_fd(CYN "Stack A" RESET, 2);
	print_stack(chk->lst_a);
	ft_putendl_fd(CYN "Stack B" RESET, 2);
	print_stack(chk->lst_b);
}

void	print_norm(t_lists *chk, t_stack *s)
{
	int		i;
	t_stack	*tmp;

	tmp = s;
	while (tmp)
	{
		i = 0;
		ft_putstr("         ");
		while (i <= tmp->norm)
		{
			ft_putstr("█");
			i++;
		}
		while (i <= chk->llen)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void	print_vis(t_lists *chk)
{
	ft_putstr(CYN);
	print_norm(chk, chk->lst_a);
	ft_putstr(MAG);
	print_norm(chk, chk->lst_b);
	ft_putstr(RESET);
	usleep(10000);
}

void	print(t_lists *chk)
{
	int i;

	i = 100000;
	if (chk->vis == 1)
	{
		if (chk->llen == 0)
		{
			chk->llen = ft_lstlen(chk->lst_a);
			while (i--)
				ft_putstr(" ");
		}
		ft_putstr(CLR);
		ft_putstr(WHT "\n\n\n");
		ft_putstr("        ___  _  _ ____ _  _    ____ _ _ _ ____ ___        ");
		ft_putendl(CYN "             STACK A is CYAN              ");
		ft_putstr("        |__] |  | [__  |__| __ [__  | | | |__| |__]       ");
		ft_putendl(MAG "             STACK B is MAGENTA" RESET);
		ft_putendl("        |    |__| ___] |  |    ___] |_|_| |  | |         ");
		ft_putstr(RESET);
		print_vis(chk);
	}
	else if (chk->vis == 2)
		print_ab(chk);
}
