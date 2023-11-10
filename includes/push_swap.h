/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:33:28 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/10 18:28:47 by anvoets          ###   ########.fr       */
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

/*					--[UTILS]--								*/

/*	main			*/
int					ps_len_argv(char **str);
int					ps_print_error(void);

/*	moves_AB		*/
void				ps_swap(t_stack **stack, char type);
void				ps_revrot(t_stack **stack, char type);
void				ps_rotate(t_stack **stack, char type);
void				ps_push_a(t_stack **alph, t_stack **bert);
void				ps_push_b(t_stack **alph, t_stack **bert);

/*	checkers		*/
int					ps_check_mult(char *str);
int					ps_check_index(t_stack *stack);
int					ps_check_index_dup(int *index, int len);
int					ps_check_str(char *str);
int					ps_overflow(char *str);

/*	pre_sort		*/
void				ps_index(t_stack **stock, int *index, int size);
void				ps_swap_int(int *a, int *b);
int					ps_pre_sort(int *tab, int size, t_stack **stack);

/*	stack_utils		*/
int					ps_stack_len(t_stack *stack);
t_stack				*ps_new_node(int content);
void				ps_stackadd_back(t_stack **lst, t_stack *new);
t_stack				*ps_genstack(int *args, int len);
void				free_stack(t_stack **stack);

/*	tabgen			*/
char				*ps_free_str_err(char *arr);
char				*ps_clean_vars(char **argv);
int					*ps_arg_tabgen(char **argv);
int					*ps_split_tabgen(char **argv);
int					*ps_tabgen(char **argv, int argc);

/*	sort_5			*/
void				ps_sort_5(t_stack **alph, t_stack **bert, int nbr);
void				ps_sort_3(t_stack **stack, char type);
int					ps_sim_r(t_stack *input, int nbr);
void				ps_rotate_sim(t_stack **stack);
void				ps_revrot_sim(t_stack **stack);

/*	sort_algo		*/
void				ps_sort_10(t_stack **alph, t_stack **bert, int idx);
void				ps_radix(t_stack **alph, t_stack **bert);
void				ps_sort_algo(t_stack **alph, t_stack **bert);
int					ps_is_sorted(t_stack *stack);
int					ps_find_min_index(t_stack *stack);

#endif