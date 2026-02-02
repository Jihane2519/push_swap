/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbounou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 20:32:31 by jbounou           #+#    #+#             */
/*   Updated: 2026/01/27 20:43:35 by jbounou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_pos(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		min_pos;
	int		i;

	tmp = a;
	min = a->value;
	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos;

	while (stack_size(*a) > 3)
	{
		pos = find_min_pos(*a);
		if (pos == 0)
			pb(a, b, 1);
		else if (pos <= stack_size(*a) / 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
