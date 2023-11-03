/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:16:00 by anvoets           #+#    #+#             */
/*   Updated: 2023/10/31 17:16:22 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *alph;
	t_stack *bert;
	int *tab;
	int len;

	if (argc == 1)
		return (EXIT_FAILURE);
	alph = NULL;
	bert = NULL;
	len = 0;
	while (argv[len + 1])
		len++;
	tab = ps_tabgen(argv);
	if (!tab)
		return (ft_printf("error1\n"));
	alph = ps_genstack(tab, len);
	if (ps_pre_sort(tab, len, &alph) != 1)
	{
		free_list(&alph);
		free_list(&bert);
		free(tab);
		// system("leaks push_swap");
		return (ft_printf("error2\n"));
	}
	free(tab);
	// print_stack(&alph, 'A');
	// print_stack(&bert, 'B');
	ps_sort_plus(&alph, &bert);
	// print_stack(&alph, 'A');
	// print_stack(&bert, 'B');
	free_list(&alph);
	free(alph);
	free_list(&bert);
	free(bert);
	// system("leaks push_swap");
	return (EXIT_SUCCESS);
}