/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:41:09 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/24 14:21:29 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_plus(t_stack **alph, t_stack **bert)
{
	int	len_a;
	// int	len_b;
	int	min;

	min = 0;
	len_a = ps_stack_len(*alph);
	if (ps_stack_len(*alph) <= 5)
		ps_sorting(alph, bert);
	while (ps_check_index(*alph) == NO)
	{
		if (ps_stack_len(*alph) <= 5)
		{
			ps_sort_5(alph, bert, min);
			while (ps_stack_len(*alph) < len_a)
			{
				ft_printf("	[%d]\n", ps_stack_len(*alph));
				ps_push_a(alph, bert);
			}
		}
		else
		{
			ps_push_b(alph, bert);
			// ps_act(ps_calccost(min, alph, bert), min, alph, bert);
			/*min = */
			min++;
		}
	}
}

int	ps_act(int code, int nbr, t_stack **alph, t_stack **bert)
{
		ps_push_b(alph, bert);
	if (code && nbr && alph && bert)
	{
		return (1);
	}
	return (1);
}

int	ps_calccost(int nbr, t_stack **alph, t_stack **bert)
{
	if (nbr && alph && bert)
		return (0);
	return (0);
	// ps_sim_r
}
