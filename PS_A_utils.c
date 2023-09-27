/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_A_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:59:38 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 18:12:34 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("pa\n");
}
