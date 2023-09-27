/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_pre_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:22:45 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/27 15:34:35 by anvoets          ###   ########.fr       */
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

int	ps_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	ps_check_index_dup(int *index)
{
	int *check;
	int	i;
	int	j;

	check = index;
	i = 0;
	j = 1;
	while (index[i])
	{
		while (check[j + i])
		{
			if (check[j + i] == index[i])
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

int	ps_pre_sort(char **tab, int size, t_stack **stack)
{
	int	*index;
	int	i;
	int	j;

	i = -1;
	j = 0;
	index = malloc(sizeof(int) * size);
	if (!index)
		return (0);
	while (tab && tab[++i])
		index[i] = ft_atoi(tab[i]);
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
	ps_index(stack, index, ps_tablen(tab));
	return (ps_check_index_dup(index));
}