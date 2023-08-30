/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_B_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:09:40 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 15:25:55 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_revrot_b(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (void)ft_printf("error(rrb)\n");
	second = *stack;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*stack);
	*stack = last;
	second->next = NULL;
	ft_printf("rrb\n");
}

void	ps_rotate_b(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (void)ft_printf("error(rb)\n");
	tmp = (*stack);
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = NULL;
	ft_printf("rb\n");
}

void	ps_push_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ((void)ft_printf("error(pb)\n"));
	if (!(*a)->next)
	{
		(*a)->next = (*b);
		(*b) = (*a);
		*a = NULL;
		return ((void)ft_printf("pb\n"));
	}
	tmp = (*a)->next;
	if (!*b)
	{
		*b = (*a);
		*a = tmp;
		(*b)->next = NULL;
		return ((void)ft_printf("pb\n"));
	}
	(*a)->next = (*b);
	*b = (*a);
	*a = tmp;
	ft_printf("pb\n");
}

void	ps_swap_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ((void)ft_printf("error(sb)\n"));
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sa\n");
}
