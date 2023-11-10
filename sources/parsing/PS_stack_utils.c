/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:14:08 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/10 11:53:34 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ps_stack_len(t_stack *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	if (!stack->next)
		return (1);
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ps_new_node(int content)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->idx = -1;
	ptr->data = content;
	ptr->next = NULL;
	return (ptr);
}

void	ps_stackadd_back(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = new;
}

t_stack	*ps_genstack(int *args, int len)
{
	t_stack	*stack;
	t_stack	*temp;
	int		i;

	stack = NULL;
	i = 0;
	while (i < len)
	{
		temp = ps_new_node(args[i]);
		ps_stackadd_back(&stack, temp);
		i++;
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_tmp;
	int		i;

	i = 0;
	if (!(*stack))
		return ;
	while ((*stack))
	{
		i++;
		next_tmp = (*stack)->next;
		free((*stack));
		*stack = next_tmp;
	}
	free(next_tmp);
}
