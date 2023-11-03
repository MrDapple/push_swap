/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:41:09 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/03 16:27:04 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_sort_10(t_stack **alph, t_stack **bert, int idx)
{
	int	size;
	int	pos;

	size = ps_stack_len(*alph);
	if (ps_is_sorted(*alph) == 1)
		return ;
	else
	{
		while ((*alph)->idx != idx)
		{
			pos = ps_find_min_index(*alph);
			if (pos >= size / 2)
				ps_revrot(alph, 'a');
			else
				ps_rotate(alph, 'a');
		}
		idx++;
		ps_push_b(alph, bert);
		if (ps_stack_len(*alph) > 3)
			ps_sort_10(alph, bert, idx);
		if (!ps_is_sorted(*alph))
			ps_sort_3(alph, 'a');
		while (*bert)
			ps_push_a(alph, bert);
	}
}

void	ps_radix(t_stack **alph, t_stack **bert)
{
	t_stack	*num;
	int		len;
	int		max_bits;
	int		i;
	int		j;

	len = ps_stack_len(*alph);
	max_bits = 0;
	while ((len - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < len)
		{
			num = *alph;
			if ((num->idx >> i) & 1)
				ps_rotate(alph, 'a');
			else
				ps_push_b(alph, bert);
		}
		while (*bert)
			ps_push_a(alph, bert);
	}
}

void	ps_sort_algo(t_stack **alph, t_stack **bert)
{
	int	size;

	size = ps_stack_len(*alph);
	if (size <= 5)
		ps_sort_5(alph, bert, 0);
	if (size < 10 && size > 5)
		ps_sort_10(alph, bert, 0);
	if (size >= 10)
		ps_radix(alph, bert);
}

int	ps_is_sorted(t_stack *list)
{
	if (list == NULL || list->next == NULL)
		return (1);
	while (list->next != NULL)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int	ps_find_min_index(t_stack *list)
{
	int	min_value;
	int	min_idx;
	int	current_idx;
	int	value;

	min_idx = 0;
	current_idx = 0;
	min_value = list->idx;
	while (list)
	{
		value = list->idx;
		if (value < min_value)
		{
			min_value = value;
			min_idx = current_idx;
		}
		list = list->next;
		current_idx++;
	}
	return (min_idx);
}
