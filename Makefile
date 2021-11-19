# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 18:12:17 by daalmeid          #+#    #+#              #
#    Updated: 2021/11/19 16:23:56 by daalmeid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_putnbr_printf.c ft_putnbr_ptr.c ft_putnbr_un.c ft_putnbr_base.c\
		ft_putstr_printf.c ft_printf.c ft_isalpha.c ft_putchar_fd.c\
		ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strlen.c 

SRCS_BONUS	= 

OBJS	= *.o

RM = rm -f

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	
all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

bonus: clean
	gcc -Wall -Wextra -Werror -c $(SRCS) $(SRCS_BONUS)
	ar rc $(NAME) $(OBJS)