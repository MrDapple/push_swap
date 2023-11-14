/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MISC_PS_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:43:17 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/10 14:10:22 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (v);
}

void	print_t_val(t_val *v)
{
	ft_printf("Alph[First]	= %d\n", v->a_first);
	ft_printf("Alph[Second]	= %d\n", v->a_second);
	ft_printf("Alph[SecLast]	= %d\n", v->a_seclast);
	ft_printf("Alph[Last]	= %d\n\n", v->a_last);
	ft_printf("Bert[First]	= %d\n", v->b_first);
	ft_printf("Bert[Second]	= %d\n", v->b_second);
	ft_printf("Bert[SecLast]	= %d\n", v->b_seclast);
	ft_printf("Bert[Last]	= %d\n", v->b_last);
}

