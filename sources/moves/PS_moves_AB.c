/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_moves_AB.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:27:46 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/10 12:56:03 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_swap(t_stack **stack, char type)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
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
		return ;
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
		return ;
	tmp = (*stack);
	*stack = (*stack)->next;
	while ((*stack)->next)
		stack = &(*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->next = NULL;
	ft_printf("r%c\n", type);
}

void	ps_push_a(t_stack **alph, t_stack **bert)
{
	t_stack	*tmp;

	if (!*bert)
		return ;
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
	ft_printf("pa\n");
}

void	ps_push_b(t_stack **alph, t_stack **bert)
{
	t_stack	*tmp;

	if (!*alph)
		return ;
	if (!(*alph)->next)
	{
		(*alph)->next = (*bert);
		(*bert) = (*alph);
		*alph = NULL;
		return ((void)ft_printf("pb\n"));
	}
	tmp = (*alph)->next;
	if (!*bert)
	{
		*bert = (*alph);
		*alph = tmp;
		(*bert)->next = NULL;
		return ((void)ft_printf("pb\n"));
	}
	(*alph)->next = (*bert);
	*bert = (*alph);
	*alph = tmp;
	ft_printf("pb\n");
}
