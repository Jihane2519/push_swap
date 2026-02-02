/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:20:29 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/27 17:42:47 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	clean(char **tab, t_stack **a)
{
	free_split(tab);
	free_stack(a);
	error_exit();
}

static void	parse_args_helper(char **tab, t_stack **a)
{
	int		j;
	long	nb;

	j = 0;
	while (tab[j])
	{
		if (!is_valid_number(tab[j]))
			clean(tab, a);
		nb = ft_atol(tab[j]);
		if (nb < INT_MIN || nb > INT_MAX)
			clean(tab, a);
		if (has_duplicate(*a, (int)nb))
			clean(tab, a);
		stack_add_back(a, (int)nb);
		j++;
	}
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**tab;

	i = 1;
	while (i < argc)
	{
		tab = ft_split(argv[i], ' ');
		if (!tab)
			clean(tab, a);
		parse_args_helper(tab, a);
		free_split(tab);
		i++;
	}
}
