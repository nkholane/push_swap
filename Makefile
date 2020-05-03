# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 12:19:34 by nokhwezi          #+#    #+#              #
#    Updated: 2020/05/03 12:19:39 by nokhwezi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=	checker

NAME2=	push_swap

INCLUDES= -I ./libft_gnl/includes

all:	lib $(NAME1) $(NAME2)

lib: 
	make re -C ./libft_gnl/


SRC1=	checker.c ft_list.c get_args.c get_instruction.c instructions.c \
lst_order.c print_stack.c ft_split.c ft_strsplitter.c memory_man.c sort_args.c \

SRC2=	push_swap.c ft_list.c get_args.c get_instruction.c instructions.c \
lst_order.c print_stack.c ft_split.c ft_strsplitter.c memory_man.c sort_args.c \
push_sort.c sort.c

OBJ1=	$(SRC1:.c=.o)

OBJ2=	$(SRC2:.c=.o)

$(NAME1):
	gcc -Wall -Werror -Wextra -c $(SRC1) $(INCLUDES)
	gcc -o $(NAME1) $(OBJ1) $(INCLUDES) -L. ./libft_gnl/libft.a

$(NAME2):
	gcc -Wall -Werror -Wextra -c $(SRC2) $(INCLUDES)
	gcc -o $(NAME2) $(OBJ2) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all
