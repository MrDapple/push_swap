/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:41:09 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/31 17:05:01 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_plus(t_stack **alph, t_stack **bert)
{
	int	len_a;
	// int	len_b;
	int	min;

	min = 0;
	len_a = ps_stack_len(*alph);
	while (ps_check_index(*alph) == NO)
	{
		if (len_a <= 5)
		{
			ps_sort_5(alph, bert, min);
			while (min-- != 0)
			{
				ps_push_a(alph, bert);
			}
		}
		else if (len_a >= 5 && len_a <= 10)
		{
			while ((*alph)->idx >= 5)
				ps_push_b(alph, bert);
		}
		else
			min += ps_act(ps_calccost(min, *alph, *bert), min, 10, alph, bert);
		len_a = ps_stack_len(*alph);
	}
}

int	ps_act(int code, int nbr, int size, t_stack **alph, t_stack **bert)
{
	int	ps;

	ps = 1;
	while ((*alph)->idx != nbr && size)
	{
		if (code == ROTATE)
			ps_rotate(alph, 'a');
		else if (code == REVROT)
			ps_revrot(alph, 'a');
		else if (code == REVREV)
			ps_revrot_2(alph, bert);
		usleep(100000);
	}
	if (code >= 1 && code <= 3)
		ps_push_b(alph, bert);
	return (ps);
}

int	ps_calccost(int nbr, t_stack *alph, t_stack *bert)
{
	if (ps_r_cost(nbr, alph) < ps_rr_cost(nbr, alph) && bert)
	{
		if (ps_rrr_cost(nbr, alph, bert) < ps_r_cost(nbr, alph))
			return (REVREV);
		return (ROTATE);
	}
	return (REVROT);
}
