/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_simulate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:38:51 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/25 17:21:37 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sim_r(t_stack *input, int nbr)
{
	t_stack *stack;
	int		r;
	int		rr;
	int	temp;

	stack = input;
	r = 0;
	rr = 0;
	temp = 0;
	while ((stack)->idx != nbr)
	{
		ps_rotate_sim(&stack);
		r++;
	}
	temp = r + 1;
	while (--temp > 0)
		ps_revrot_sim(&stack);
	while ((stack)->idx != nbr)
	{
		ps_revrot_sim(&stack);
		rr++;
	}
	temp = rr + 1;
	while (--temp > 0)
		ps_rotate_sim(&stack);
	if (r < rr)
		return (1);
	return 2;
}

void	ps_rotate_sim(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ((void)NULL);
	tmp = (*stack);
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = NULL;
}

void ps_revrot_sim(t_stack **stack)
{
	t_stack *second;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return ((void)NULL);
	second = *stack;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*stack);
	*stack = last;
	second->next = NULL;
}