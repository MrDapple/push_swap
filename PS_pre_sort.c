/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:22:45 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/24 14:00:00 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ps_tablen(int *tab)
{
	int	i;

	i = 1;
	while (tab[i])
		i++;
	return (i);
}

int	ps_check_index_dup(int *index, int len)
{
	int	*check;
	int	i;
	int	j;

	check = index;
	i = 0;
	j = 1;
	while (i < len)
	{
		while ((j + i) < len)
		{
			if (check[j + i] == index[i])
			{
				return (0);
			}
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

int	ps_pre_sort(int *tab, int size, t_stack **stack)
{
	int	*index;
	int	i;
	int	j;

	i = -1;
	j = 0;
	// index = malloc (sizeof(int) * size);
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
	// free(index);
	return (j);
}
