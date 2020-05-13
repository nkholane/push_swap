# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 12:19:34 by nkholane          #+#    #+#              #
#    Updated: 2020/05/10 22:26:02 by nokhwezi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=	checker

NAME2=	push_swap

INCLUDES= -I ./libft/includes

all:	lib $(NAME1) $(NAME2)

lib: 
	make re -C ./libft/


SRC1=	checker.c lists.c get_args.c get_orders.c orders.c \
lst_order.c ft_split.c frees.c sort_args.c \

SRC2=	push_swap.c lists.c get_args.c get_orders.c orders.c \
lst_order.c ft_split.c frees.c sort_args.c \
push_sort.c sort.c

OBJ1=	$(SRC1:.c=.o)

OBJ2=	$(SRC2:.c=.o)

$(NAME1):
	gcc -Wall -Werror -Wextra -c $(SRC1) $(INCLUDES)
	gcc -o $(NAME1) $(OBJ1) $(INCLUDES) -L. ./libft/libft.a
	@echo "\033[22;32m Makefile: '$(NAME1)' Has Been Successfully Compiled Comrade...\n \033[22;0m"

$(NAME2):
	gcc -Wall -Werror -Wextra -c $(SRC2) $(INCLUDES)
	gcc -o $(NAME2) $(OBJ2) $(INCLUDES) -L. ./libft/libft.a
	@echo "\033[22;32m Makefile: '$(NAME2)' Has Been Successfully Compiled Comrade...\n \033[22;0m"

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	@echo "\033[22;31m Makefile: '$(NAME1)' & $(NAME2) Successfully Removed - Bye Comrade...\n \033[22;0m"
	rm -f ./libft/*.o
	@echo "\033[22;31m Libft Object Files Successfully Removed - Bye Comrade...\n \033[22;0m"

re:	fclean all
