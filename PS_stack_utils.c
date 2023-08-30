 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:14:08 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/28 15:40:38 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_new_stack(int content)
{
	t_stack *ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
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

t_stack	*ps_genstack(char **args)
{
	t_stack	*stack = NULL;
	t_stack	*temp;
	int		i;

	i = 0;
	while (args[i])
	{
		temp = ps_new_stack(ft_atoi(args[i]));
		ps_stackadd_back(&stack, temp);
		i++;
	}
	return (stack);
}
