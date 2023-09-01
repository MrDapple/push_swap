/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/01 11:47:45 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **stack)
{
	t_stack	*next_tmp;

	if (!(*stack))
		return ((void)ft_printf("	ERROR: nothing to free\n"));
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

int	push_swap(int argc, char **argv)
{
	t_stack	*alph;
	t_stack	*bert;
	char	**tab;

	alph = NULL;
	if (argc != 2)
		return (0);
	bert = NULL;
	tab = ft_split(argv[1], ' ');
	alph = ps_genstack(tab);
	print_stack(alph, 'A');
	print_stack(bert, 'B');
	ps_pre_sort(tab, ps_tablen(tab), &alph);
	print_stack(alph, 'A');
	ps_sorting(&alph, &bert);
	free_list(&alph);
	free_list(&bert);
	free_tab(tab);
	return (0);
}

// if prev=null for check begin list

int	main(int argc, char **argv)
{
	argc = 2;
	argv[1] = "-3 -2 -1 1 2 3";
	push_swap(argc, argv);
	// system("leaks push_swap");
	return (0);
}
