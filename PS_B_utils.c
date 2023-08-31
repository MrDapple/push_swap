/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_B_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:09:40 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 12:30:03 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push_b(t_stack **alph, t_stack **bert)
{
	t_stack	*tmp;

	if (!*alph)
		return ((void)ft_printf("error(pb)\n"));
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
