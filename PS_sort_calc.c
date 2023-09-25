/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:37:11 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/25 17:20:19 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->idx < i)
			return (0);
		i = tmp->idx;
		tmp = tmp->next;
	}
	return (1);
}

int	ps_stack_len(t_stack **stack)
{
	int i;
	t_stack *head;

	i = 1;
	head = *stack;
	if (!*stack)
		return (0);
	if (!(*stack)->next)
		return (1);
	while (head->next)
	{
		i++;
		head = head->next;
	}
	return (i);
}