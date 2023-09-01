/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:33:44 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/01 15:02:02 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_check_index(t_stack **stack)
{
	t_stack *tmp;
	int	i;

	tmp = *stack;
	i = 1;
	while (tmp)
	{
		if (tmp->idx < i)
			return (0);
		i = tmp->idx;
		tmp = tmp->next;
	}
	return (1);
}

// int	ps_pivot(t_stack **stack)
// {
// 	int i;
	
// 	i = 0;

// 	return (i);
// }

void	ps_sorting(t_stack **alph_x, t_stack **bert_x, int max)
{
	t_stack *alph;
	t_stack	*bert;
	int	mid;
	int i;

	alph = *alph_x;
	bert = *bert_x;
	mid = max / 2;
	i = 0;
	while (ps_check_index(&alph) == 0 && i <= 20)
	{
		ft_printf("	A [%d|%d] M	= ", alph->idx, mid);
		if (alph->idx < mid)
			ps_push_b(&alph, &bert);
		if (alph->idx >= mid)
			ps_rotate(&alph, 'a');
		// else
		// 	mid = ps_pivot(&alph);
		i++;
	}

	ft_printf("	is sorted = %d\n	MID = %d / 2 = %d\n", ps_check_index(&alph), max, mid);
	if (alph && bert)
		return ;
}
