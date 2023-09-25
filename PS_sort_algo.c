/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/25 18:12:25 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_5(t_stack **alph, t_stack **bert, int nbr)
{
	int	i;

	i = ps_sim_r((*alph), nbr);
	while ((*alph)->idx != nbr)
	{
		if (i == 1)
			ps_rotate(alph, 'a');
		else if (i == 2)
			ps_revrot(alph, 'a');
	}
	ps_push_b(alph, bert);
	ps_sort_4(alph, bert, 1);
	ps_push_a(alph, bert);
}

void	ps_sort_4(t_stack **alph, t_stack **bert, int nbr)
{
	int	i;

	i = ps_sim_r((*alph), nbr);
	while ((*alph)->idx != nbr)
	{
		if (i == 1)
			ps_rotate(alph, 'a');
		else if (i == 2)
			ps_revrot(alph, 'a');
	}
	ps_push_b(alph, bert);
	ps_sort_3(alph, 'a');
	ps_push_a(alph, bert);
}

void	ps_sort_3(t_stack **stack, char type)
{
	if (((*stack)->idx) - 1 == (*stack)->next->idx &&
		((*stack)->idx) + 1 == (*stack)->next->next->idx)
		ps_swap(stack, type);
	else if (((*stack)->idx) + 1 == (*stack)->next->idx &&
			((*stack)->idx) - 1 == (*stack)->next->next->idx)
		ps_revrot(stack, type);
	else if (((*stack)->idx) - 2 == (*stack)->next->idx &&
			((*stack)->idx) - 1 == (*stack)->next->next->idx)
		ps_rotate(stack, type);
	else if (((*stack)->idx) - 1 == (*stack)->next->idx &&
			((*stack)->idx) - 2 == (*stack)->next->next->idx)
	{
		ps_swap(stack, type);
		ps_revrot(stack, type);
	}
	else if (((*stack)->idx) + 2 == (*stack)->next->idx &&
			((*stack)->idx) + 1 == (*stack)->next->next->idx)
	{
		ps_swap(stack, type);
		ps_rotate(stack, type);
	}
}

void	ps_sorting(t_stack **alph, t_stack **bert, int max)
{
	int	mid;

	mid = max / 2;
	if (ps_stack_len(alph) <= 5)
	{
		if (ps_stack_len(alph) == 3)
			ps_sort_3(alph, 'a');
		else if (ps_stack_len(alph) == 4)
			ps_sort_4(alph, bert, 0);
		else if (ps_stack_len(alph) == 5)
			ps_sort_5(alph, bert, 0);
	}
	//	else
	//	ps_radix
	ft_printf("	is sorted = %d\n	MID = %d / 2 = %d\n", ps_check_index(alph),
					max, mid);
	if (alph && bert)
		return ;
}
