/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MISC_PS_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:43:17 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 13:21:15 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, char type)
{
	static int	i;
	int			stop;
	int			limit;

	if (!i)
		i = 1;
	stop = 0;
	limit = 10;
	if (!stack)
		return ((void)ft_printf("\n	call #%d [%c]\n	ERROR: list empty or non-existant\n\n", i++, type));
	ft_printf("\n	call #%d [%c]\n\n", i++, type);
	while (stack && stop < limit)
	{
		stop++;
		// ft_printf("[%d]\n", stop);
		if (stack->data)
			ft_printf("data = %d\n", stack->data);
		else
			ft_printf("data = NULL\n");
		ft_printf("adrs = %p\n", stack);
		ft_printf("next = %p\n\n", stack->next);
		stack = stack->next;
	}
	if (stop == limit)
		ft_printf("	STOP: infinite loop protection (%d/%d)\n\n", stop, limit);
}
