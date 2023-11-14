/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:13:46 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/03 13:06:57 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ps_sort_10(t_stack **alph, t_stack **bert)
{
	int	mvs;

	mvs = 0;
	while (ps_stack_len(*alph) > 5)
	{
		if ((*alph)->idx > 4)
		{
			ps_push_b(alph, bert);
			mvs++;
		}
		else
			ps_rotate(alph, 'a');
		print_stack(alph, 'A');
		print_stack(bert, 'B');
		usleep(1000000);
	}
		print_stack(alph, 'T');
	ps_sort_5(alph, bert, 0);
	while (mvs-- > 0)
	{
		print_stack(alph, 'R');
		ps_push_a(alph, bert);
	}
	return (0);
}

int	ps_calcost_10(t_stack *alph, t_stack *bert);