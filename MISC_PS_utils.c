/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MISC_PS_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:43:17 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/29 13:50:42 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	static int	i;

	if (!i)
		i = 1;
	ft_printf("\n	-=[%d]=-\n\n", i++);
	while (stack)
	{
		ft_printf("data=[%d]\nprev=[%p]\nnext=[%p]\n\n", stack->data, stack->prev, stack->next);
		stack = stack->next;
	}
}
