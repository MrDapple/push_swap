/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:14:08 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/25 14:28:15 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ps_tabgen(char **argv)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (argv[i + 1])
	{
		while (argv[i + 1][j + 1])
		{
			if (ft_isdigit(argv[i + 1][++j]) == 0)
				return (NULL);
		}
		i++;
		j = -1;
	}
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (NULL);
	i = 0;
	while (argv[i + 1])
	{
		tab[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (tab);
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
