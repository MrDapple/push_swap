/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_algo_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:53 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/03 16:47:20 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ps_rot_direct(t_stack **stack, int len, char type)
{
	if ((*stack)->idx > (len / 2))
		ps_rotate(stack, type);
	else
		ps_swap(stack, type);
}

// int	ps_rot_act(t_stack *stack, int len, int code)
// {
// 	int	i;

// 	i = 0;
// 	while (i )
// }

// int	ps_rot_calc(t_stack *stack, int len)
// {

// }