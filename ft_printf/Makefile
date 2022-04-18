NAME = libftprintf.a

INCL = includes/

SRCS_DIR = ./srcs
SRCS = srcs/ft_printf.c\
		srcs/ft_process_hex.c\
		srcs/ft_process_int.c\
		srcs/ft_process_pointer.c\
		srcs/ft_process_text.c\
		srcs/ft_process_unsigned.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I $(INCL)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $?

%.o: %.c $(INCL)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
