/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_E_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:27:46 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 18:31:47 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack **stack, char type)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ((void)ft_printf("error(s%c)\n", type));
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("s%c\n", type);
}

void	ps_revrot(t_stack **stack, char type)
{
	t_stack	*second;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ((void)ft_printf("error(rr%c)\n", type));
	second = *stack;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*stack);
	*stack = last;
	second->next = NULL;
	ft_printf("rr%c\n", type);
}

void	ps_rotate(t_stack **stack, char type)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ((void)ft_printf("error(r%c)\n", type));
	tmp = (*stack);
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = NULL;
	ft_printf("r%c\n", type);
}
