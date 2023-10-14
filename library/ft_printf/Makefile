# **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2023/04/09 22:27:58 by maeharahika       #+#    #+#              #
#    Updated: 2023/04/10 23:09:22 by hmaehara         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_rdy_print.c ft_printchar.c ft_printstr.c \
	   ft_printptr.c ft_printint.c ft_printunsigned.c \
	   ft_printhex.c ft_printper.c

OBJS = ${SRCS:.c=.o}

AR = ar rcs
LIBNAME = ft_printf.h
CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	    $(AR) $(NAME) $(OBJS)

clean:
	    $(RM) $(OBJS)

fclean: clean
	    $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
