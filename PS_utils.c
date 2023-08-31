/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/08/31 11:25:41 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_stack	*alph;
	t_stack	*bert;
	char	**tab;

	if (argc != 2)
		return (0);
	bert = NULL;
	tab = ft_split(argv[1], ' ');
	alph = ps_genstack(tab);
	print_stack(alph, 'A');
	print_stack(bert, 'B');
	print_stack(alph, 'A');
	print_stack(bert, 'B');
	ps_sorting(&alph, &bert);
	return (0);
}

// if prev=null for check begin list

int	main(int argc, char **argv)
{
	argc = 2;
	argv[1] = "-100 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
	push_swap(argc, argv);
	return (0);
}
