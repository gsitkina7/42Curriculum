NAME = pipex

INCL = includes/pipex.h

SRCS = ft_putstr_fd.c	ft_split.c		ft_strjoin.c\
		ft_strlen.c		ft_strnstr.c	utils.c\
		pipex.c

SRCS_DIR = srcs/

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(SRCS_DIR),$(OBJS_NAME))

CC = gcc

GFLAGS = -Wall -Werror -Wextra -I $(INCL)

all: $(NAME)

$(NAME): $(INCL) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(INCL)
	$(CC) -c $(CFLAGS) -o $@ $<

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re