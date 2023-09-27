/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:37:11 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 18:19:44 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->idx < i)
			return (0);
		i = stack->idx;
		stack = stack->next;
	}
	return (1);
}

int	ps_stack_len(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
