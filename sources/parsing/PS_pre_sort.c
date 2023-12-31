/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:22:45 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/09 17:25:57 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_index(t_stack **stock, int *index, int size)
{
	int		i;
	t_stack	*stack;

	stack = *stock;
	while (stack)
	{
		i = 0;
		while (i < size && stack->idx == -1)
		{
			if (stack->data == index[i])
				stack->idx = i;
			i++;
		}
		stack = stack->next;
	}
}

void	ps_swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

int	ps_pre_sort(int *tab, int size, t_stack **stack)
{
	int	*index;
	int	i;
	int	j;

	i = -1;
	j = 0;
	index = tab;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (index[j] > index[i])
				ps_swap_int(&index[i], &index[j]);
			i++;
		}
		j++;
	}
	ps_index(stack, index, size);
	j = ps_check_index_dup(index, size);
	return (j);
}
