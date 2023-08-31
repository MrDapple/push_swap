/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_A_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:59:38 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 10:49:30 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_revrot_a(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return (void)ft_printf("error(rra)\n");
	second = *stack;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*stack);
	*stack = last;
	second->next = NULL;
	ft_printf("rra\n");
}

void	ps_rotate_a(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return (void)ft_printf("error(ra)\n");
	tmp = (*stack);
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = NULL;
	ft_printf("ra\n");
}

void	ps_push_a(t_stack **alph, t_stack **bert)
{
	t_stack	*tmp;

	if (!*bert)
		return ((void)ft_printf("error(pa)\n"));
	if (!(*bert)->next)
	{
		(*bert)->next = (*alph);
		(*alph) = (*bert);
		*bert = NULL;
		return ((void)ft_printf("pa\n"));
	}
	tmp = (*bert)->next;
	if (!*alph)
	{
		*alph = (*bert);
		*bert = tmp;
		(*alph)->next = NULL;
		return ((void)ft_printf("pa\n"));
	}
	(*bert)->next = (*alph);
	*alph = (*bert);
	*bert = tmp;
	ft_printf("pb\n");
}

void	ps_swap_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ((void)ft_printf("error(sa)\n"));
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	ft_printf("sa\n");
}
