/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MISC_PS_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:43:17 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 11:24:48 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stack(t_stack *stack, char type)
{
	static int	i;
	int			stop;
	int			limit;

	if (!i)
		i = 1;
	stop = 0;
	limit = 20;
	if (!stack)
		return ((void)ft_printf("\n	call #%d [%c]\n	ERROR: list empty or non-existant\n\n", i++, type));
	ft_printf("\n	call #%d [%c]\n\n", i++, type);
	while (stack && stop < limit)
	{
		stop++;
		// ft_printf("[%d]\n", stop);
		if (stack->data)
			ft_printf("data = %i\n", stack->data);
		else
			ft_printf("data = NULL\n");
		ft_printf("adrs = %p\n", stack);
		ft_printf("next = %p\n\n", stack->next);
		stack = stack->next;
	}
	if (stop == limit)
		ft_printf("	STOP: infinite loop protection (%d/%d)\n\n", stop, limit);
}
