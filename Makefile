NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./lib_ft

SRC =	1creating_stacks_n_check/1.1stack_make.c \
		1creating_stacks_n_check/1.2check_num.c \
		1creating_stacks_n_check/1.3finish_with_stacks.c \
		2finding_duplicates/2.1actual_finding.c \
		3finally_sort_sheeesh/3.3sorting_3_numbers.c \
		3finally_sort_sheeesh/3.1main_function.c \
		3finally_sort_sheeesh/3.2checkin.c \
		3finally_sort_sheeesh/3.4.1insert_functions.c \
		3finally_sort_sheeesh/3.4sorting_5_or_less_num.c \
		3finally_sort_sheeesh/3.5sorting_giganumbers.c \
		push/usual_push.c \
		rotate/reverse_rotate.c \
		rotate/rotate_both.c \
		rotate/usual_rotate.c \
		swap/swap_both.c \
		swap/usual_swap.c \
		push_swap.c 

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling this crap"
		make -C $(LIBFT) && make clean -C $(LIBFT)
		cc $(CFLAGS) $(OBJS) -o $(NAME) ./lib_ft/libft.a
		make clean
		@echo "All good you can rest(no)"
clean:
		@echo "Trashcan opened"
		@echo "Putting all your garbage but program"
		$(RM) $(OBJS)
		@echo "Trashcan closed"

fclean:	clean
		@echo "We decided that your program garbage too"
		@make fclean -C $(LIBFT)
		$(RM) $(NAME)
		@echo "Now trashcan really closed"

re: fclean all

.PHONY: all clean fclean re

.SILENT: