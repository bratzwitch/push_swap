NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib_ft

SRC =	push_swap.c

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling this crap"
		@make -C $(LIBFT) && make clean -C $(LIBFT)
		@cc $(CFLAGS) $(OBJS) -o $(NAME) ./lib_ft/libft.a
		@echo "All good you can rest(no)"
clean:
		$(RM) $(OBJS)

fclean:	clean
		make fclean -C $(LIBFT)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re