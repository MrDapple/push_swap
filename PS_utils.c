/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/09/28 12:29:23 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **stack)
{
	t_stack	*next_tmp;

	if (!(*stack))
		return ;
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
	if (ps_pre_sort(tab, ps_tablen(tab), &alph) != 1)
	{
		free_list(&alph);
		free_list(&bert);
		return (ft_printf("error\n"));
	}
	// print_stack(&alph, 'A');
	// print_stack(&bert, 'B');
	ps_sorting(&alph, &bert);
	// print_stack(&alph, 'A');
	// print_stack(&bert, 'B');
	free_list(&alph);
	free_list(&bert);
	return (0);
}

// if prev=null for check begin list
