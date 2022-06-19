SRCS			=	pipex.c ft_putstr_fd.c ft_split.c ft_strnstr.c ft_strjoin.c path_s.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= pipex

$(NAME):		$(OBJS) pipex.h Makefile
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re