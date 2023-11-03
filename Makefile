RED			=	\033[0;31m
GREEN		=	\033[0;32m
BLUE		=	\033[1;34m
YELLOW		=	\033[1;33m
DARKGREY	=	\033[1;30m
LIGHTGREY	=	\033[0;37m
BLACK		=	\033[0;30m
NC			=	\033[0m

OBJCS		:=	sources/parsing/PS_utils.o \
				sources/parsing/PS_stack_utils.o \
				sources/parsing/PS_pre_sort.o \
				sources/parsing/PS_checkers.o \
				sources/moves/PS_AB_utils.o \
				sources/moves/PS_2_utils.o \
				sources/sorting/PS_sort_5.o \
				sources/sorting/PS_sort_algo.o \
				sources/PS_simulate.o \
				sources/MISC_PS_utils.o \
				sources/PS_main.o \

LIBFT_A		:=	libft/libft.a
INCLUDES	:=	includes/push_swap.h
NAME		:=	push_swap

CFLAGS		:=	-Wall -Wextra -Werror
SFLAGS		:=	-g3 -fsanitize=address

all			:	libgen $(NAME)

$(NAME)		:	$(OBJCS) $(INCLUDES)
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

.PHONY		:	all clean fclean re libft
