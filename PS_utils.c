/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 16:11:04 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**tab;
	int		i;

	if (argc != 2)
		return (0);
	stack_b = NULL;
	i = 0;
	tab = ft_split(argv[1], ' ');
	stack_a = ps_genstack(tab);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	return (0);
}

// if prev=null for check begin list

int	main(int argc, char **argv)
{
	argc = 2;
	argv[1] = "1 2 3 4 5";
	push_swap(argc, argv);
	return (0);
}
