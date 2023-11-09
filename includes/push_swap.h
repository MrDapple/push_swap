/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:56:39 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/07 12:49:26 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				idx;
	struct s_stack	*next;
}					t_stack;

enum				e_move
{
	ROTATE = 1,
	REVROT = 2,
	REVREV = 3
}					e_move;

typedef struct s_values
{
	int				a_first;
	int				a_second;
	int				a_seclast;
	int				a_last;
	int				b_first;
	int				b_second;
	int				b_seclast;
	int				b_last;
}					t_val;

//			--[UTILS]--

//	SORT ALGO
void				ps_sort_algo(t_stack **alph, t_stack **bert);
void				ps_sort_10(t_stack **alph, t_stack **bert, int index);
void				ps_radix(t_stack **alph, t_stack **bert);

// SORT ALGO UTILS
int					ps_is_sorted(t_stack *stack);
int					ps_find_min_index(t_stack *stack);

//	COST CALC
int					ps_r_cost(int nbr, t_stack *stack);
int					ps_rr_cost(int nbr, t_stack *stack);
int					ps_rrr_cost(int nbr, t_stack *alph, t_stack *bert);

//	SORT 3
void				ps_sorting(t_stack **alph, t_stack **bert);
void				ps_sort_3(t_stack **stack, char type);
void				ps_sort_5(t_stack **alph, t_stack **bert, int nbr);

//	ALGO CALC
int					ps_check_index(t_stack *stack);
int					ps_stack_len(t_stack *stack);

//	COMMANDS 'E'
void				ps_swap(t_stack **stack, char type);
void				ps_rotate(t_stack **stack, char type);
void				ps_revrot(t_stack **stack, char type);

//	COMMANDS 'A'
void				ps_push_a(t_stack **alph, t_stack **bert);

//	COMMANDS 'B'
void				ps_push_b(t_stack **alph, t_stack **bert);

//	COMMANDS '2'
void				ps_swap_2(t_stack **alph, t_stack **bert);
void				ps_rotate_2(t_stack **alph, t_stack **bert);
void				ps_revrot_2(t_stack **alph, t_stack **bert);

//	SIMULATORS
int					ps_sim_r(t_stack *input, int nbr);
void				ps_rotate_sim(t_stack **stack);
void				ps_revrot_sim(t_stack **stack);

//	ASSORTED UTILS
int					ps_pre_sort(int *tab, int size, t_stack **stack);
int					ps_tablen(int *tab);
void				ps_swap_int(int *a, int *b);
int					*ps_tabgen(char **argv);
int					ps_check_index_dup(int *index, int len);
int					ps_check_str(char *str);
int					ps_overflow(char *str);

//	STACK UTILS
t_stack				*ps_genstack(int *args, int len);
t_stack				*ps_new_node(int content);
void				ps_stackadd_back(t_stack **lst, t_stack *new);
void				free_stack(t_stack **stack);

//	FREE
void				free_list(t_stack **stack);

#endif