# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nokhwezi <nokhwezi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 10:53:04 by nmabe             #+#    #+#              #
#    Updated: 2020/05/10 15:15:44 by nokhwezi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c\
	  ft_bzero.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_memalloc.c\
	  ft_del_arr.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memcpy.c\
	  ft_memdel.c\
	  ft_memmove.c\
	  ft_memset.c\
	  ft_putchar.c\
	  ft_putchar_fd.c\
	  ft_putendl.c\
	  ft_putendl_fd.c\
	  ft_putnbr.c\
	  ft_putnbr_fd.c\
	  ft_putstr.c\
	  ft_putstr_fd.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strclr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdel.c\
	  ft_strdup.c\
	  ft_strequ.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strjoin.c\
	  ft_strlcat.c\
	  ft_strlen.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strnequ.c\
	  ft_strnew.c\
	  ft_strnstr.c\
	  ft_strrchr.c\
	  ft_strarr.c\
	  ft_strstr.c\
	  ft_strsub.c\
	  ft_strtrim.c\
	  ft_strtrimc.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_itoa.c\
	  ft_strsplit.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_getchar.c\
	  ft_isspace.c\
	  ft_strswap.c\
	  ft_swap.c\
	  get_next_line.c\
	  sort_int_tab.c\
	  ft_chrcount.c \
	  ft_intlen.c
		
		
OFILES = $(SRC:.c=.o) 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	gcc -c $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)
	@echo "\033[22;32m Makefile: '$(NAME)' Has Been Successfully Compiled Comrade...\n \033[22;0m"

clean :
	/bin/rm -rf *.o

fclean : clean 
	/bin/rm -rf $(NAME)
	@echo "\033[22;31m Makefile: '$(NAME)' Successfully Removed. Libft.a Terminated \n \033[22;0m"

re: fclean all
