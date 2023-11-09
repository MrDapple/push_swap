/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:16:00 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/09 17:14:14 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_len_argv(char **str, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (str[1][i])
		{
			while (str[1][i] == ' ')
				i++;
			if (ft_isprint(str[1][i]) == 1)
			{
				j++;
				while (ft_isprint(str[1][i]) == 1 && str[1][i] != ' ')
					i++;
			}
		}
		return (j);
	}
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
		return (ps_print_error());
	alph = NULL;
	bert = NULL;
	tab = ps_tabgen(argv, argc);
	if (!tab)
		return (ps_print_error());
	alph = ps_genstack(tab, ps_len_argv(argv, argc));
	if (ps_pre_sort(tab, ps_len_argv(argv, argc), &alph) != 1)
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
