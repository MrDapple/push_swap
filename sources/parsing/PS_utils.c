/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/09 17:41:24 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	*ps_arg_tabgen(char **argv)
{
	int	*tab;
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ps_check_str(argv[i]) == NO)
			return (NULL);
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

int	*ps_split_tabgen(char **argv)
{
	int	*tab;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ps_check_str(argv[i]) == NO)
			return (NULL);
		i++;
	}
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

int	*ps_tabgen(char **argv, int argc)
{
	char	**arr;
	int		*tab;
	int		i;

	i = 0;
	arr = NULL;
	tab = NULL;
	if (argc > 2)
		return (ps_arg_tabgen(argv));
	arr = ft_split(argv[1], ' ');
	if (!arr)
		return (NULL);
	if (!arr[i])
	{
		free(arr);
		return (NULL);
	}
	tab = ps_split_tabgen(arr);
	while (arr[i])
		free(arr[i++]);
	free(arr);
	if (!tab)
		return (NULL);
	return (tab);
}

void	free_list(t_stack **stack)
{
	t_stack	*next_tmp;
	int		i;

	i = 0;
	if (!(*stack))
		return ;
	while ((*stack))
	{
		i++;
		next_tmp = (*stack)->next;
		free((*stack));
		*stack = next_tmp;
	}
	free(next_tmp);
}
