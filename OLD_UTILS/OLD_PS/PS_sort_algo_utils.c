/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_sort_algo_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:04:23 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/09 17:21:53 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ps_push_calc(t_stack **alph, t_stack **bert)
{
	if (alph && bert)
		return (1);
	return (0);
}

int	ps_r_cost(int nbr, t_stack *stack)
{
	t_stack	*tmp;
	int		cst;
	int		i;

	tmp = stack;
	cst = 0;
	i = 0;
	while ((tmp)->idx != nbr && cst >= 0)
	{
		ps_rotate_sim(&tmp);
		cst++;
	}
	i = cst;
	while (i > 0)
	{
		ps_revrot_sim(&tmp);
		i--;
	}
	return (cst);
}

int	ps_rr_cost(int nbr, t_stack *stack)
{
	t_stack	*tmp;
	int		cst;
	int		i;

	tmp = stack;
	cst = 0;
	i = 0;
	while ((tmp)->idx != nbr && cst >= 0)
	{
		ps_revrot_sim(&tmp);
		cst++;
	}
	i = cst;
	while (i > 0)
	{
		ps_rotate_sim(&tmp);
		i--;
	}
	return (cst);
}

