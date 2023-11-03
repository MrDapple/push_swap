/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/31 17:21:34 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_sort_5(t_stack **alph, t_stack **bert, int nbr)
{
	int	i;

	i = ps_sim_r((*alph), nbr);
	if ((*alph)->idx - 1 == nbr && (*alph)->idx - 1 == (*alph)->next->idx)
		ps_swap(alph, 'a');
	else
	{
		while ((*alph)->idx != nbr)
		{
			if (i == 1)
				ps_rotate(alph, 'a');
			else if (i == 2)
				ps_revrot(alph, 'a');
		}
	}
	if (ps_check_index(*alph) == NO)
	{
		ps_push_b(alph, bert);
		if (ps_stack_len(*alph) > 3)
			ps_sort_5(alph, bert, nbr + 1);
		else
			ps_sort_3(alph, 'a');
		while (ps_stack_len(*bert) > 0)
			ps_push_a(alph, bert);
	}
}

void	ps_sort_3(t_stack **stack, char type)
{
	if (((*stack)->idx) - 1 == (*stack)->next->idx
		&& ((*stack)->idx) + 1 == (*stack)->next->next->idx)
		ps_swap(stack, type);
	else if (((*stack)->idx) + 1 == (*stack)->next->idx
		&& ((*stack)->idx) - 1 == (*stack)->next->next->idx)
		ps_revrot(stack, type);
	else if (((*stack)->idx) - 2 == (*stack)->next->idx
		&& ((*stack)->idx) - 1 == (*stack)->next->next->idx)
		ps_rotate(stack, type);
	else if (((*stack)->idx) - 1 == (*stack)->next->idx
		&& ((*stack)->idx) - 2 == (*stack)->next->next->idx)
	{
		ps_swap(stack, type);
		ps_revrot(stack, type);
	}
	else if (((*stack)->idx) + 2 == (*stack)->next->idx
		&& ((*stack)->idx) + 1 == (*stack)->next->next->idx)
	{
		ps_swap(stack, type);
		ps_rotate(stack, type);
	}
}

int	ps_sim_r(t_stack *input, int nbr)
{
	t_stack	*stack;
	int		r;
	int		rr;
	int		temp;

	stack = input;
	r = 0;
	rr = 0;
	temp = 0;
	while ((stack)->idx != nbr && ++r >= 0)
		ps_rotate_sim(&stack);
	temp = r + 1;
	while (--temp > 0)
		ps_revrot_sim(&stack);
	while ((stack)->idx != nbr && ++rr >= 0)
		ps_revrot_sim(&stack);
	temp = rr + 1;
	while (--temp > 0)
		ps_rotate_sim(&stack);
	if (r < rr)
		return (1);
	return (2);
}

void	ps_rotate_sim(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = NULL;
}

void	ps_revrot_sim(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	second = *stack;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*stack);
	*stack = last;
	second->next = NULL;
}
