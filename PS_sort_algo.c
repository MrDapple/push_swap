/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 12:20:21 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val	*ps_set_values(t_stack **alph, t_stack **bert)
{
	t_val	*v;

	v = malloc(sizeof(t_val));
	if ((*alph) && (*alph)->next)
	{
		v->a_first = (*alph)->data;
		v->a_second = (*alph)->next->data;
		while ((*alph)->next->next)
			alph = &(*alph)->next;
		v->a_seclast = (*alph)->data;
		v->a_last = (*alph)->next->data;
	}
	if ((*bert) && (*bert)->next)
	{
		v->b_first = (*bert)->data;
		v->b_second = (*bert)->next->data;
		while ((*bert)->next->next)
			bert = &(*bert)->next;
		v->b_seclast = (*bert)->data;
		v->b_last = (*bert)->next->data;
	}
	print_t_val(v);
	return (v);
}

void	ps_sorting(t_stack **alph, t_stack **bert)
{
	t_val	*v;

	v = ps_set_values(&*alph, &*bert);
	
}