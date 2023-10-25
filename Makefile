RED			=	\033[0;31m
GREEN		=	\033[0;32m
BLUE		=	\033[1;34m
YELLOW		=	\033[1;33m
DARKGREY	=	\033[1;30m
LIGHTGREY	=	\033[0;37m
BLACK		=	\033[0;30m
NC			=	\033[0m

SRCS		:=	PS_utils.c \
				PS_stack_utils.c \
				PS_A_utils.c \
				PS_B_utils.c \
				PS_2_utils.c \
				PS_E_utils.c \
				PS_sort_algo.c \
				PS_pre_sort.c \
				PS_sort_calc.c \
				PS_simulate.c \
				PS_sort_plus_utils.c \
				PS_sort_plus.c \
				MISC_PS_utils.c

OBJS		:= $(SRCS:.c=.o)

LIBFT_A		:=	libft/libft.a
NAME		:=	push_swap

CFLAGS		:=	-Wall -Wextra -Werror
SFLAGS		:=	-g3 -fsanitize=address

all			:	libgen $(NAME)

$(NAME)		:	$(OBJS) push_swap.h
	${CC} ${CFLAGS} $(OBJS) $(LIBFT_A) -o ${NAME}

.o			:	%.c
	$(CC) -c $(CFLAGS) -o $@ $^

libgen		:
	@make -C libft

clean		:
	@rm -f $(OBJS)
	@make clean -C libft

fclean		:	clean
	@rm -f $(NAME)
	@make fclean -C libft

re			:	fclean all

.PHONY		:	all clean fclean re libft
