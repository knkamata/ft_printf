########################################################

NAME		= libftprintf.a

########################################################

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
AR			= ar rcs
RM			= rm -f

########################################################

SRCS		= ft_printf.c \
			  ./srcs/ft_itoas.c ./srcs/ft_strs.c \
			  ./srcs/stdout_str.c ./srcs/stdout_int.c \
			  ./srcs/stdout_ptr.c ./srcs/stdout_hex.c
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
