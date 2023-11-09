/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:16:00 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/09 15:45:44 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_len_argv(char **str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (i);
}

int	ps_print_error(void)
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	*alph;
	t_stack	*bert;
	int		*tab;

	if (argc == 1)
		return (EXIT_FAILURE);
	alph = NULL;
	bert = NULL;
	tab = ps_tabgen(argv);
	if (!tab)
		return (ps_print_error());
	alph = ps_genstack(tab, ps_len_argv(argv));
	if (ps_pre_sort(tab, ps_len_argv(argv), &alph) != 1)
	{
		free_list(&alph);
		free(tab);
		return (ps_print_error());
	}
	free(tab);
	ps_sort_algo(&alph, &bert);
	free_list(&alph);
	free(alph);
	free_list(&bert);
	free(bert);
	return (EXIT_SUCCESS);
}
