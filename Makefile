OBJCS		:=	PS_utils.o \
				PS_stack_utils.o \
				MISC_PS_utils.o \
				PS_A_utils.o \
				PS_B_utils.o \
				PS_2_utils.o \
				PS_sort_algo.o \

HEADER		:=	push_swap.h \

LIBPRINT	:=	libftprintf/libftprintf.a

NAME		:=	push_swap
CFLAGS		?=	-Wall -Wextra -Werror
SFLAGS		:=	-fsanitize=address

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

run			:	all
	@echo "\n-------------- RESULT --------------"
	@./push_swap
	@echo "------------------------------------\n"
	@# @echo "cleaning up...\n"
	@# @rm -f *.o push_swap

push		: fclean
	@echo "\n	UPDATING.... \n\n"
	git status
	@echo "\n	ADDING CHANGES.... \n\n"
	git add -A
	git status
	@echo "\n	COMMITING.... \n\n"
	git commit -m "auto-update"
	@echo "\n	PUSHING.... \n\n"
	git push

.PHONY		:	all clean fclean re run libft
