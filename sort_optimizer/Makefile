ACJK JCKB XKS9 JGN9 4HZZ M16P RP5V H215
NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	\
			src/push_swap.c\
			src/op/instructions_p.c\
			src/op/instruction_rr.c\
			src/op/instructions_s.c\
			src/op/instruction_r.c\
			src/utils/free_error.c\
			src/utils/init_b.c\
			src/utils/minimumum.c\
			src/sort/opti_sort.c\
			src/sort/quick_sort.c\
			src/sort/small_sort.c\
			src/moves/best_m.c\
			src/moves/do_m.c\
			src/checks/check_dub.c\
			src/checks/check_num.c\
			src/checks/check_sort.c\
			src/arguments/parser.c\

DEPS = $(wildcard inc/*.h)

LIBFT_DIR = all_libft/
LIBFT_LIB = all_libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT_LIB) $(SRCS) $(DEPS) 
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
