SRCS			=	ft_printf.c ft_cs.c ft_pointer.c ft_id.c ft_u.c ft_x.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

$(NAME):		$(OBJS) ft_printf.h Makefile
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re