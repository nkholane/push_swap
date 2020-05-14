# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 12:19:34 by nkholane          #+#    #+#              #
#    Updated: 2020/05/14 02:56:22 by nokhwezi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=	checker
NAME2=	push_swap

FLAGS= -Wall -Werror -Wextra -g

INCLUDES= -I ./libft/includes

all:	lib $(NAME1) $(NAME2)

lib: 
	make re -C ./libft/


SRC1=	lists.c get_args.c get_orders.c orders.c \
lst_order.c ft_split.c frees.c sort_args.c checker.c\

SRC2=  lists.c get_args.c get_orders.c orders.c \
lst_order.c ft_split.c frees.c sort_args.c \
push_sort.c sort.c push_swap.c \

OBJ1=	$(SRC1:.c=.o)

OBJ2=	$(SRC2:.c=.o)

$(NAME1):
	gcc $(FLAGS) -c $(SRC1) $(INCLUDES)
	gcc -o $(NAME1) $(OBJ1) $(INCLUDES) -L. ./libft/libft.a
	@echo "Makefile: '$(NAME1)' Has Been Successfully Compiled Comrade...\n"

$(NAME2):
	gcc $(FLAGS) -c $(SRC2) $(INCLUDES)
	gcc -o $(NAME2) $(OBJ2) $(INCLUDES) -L. ./libft/libft.a
	@echo "Makefile: '$(NAME2)' Has Been Successfully Compiled Comrade...\n"

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	@echo "Makefile: '$(NAME1)' & $(NAME2) Successfully Removed - Bye Comrade...\n"
	rm -f ./libft/*.o
	@echo "Libft Object Files Successfully Removed - Bye Comrade...\n"

re:	fclean all
