/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:37:11 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/09 15:46:06 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ps_check_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->idx < i)
			return (NO);
		i = stack->idx;
		stack = stack->next;
	}
	return (YES);
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
		while ((i + j) < len)
		{
			if (index[i] == check[i + j])
				return (NO);
			j++;
		}
		j = 1;
		i++;
	}
	return (YES);
}

int	ps_check_str(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) <= 0)
		return (NO);
	if (ft_strlen(str) >= 10)
	{
		if (ps_overflow(str) == NO)
			return (NO);
	}
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		i++;
		if (ft_isdigit(str[i]) == 0)
			return (NO);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (NO);
		i++;
	}
	return (YES);
}

int	ps_overflow(char *str)
{
	char	*max;
	int		len;

	if (str[0] == '-')
		max = "2147483648";
	else
		max = "2147483647";
	if (str[0] == '-' || str[0] == '+')
		str++;
	len = 0;
	while (len < 10)
	{
		if (str[len] > max[len])
			return (NO);
		if (str[len] < max[len])
			break ;
		len++;
	}
	return (YES);
}
