/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 08:43:40 by nkholane          #+#    #+#             */
/*   Updated: 2020/05/14 01:36:25 by nokhwezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
#include <limits.h>

typedef struct		s_stack
{
	int				data;
	int				puts;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_lists
{
	t_stack			*lst_a;
	t_stack			*lst_b;
	char			**arr;
	int				fd;
	int				lst_len;
}					t_lists;

# define SA ft_putendl_fd("sa", 1);
# define SB ft_putendl_fd("sb", 1);
# define SS ft_putendl_fd("ss", 1);
# define PA ft_putendl_fd("pa", 1);
# define PB ft_putendl_fd("pb", 1);
# define RA ft_putendl_fd("ra", 1);
# define RB ft_putendl_fd("rb", 1);
# define RR ft_putendl_fd("rr", 1);
# define RRA ft_putendl_fd("rra", 1);
# define RRB ft_putendl_fd("rrb", 1);
# define RRR ft_putendl_fd("rrr", 1);
# define KO ft_putendl_fd("KO", 2);
# define ERROR ft_putendl_fd("Error", 2);
# define OK ft_putendl_fd("OK", 2);

int					sort_args(t_lists *head, char *str);
int					read_args(char *argv, t_lists *head, int end);
int					args(int argc, char **argv, t_lists *head);
int					put_back(t_lists *head, size_t n);
int					find_spec_next(t_lists *head, int len, int num);

void				put_set(int *arr, size_t n, t_lists *head);
int					read_instruction(t_lists *stk);
int					swap_ab(t_stack *first);
void				push_ab(t_stack **first, t_stack **second);
void				rotate_ab(t_stack **lst);
void				reverse_rotab(t_stack **lst);

int					ft_lstlen(t_stack *lst);
int					is_nums(char *str);
t_stack				*ft_newlst(void);
void				free_stack(t_stack *stack);
t_stack				*sort_list(t_stack *lst, int (*cmp)(int, int));
int					ascending(int a, int b);

int					get_many(t_lists *head, int lst_len);
int					find_high(t_lists *head);
int					pushback_a(t_lists *head);
void				three_sort(t_lists *head);
void				three_reverse(t_lists *head);
void				sort(t_lists *head, int lst_len);
int					find_next(t_lists *head, int len, int range);

char				**ft_split(char *str);
void				free_mem(t_lists *head);
void				free_array(char **arr, int n);

#endif
