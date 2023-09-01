RED			=	\033[0;31m
GREEN		=	\033[0;32m
BLUE		=	\033[1;34m
YELLOW		=	\033[1;33m
DARKGREY	=	\033[1;30m
LIGHTGREY	=	\033[0;37m
BLACK		=	\033[0;30m
NC			=	\033[0m

OBJCS		:=	PS_utils.o \
				PS_stack_utils.o \
				MISC_PS_utils.o \
				PS_A_utils.o \
				PS_B_utils.o \
				PS_2_utils.o \
				PS_E_utils.o \
				PS_sort_algo.o \
				PS_pre_sort.o \

LIBPRINT	:=	libftprintf/libftprintf.a

NAME		:=	push_swap
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:=	-g3 -fsanitize=address

all			:	libft $(NAME)

$(NAME)		:	$(OBJCS)
	@${CC} ${CFLAGS} $(OBJCS) $(LIBPRINT) -o ${NAME}

%.o			:	%.c
	@$(CC) -c $(CFLAGS) -o $@ $^

libft		:
	@make -C libftprintf

clean		:
	@rm -f *.o
	@rm -f push_swap

fclean		:	clean
	@make fclean -C libftprintf
	@rm -f $(NAME) libftprintf.a

re			:	fclean all

crun		:	all
	@echo "$(BLUE)\n-------------- RESULT --------------$(NC)"
	@./push_swap
	@echo "$(BLUE)------------------------------------\n$(NC)"
	@echo "$(YELLOW)cleaning up...$(NC)\n$(BLACK)(psst... dont forget to 'cclean' every once in a while)$(NC)\n"
	@rm -f *.o push_swap

run		:	all
	@echo "$(BLUE)\n-------------- RESULT --------------$(NC)"
	@./push_swap
	@echo "$(BLUE)------------------------------------\n$(NC)"

push		: 	fclean
	@echo "\n$(RED)= = = = = [UPDATING] = = = = =$(BLACK)\n\n"
	@git status
	@echo "$(BLUE)		- - -	ADD CHANGES....	- - - $(BLACK)\n\n"
	@git add -A
	@echo " $(GREEN)		- - -	ADD CHANGES OK!	- - - $(NC)\n\n"
	@echo "$(BLUE)		- - -	COMMITING....	- - - $(BLACK)\n\n"
	@git commit -m "automatic update"
	@echo " $(GREEN)		- - -	COMMIT OK!	- - - $(NC)\n\n"
	@echo "$(BLUE)		- - -	PUSHING....	- - - $(BLACK)\n\n"
	@git push
	@echo " $(GREEN)		 - - -	PUSH OK!	- - - $(NC)\n\n"
	@echo "\n$(GREEN)= = = = = [UPDATE OK!] = = = = =$(NC)\n\n"

.PHONY		:	all clean fclean re libft crun run push
