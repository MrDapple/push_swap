/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PS_tabgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvoets <anvoets@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 08:59:41 by anvoets           #+#    #+#             */
/*   Updated: 2023/11/10 18:31:27 by anvoets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ps_free_str_err(char *arr)
{
	if (arr[0])
		free(arr);
	return (NULL);
}

char	*ps_clean_vars(char **argv)
{
	char	*arr;
	char	*temp;
	int		i;

	temp = "";
	arr = NULL;
	i = 1;
	while (argv[i])
	{
		arr = ft_strjoin(temp, argv[i]);
		if (*temp)
			free(temp);
		if (!arr)
			return (ps_free_str_err(arr));
		temp = arr;
		arr = ft_strjoin(temp, " ");
		free(temp);
		if (!arr)
			return (ps_free_str_err(arr));
		temp = arr;
		i++;
	}
	return (arr);
}

int	*ps_arg_tabgen(char **argv)
{
	int		*tab;
	int		i;
	char	**arr;
	char	*str;

	arr = NULL;
	tab = NULL;
	i = 1;
	str = ps_clean_vars(argv);
	if (!str)
		return (NULL);
	arr = ft_split(str, ' ');
	if (!arr)
		return (NULL);
	tab = ps_split_tabgen(arr);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	free(str);
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
