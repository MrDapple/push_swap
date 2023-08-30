/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_S_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:37:18 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/29 14:20:11 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap_s(t_stack *stack_a, t_stack *stack_b)
{
	int	temp1;
	int	temp2;

	if ((stack_a->next->data && stack_a->data) &&
		(stack_b->next->data && stack_b->data))
	{
		temp1 = stack_a->data;
		stack_a = stack_a->next;
		temp2 = stack_a->data;
		stack_a->data = temp1;
		stack_a = stack_a->prev;
		stack_a->data = temp2;
		temp1 = stack_b->data;
		stack_b = stack_b->next;
		temp2 = stack_b->data;
		stack_b->data = temp1;
		stack_b = stack_b->prev;
		stack_b->data = temp2;
		ft_printf("ss\n");
	}
}
