/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_A_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:59:38 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 10:20:46 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ps_swap_a(t_stack *stack)
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
		ft_printf("sa\n");
	}
}
