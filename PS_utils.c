/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/30 10:22:37 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	// t_stack	*stack_b = NULL;
	char	**tab;
	int i;

	i = 0;
	tab = NULL;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
		return (0);
	stack_a = ps_genstack(tab);
	print_stack(stack_a);
	ps_swap_a(stack_a);
	print_stack(stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	argc = 2;
	argv[1] = ARG;
	push_swap(argc, argv);
	return (0);
}
