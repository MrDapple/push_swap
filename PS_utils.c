/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/26 13:54:06 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **stack)
{
	t_stack	*next_tmp;

	// if (!(*stack))
	// 	return ((void)ft_printf("	ERROR: nothing to free\n"));
	if (!(*stack))
		return ((void)NULL);
	while ((*stack))
	{
		next_tmp = (*stack)->next;
		free((*stack));
		*stack = next_tmp;
	}
	free(next_tmp);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*alph;
	t_stack	*bert;
	char	**tab;

	alph = NULL;
	if (argc == 1)
		return (0);
	bert = NULL;
	tab = ps_tabgen(argv);
	alph = ps_genstack(tab);
	ps_pre_sort(tab, ps_tablen(tab), &alph);
	// print_stack(&alph, 'A');
	// print_stack(&bert, 'B');
	ps_sorting(&alph, &bert, ps_tablen(tab));
	// print_stack(&alph, 'A');
	// print_stack(&bert, 'B');
	free_list(&alph);
	free_list(&bert);
	return (0);
}

// if prev=null for check begin list

// int	main(int argc, char **argv)
// {
// 	argc = 2;
// 	argv[1] = "5 3 1 2 4";
// 	push_swap(argc, argv);
// 	// system("leaks push_swap");
// 	return (0);
// }
