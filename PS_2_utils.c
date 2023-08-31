/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_2_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:37:18 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 10:51:48 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_revrot_2(t_stack **alph, t_stack **bert)
{
	t_stack	*second;
	t_stack	*last;

	if ((!*alph || !(*alph)->next) ||
		(!*bert || !(*bert)->next))
		return (void)ft_printf("error(rrr)\n");
	second = *alph;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*alph);
	*alph = last;
	second->next = NULL;
	second = *bert;
	while (second->next->next)
		second = second->next;
	last = second->next;
	last->next = (*bert);
	*bert = last;
	second->next = NULL;
	ft_printf("rrr\n");
}

void	ps_rotate_2(t_stack **alph, t_stack **bert)
{
	t_stack	*tmp;

	if ((!*alph || !(*alph)->next) ||
		(!*bert || !(*bert)->next))
		return ((void)ft_printf("error(rr)\n"));
	tmp = (*alph);
	*alph = (*alph)->next;
	while ((*alph)->next)
		alph = &(*alph)->next;
	(*alph)->next = tmp;
	(*alph)->next->next = NULL;
	tmp = (*bert);
	*bert = (*bert)->next;
	while ((*bert)->next)
		bert = &(*bert)->next;
	(*bert)->next = tmp;
	(*bert)->next->next = NULL;
	ft_printf("rr\n");
}

void	ps_swap_2(t_stack **alph, t_stack **bert)
{
	t_stack	*first;
	t_stack	*second;

	if ((*alph == NULL || (*alph)->next == NULL) ||
		(*bert == NULL || (*bert)->next == NULL))
		return ((void)ft_printf("error(ss)\n"));
	first = *alph;
	second = (*alph)->next;
	first->next = second->next;
	second->next = first;
	*alph = second;
	first = *alph;
	second = (*bert)->next;
	first->next = second->next;
	second->next = first;
	*bert = second;
	ft_printf("ss\n");
}
