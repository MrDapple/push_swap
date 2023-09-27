/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:56:39 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/26 11:17:02 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"
# include "libftprintf/get_next_line.h"
# include "libftprintf/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	int				idx;
	struct s_stack	*next;
}					t_stack;

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

//	MISC (aka 'to delete after')
void				print_stack(t_stack **stack, char type);
void				print_t_val(t_val *v);
t_val				*ps_set_values(t_stack **alph, t_stack **bert);

// ALGORITHM
void				ps_sorting(t_stack **alph, t_stack **bert, int max);
void				ps_sort_3(t_stack **stack, char type);
void				ps_sort_4(t_stack **alph, t_stack **bert, int nbr);

// ALGO CALC
int					ps_check_index(t_stack *stack);
int					ps_stack_len(t_stack *stack);

// COMMANDS 'E'
void				ps_swap(t_stack **stack, char type);
void				ps_rotate(t_stack **stack, char type);
void				ps_revrot(t_stack **stack, char type);

// COMMANDS 'A'
void				ps_push_a(t_stack **alph, t_stack **bert);

// COMMANDS 'B'
void				ps_push_b(t_stack **alph, t_stack **bert);

// COMMANDS '2'
void				ps_swap_2(t_stack **alph, t_stack **bert);
void				ps_rotate_2(t_stack **alph, t_stack **bert);
void				ps_revrot_2(t_stack **alph, t_stack **bert);

// SIMULATORS
int					ps_sim_r(t_stack *input, int nbr);
void				ps_rotate_sim(t_stack **stack);
void				ps_revrot_sim(t_stack **stack);

// ASSORTED UTILS
int					ps_pre_sort(char **tab, int size, t_stack **stack);
int					ps_tablen(char **tab);
void				ps_swap_int(int *a, int *b);
void				ps_index(t_stack **stock, int *index, int size);
char 				**ps_tabgen(char **argv);

// STACK UTILS
t_stack				*ps_genstack(char **args);
t_stack				*ps_new_stack(int content);
void				ps_stackadd_back(t_stack **lst, t_stack *new);
void				free_list(t_stack **stack);

// FREE
void				free_tab(char **tab);
void				free_list(t_stack **stack);

#endif