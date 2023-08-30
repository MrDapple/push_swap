/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_B_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:09:40 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 10:39:48 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	head_a;
	int	head_b;

	head_a = &stack_a;
	head_b = &stack_b;
	if (!stack_b)
	{
		stack_b->next = &stack_a;
		
	}
}

void	ps_swap_b(t_stack *stack)
{
	int	temp1;
	int	temp2;

	if (stack->next->data && stack->data)
	{
		temp1 = stack->data;
		stack = stack->next;
		temp2 = stack->data;
		stack->data = temp1;
		stack = stack->prev;
		stack->data = temp2;
		ft_printf("sb\n");
	}
}
