NAME = push_swap
CHECK = checker

INCL = includes/push_swap.h

PUSH_SRCS = error.c			initializer.c	push.c\
       reverse_rotate.c		rotate.c       	sort_three.c\
       stack_math.c			stack_utils.c  	swap.c\
	   sort_five.c			sort_big.c		sort_utils.c\
	   main.c

CHECK_SRCS = error.c		initializer.c	push.c\
       reverse_rotate.c		rotate.c		sort_three.c\
       stack_math.c			stack_utils.c	swap.c\
       sort_five.c			sort_big.c		sort_utils.c\
	   checker.c

LIB_DIR = srcs/libft/
SRCS_DIR = srcs/

PUSH_OBJS_NAME = $(PUSH_SRCS:.c=.o)
PUSH_OBJS = $(addprefix $(SRCS_DIR),$(PUSH_OBJS_NAME))

CHECK_OBJS_NAME = $(CHECK_SRCS:.c=.o)
CHECK_OBJS = $(addprefix $(SRCS_DIR),$(CHECK_OBJS_NAME))

OBJS = $(putsubst $%.c, %.o, $(SRCS))

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCL)

all: makelibft $(NAME)

$(NAME): $(PUSH_OBJS) $(INCL) $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(PUSH_OBJS) -L $(LIB_DIR) -lft

$(CHECK): $(CHECK_OBJS) $(INCL) $(LIB_DIR)
	@make makelibft
	@$(CC) $(CFLAGS) -o $(CHECK) $(CHECK_OBJS) -L $(LIB_DIR) -lft

%.o: %.c $(INCL) $(LIB_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

makelibft:
	@make -C $(LIB_DIR)

clean:
	@rm -f $(CHECK_OBJS) $(PUSH_OBJS)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME) $(CHECK)
	@make -C $(LIB_DIR) fclean

re: fclean all

bonus: $(CHECK)

.PHONY: all clean fclean re bonus
