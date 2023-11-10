OBJCS		:=	sources/moves/PS_moves_AB.o \
				sources/parsing/PS_checkers.o \
				sources/parsing/PS_pre_sort.o \
				sources/parsing/PS_stack_utils.o \
				sources/parsing/PS_tabgen.o \
				sources/sorting/PS_sort_5.o \
				sources/sorting/PS_sort_algo.o \
				sources/PS_main.o \

LIBFT_A		:=	libft/libft.a
INCLUDES	:=	includes/push_swap.h
NAME		:=	push_swap

CFLAGS		:=	-Wall -Wextra -Werror

all			:	libgen $(INCLUDES) $(NAME)

$(NAME)		:	$(INCLUDES) $(OBJCS)
	${CC} ${CFLAGS} $(OBJCS) $(LIBFT_A) -o ${NAME}

%.o			:	%.c
	$(CC) -c $(CFLAGS) -o $@ $^

libgen		:
	@make -C libft

clean		:
	@rm -f $(OBJCS)
	@make clean -C libft

fclean		:	clean
	@rm -f $(NAME)
	@make fclean -C libft

re			:	fclean all

.PHONY		:	all clean fclean re libgen
