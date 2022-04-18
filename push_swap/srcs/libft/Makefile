NAME = libft.a

HEADER = libft.h

SRCS = ft_atoi.c		ft_isdigit.c		ft_lstadd_front.c\
		ft_lstclear.c	ft_lstdelone.c		ft_lstlast.c\
		ft_lstnew.c		ft_lstsize.c		ft_putchar_fd.c\
		ft_putstr_fd.c	ft_split.c			ft_strlen.c\
		ft_strncmp.c	get_next_line.c		get_next_line_utils.c

OBJS = $(patsubst %.c, %.o,$(SRCS))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re