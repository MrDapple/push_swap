/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_2_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:37:18 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 15:24:54 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_revrot_2(t_stack **a, t_stack **b)
{
	t_stack	*second;
	t_stack	*last;

	if ((!*a || !(*a)->next) ||
		(!*b || !(*b)->next))
		return (void)ft_printf("error(rrr)\n");
	second = *a;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*a);
	*a = last;
	second->next = NULL;
	second = *b;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*b);
	*b = last;
	second->next = NULL;
	ft_printf("rrr\n");
}

void	ps_rotate_2(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if ((!*a || !(*a)->next) ||
		(!*b || !(*b)->next))
		return ((void)ft_printf("error(rr)\n"));
	tmp = (*a);
	*a = (*a)->next;
	while ((*a)->next)
		a = &(*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = NULL;
	tmp = (*b);
	*b = (*b)->next;
	while ((*b)->next)
		b = &(*b)->next;
	(*b)->next = tmp;
	(*b)->next->next = NULL;
	ft_printf("rr\n");
}

void	ps_swap_2(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if ((*a == NULL || (*a)->next == NULL) ||
		(*b == NULL || (*b)->next == NULL))
		return ((void)ft_printf("error(ss)\n"));
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	first = *a;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	ft_printf("ss\n");
}
