# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 08:31:35 by kkamata           #+#    #+#              #
#    Updated: 2021/09/02 08:41:20 by kkamata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################################################

NAME		= libftprintf.a

########################################################

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
AR			= ar rcs
RM			= rm -f

########################################################

SRCS		= ft_printf.c \
			  ./srcs/ft_itoa.c \
			  ./srcs/ft_strs.c \
			  ./srcs/write_format.c \
			  ./srcs/write_specifiers.c \
			  ./srcs/write_str.c \
			  ./srcs/write_pct.c \
			  ./srcs/write_int.c \
			  ./srcs/write_int_pos.c \
			  ./srcs/write_int_neg.c \
			  ./srcs/write_uint.c \
			  ./srcs/write_ptr.c \
			  ./srcs/write_hex.c \
			  ./srcs/write_width.c
OBJS		= $(SRCS:%.c=%.o)

########################################################

.PHONY: all clean fclean re bonus

########################################################

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

########################################################
