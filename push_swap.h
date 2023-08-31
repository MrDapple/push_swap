/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:56:39 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 11:13:16 by anvoets          ###   ########.fr       */
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

//	MISC
void				print_stack(t_stack *stack, char type);
void				print_t_val(t_val *v);

// ALGORITHM
void				ps_sorting(t_stack **alph, t_stack **bert);
t_val				*ps_set_values(t_stack **alph, t_stack **bert);

// SORT 'A'
void				ps_swap_a(t_stack **stack);
void				ps_push_a(t_stack **alph, t_stack **bert);
void				ps_rotate_a(t_stack **stack);
void				ps_revrot_a(t_stack **stack);

// SORT 'B'
void				ps_swap_b(t_stack **stack);
void				ps_push_b(t_stack **alph, t_stack **bert);
void				ps_rotate_b(t_stack **stack);
void				ps_revrot_b(t_stack **stack);

// SORT '2'
void				ps_swap_2(t_stack **alph, t_stack **bert);
void				ps_rotate_2(t_stack **alph, t_stack **bert);
void				ps_revrot_2(t_stack **alph, t_stack **bert);

// STACK utils
t_stack				*ps_genstack(char **args);
t_stack				*ps_new_stack(int content);
void				ps_stackadd_back(t_stack **lst, t_stack *new);

#endif